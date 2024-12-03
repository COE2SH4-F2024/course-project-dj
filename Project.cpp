#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000
Food* foodPtr = NULL; 
GameMechs *myGM;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

Player* playerPtr = nullptr; 

int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
    return 0; 

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    foodPtr = new Food(); 
    playerPtr = new Player(myGM, foodPtr);
    objPosArrayList playerPosList; 
    playerPtr->getPlayerPos(); 
    foodPtr->generateFood(playerPosList); 
}

void GetInput(void)
{
   playerPtr->updatePlayerDir();
}

void RunLogic(void)
{
    playerPtr->movePlayer(); 
    // playerPtr->updatePlayerDir();
    // playerPtr->movePlayer();
    // objPos playerHead = playerPtr->getPlayerPos(); 
    // objPos foodPos = foodPtr->getFoodPos(); 
    // if(playerHead.isPosEqual(&foodPos))
    // {
    //     objPosArrayList playerPosList; 
    //     playerPtr->getPlayerPos(); 
    //     foodPtr->generateFood(playerPosList); 
    // }
    if(playerPtr->checkSelfCollision()){
        myGM->setLoseFlag();
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    int i, j;
    int boardWidth = 20;
    int boardHeight = 10;
    
    for (j = 0; j < boardWidth + 2; j++) {
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");
    objPos foodPos = foodPtr->getFoodPos();
    objPosArrayList* playerPosList = playerPtr->getPlayerPosList();

    for (int i = 0; i < boardHeight; i++) {
        MacUILib_printf("#");
        for (int j = 0; j < boardWidth; j++) {
            bool check = false;
            for (int k = 0; k < playerPosList->getSize(); k++) {
                objPos currentPart = playerPosList->getElement(k);
                if (i == currentPart.getObjPos().pos->y && j == currentPart.getObjPos().pos->x) {
                    MacUILib_printf("%c", currentPart.getSymbol());
                    check = true;
                    break;
                }
            }

            if (!check && i == foodPos.getObjPos().pos->y && j == foodPos.getObjPos().pos->x) {
                MacUILib_printf("%c", foodPos.getSymbol());
                check = true;
            }

            if (!check) {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("#\n");
    }

    // Draw bottom border
    for (int j = 0; j < boardWidth + 2; j++) {
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");

    // Display score
    MacUILib_printf("Score: %d\n", playerPtr->getScore());

    // objPos playerPos = playerPtr->getPlayerPos();
    // int playerX = playerPos.getObjPos().pos->x;
    // int playerY = playerPos.getObjPos().pos->y;
    // char playerSymbol = playerPos.getSymbol();
    
    // // objPos randomcharone(5, 5, 'A');
    // // objPos randomchartwo(2, 7, 'C');
    // objPos foodPos = foodPtr->getFoodPos(); 
    // int foodX = foodPos.getObjPos().pos->x; 
    // int foodY = foodPos.getObjPos().pos->y; 
    // char foodSymbol = foodPos.getSymbol(); 
    // objPosArrayList* playerPosList = playerPtr->getPlayerPosList(); 

    // for (i = 0; i < boardHeight; i++) {
    //     MacUILib_printf("#");
    //     for (j = 0; j < boardWidth; j++) {
    //         if (i == playerY && j == playerX) {
    //             MacUILib_printf("%c", playerSymbol);
    //         } else if (i == foodY && j == foodX) {
    //             MacUILib_printf("%c", foodSymbol);
    //         // } else if (i == randomchartwo.getObjPos().pos->y && j == randomchartwo.getObjPos().pos->x) {
    //         //     MacUILib_printf("%c", randomchartwo.getSymbol());
    //         } else {
    //             MacUILib_printf(" ");
    //         }
    //     }
    //     MacUILib_printf("#\n");
    // }

    // for (j = 0; j < boardWidth + 2; j++) {
    //     MacUILib_printf("#");
    // }
    // MacUILib_printf("\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if (myGM->getLoseFlagStatus()) 
    {
        MacUILib_printf( "You lost\n");
    }
    else if (myGM->getExitFlagStatus()) 
    {
        MacUILib_printf("You quit\n");
    }
    else 
    {
        MacUILib_printf("You won\n");
    }

    // delete myPlayer;
    delete myGM;
    delete foodPtr;
    delete playerPtr; 

    MacUILib_uninit();
}