#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    //cout << "Default constructor called\n";
    input = 0;
    exitFlag = 0;
    loseFlag = 0;     
    score = 0;
    boardSizeX = 20;
    boardSizeY = 10;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    //cout << "Other constructor called\n";
    input = 0;
    exitFlag = 0;
    loseFlag = 0;     
    score = 0;

    if(boardX < 2)
    {
        boardX = 20;
    }

    if(boardY < 2)
    {
        boardY = 10;
    }

    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor? 
GameMechs::~GameMechs() 
{
    // nothing on the heap
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() // const // we dont want const because then we cant edit input
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here