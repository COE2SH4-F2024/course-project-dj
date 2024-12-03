#include "GameMechs.h"
#include "MacUILib.h"
//Default constructor
GameMechs::GameMechs()
{
    //cout << "Default constructor called\n";
    //Initializing variables 
    input = 0;
    exitFlag = 0;
    loseFlag = 0;     
    score = 0;
    boardSizeX = 20;
    boardSizeY = 10;

}

//Parameterized constructor
GameMechs::GameMechs(int boardX, int boardY)
{
    //Initialize Variables
    input = 0;
    exitFlag = 0;
    loseFlag = 0;     
    score = 0;

    //Make sure the board dimensions are at least 2 by 2 
    if(boardX < 2)
    {
        boardX = 20;
    }

    if(boardY < 2)
    {
        boardY = 10;
    }
    //Setting the board size
    boardSizeX = boardX;
    boardSizeY = boardY;
}

//Destructor 
GameMechs::~GameMechs() 
{
    // nothing on the heap
}


//Returns the status of the exit flag 
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

//Returns the status of the lose flag 
bool GameMechs::getLoseFlagStatus() const
{ 
    return loseFlag;
}
    
//Returns the input from the user 
char GameMechs::getInput() // const // we dont want const because then we cant edit input
{
    //If the character is within the desired values, it recieves it as an input 
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}

//Returns the game score 
int GameMechs::getScore() const
{
    return score;
}

//Incrementing the game score 
void GameMechs::incrementScore()
{
    score++;
}


//Recieving the width of the board
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}


//Recieving the height of the board 
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

//Setting an exit flag 
void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

//Setting a lose flag 
void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

//Setting the input character 
void GameMechs::setInput(char this_input)
{
    input = this_input;
}

//Clearing the input character 
void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here