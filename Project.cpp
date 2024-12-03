#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

//Global poiunters
Food* foodPtr = NULL; 
GameMechs *myGM;


//Function prototypes from previous files 
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

Player* playerPtr = nullptr; 

//Main function (looping for contionious updating) 
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

//Initializing the game 
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
//Captures the player's input and updates direction based on that 
void GetInput(void)
{
   playerPtr->updatePlayerDir();
}

//Game logic (moving the player, checking for self collision)
void RunLogic(void)
{
    playerPtr->movePlayer(); 
    if(playerPtr->checkSelfCollision()){
        myGM->setLoseFlag();
    }
}

//Drawing the entire board and elements within it  
void DrawScreen(void)
{
    MacUILib_clearScreen();    
    int i, j;
    int boardWidth = 20;
    int boardHeight = 10;
    
    //Drawing top border
    for (j = 0; j < boardWidth + 2; j++) {
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");
    objPos foodPos = foodPtr->getFoodPos(); //Getting food position
    objPosArrayList* playerPosList = playerPtr->getPlayerPosList(); //Getting snakes position list 

    //Drawing the game board 
    for (int i = 0; i < boardHeight; i++) {
        MacUILib_printf("#");
        for (int j = 0; j < boardWidth; j++) {
            bool check = false;
            //Checking if the current position matches any part of the snake 
            for (int k = 0; k < playerPosList->getSize(); k++) {
                objPos currentPart = playerPosList->getElement(k);
                if (i == currentPart.getObjPos().pos->y && j == currentPart.getObjPos().pos->x) {
                    MacUILib_printf("%c", currentPart.getSymbol()); //Drawing the snake segments in a loop 
                    check = true;
                    break;
                }
            }
            //Checking thew possibilioty if the current position matches the food 
            if (!check && i == foodPos.getObjPos().pos->y && j == foodPos.getObjPos().pos->x) {
                MacUILib_printf("%c", foodPos.getSymbol()); //Draws the food 
                check = true;
            }
            //Empty space if no match 
            if (!check) {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("#\n"); //Right border
    }

    // Draw bottom border
    for (int j = 0; j < boardWidth + 2; j++) {
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");

    // Display score
    MacUILib_printf("Score: %d\n", playerPtr->getScore());
}
//Loop delay between updates 
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

//Cleans up all resources and endgame results (including ending the game) 
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