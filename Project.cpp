#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100

GameMechs *myGM;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



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
    myPlayer = new Player(myGM);
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
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
