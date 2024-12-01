#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    food = foodRef; 

    // Instantiate playerPosList dynamically
    playerPosList = new objPosArrayList(); 

    // Initialize the snake at the center of the board
    int boardCenterX = mainGameMechsRef->getBoardSizeX() / 2; 
    int boardCenterY = mainGameMechsRef->getBoardSizeY() / 2;
    playerPosList->insertHead(objPos(boardCenterX, boardCenterY, '*')); 

}

Player::~Player()
{
    // Clean up the dynamically allocated playerPosList
    delete playerPosList;
}

objPos Player::getPlayerPos() const
{
    return playerPosList->getHeadElement(); 
}

void Player::updatePlayerDir()
{ 
    char input = mainGameMechsRef->getInput(); 

    switch(input) 
    {                      
        case ' ':  
            myDir = STOP; 
            break; 
        case 'w': 
            if (myDir != DOWN){ 
                myDir = UP; 
            }
            break;
        case 's': 
            if (myDir != UP){
                myDir = DOWN; 
            }
            break; 
        case 'a':
            if(myDir != RIGHT){
                myDir = LEFT; 
            }
            break; 
        case 'd': 
            if(myDir != LEFT){
                myDir = RIGHT; 
            }
            break; 
        default: 
            break; 
    }  
    mainGameMechsRef->clearInput();    
}

void Player::movePlayer()
{
    if(myDir == STOP){
        return; 
    }

    objPos headPos = playerPosList->getHeadElement(); 

    int x = headPos.pos->x; 
    int y = headPos.pos->y; 
    int boardWidth = mainGameMechsRef->getBoardSizeX(); 
    int boardHeight = mainGameMechsRef->getBoardSizeY(); 

    switch(myDir){ 
        case UP: 
            y = (y - 1 + boardHeight) % boardHeight; 
            break; 
        case DOWN: 
            y = (y + 1) % boardHeight;    
            break; 
        case LEFT:
            x = (x - 1 + boardWidth) % boardWidth;
            break; 
        case RIGHT: 
            x = (x + 1) % boardWidth;   
            break; 
        case STOP:
            break; 
        default:
            break;
    }

    // Create a new objPos for the new head position
    objPos newHeadPos(x, y, '*');
    objPos foodPos = food->getFoodPos(); 
    int i; 
    for(i = 1; i <playerPosList->getSize(); i++){
        objPos bodySegment = playerPosList->getElement(i); 
        if(newHeadPos.isPosEqual(&bodySegment)){
            mainGameMechsRef->setLoseFlag(); 
            mainGameMechsRef->setExitTrue(); 
            return; 
        }
    }
    if (newHeadPos.isPosEqual(&foodPos)){
        playerPosList->insertHead(newHeadPos);
        mainGameMechsRef->incrementScore();
        food->generateFood(*playerPosList); 
    }else{
        playerPosList->insertHead(newHeadPos);
        playerPosList->removeTail(); 
    }
}

bool Player::checkSelfCollision()
{
    objPos head = playerPosList->getHeadElement();

    // Check if head collides with any other body segment
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        objPos bodySegment = playerPosList->getElement(i);
        if (head.isPosEqual(&bodySegment))
        {
            return true;
        }
    }

    return false;
}

int Player::getScore() const{
    return playerPosList->getSize() - 1; 
}

GameMechs* Player::getGameMechs() const {
    return mainGameMechsRef; 
}

objPosArrayList* Player::getPlayerPosList() const {
    return playerPosList;
}