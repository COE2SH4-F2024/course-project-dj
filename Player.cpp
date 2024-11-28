#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    // int boardCenterX = mainGameMechsRef->getBoardSizeX() / 2; 
    // int boardCenterY = mainGameMechsRef->getBoardSizeY() / 2; 
    // playerPos.setObjPos(boardCenterX, boardCenterY, '*'); 
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{ 
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added