#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100

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

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    Food* foodPtr = new Food(); 
    playerPtr = new Player(myGM, foodPtr);
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    playerPtr->updatePlayerDir();
    playerPtr->movePlayer();
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

    objPos playerPos = playerPtr->getPlayerPos();
    int playerX = playerPos.getObjPos().pos->x;
    int playerY = playerPos.getObjPos().pos->y;
    char playerSymbol = playerPos.getSymbol();
    
    objPos randomcharone(5, 5, 'A');
    objPos randomchartwo(2, 7, 'C');
    
    for (i = 0; i < boardHeight; i++) {
        MacUILib_printf("#");
        for (j = 0; j < boardWidth; j++) {
            if (i == playerY && j == playerX) {
                MacUILib_printf("%c", playerSymbol);
            } else if (i == randomcharone.getObjPos().pos->y && j == randomcharone.getObjPos().pos->x) {
                MacUILib_printf("%c", randomcharone.getSymbol());
            } else if (i == randomchartwo.getObjPos().pos->y && j == randomchartwo.getObjPos().pos->x) {
                MacUILib_printf("%c", randomchartwo.getSymbol());
            } else {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("#\n");
    }

    for (j = 0; j < boardWidth + 2; j++) {
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if (myGM->getLoseFlagStatus()) // Player lost the game
    {
        cout << "Game Over! You lost. Better luck next time!\n";
    }
    else if (myGM->getExitFlagStatus()) // Player quit the game
    {
        cout << "You quit the game. Thank you for playing!\n";
    }
    else // If neither losing nor quitting, assume victory
    {
        cout << "Congratulations! You won the game!\n";
    }

    // delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}