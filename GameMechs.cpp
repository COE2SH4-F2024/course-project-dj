#include "GameMechs.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY)
{
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return false; 
}

bool GameMechs::getLoseFlagStatus() const
{
    return false; 
}
    

char GameMechs::getInput() const
{
    return '\0';
}

int GameMechs::getScore() const
{
    return 0; 
}

void GameMechs::incrementScore()
{
    
}

int GameMechs::getBoardSizeX() const
{
    return 20; 
}

int GameMechs::getBoardSizeY() const
{
    return 10; 
}


void GameMechs::setExitTrue()
{

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here