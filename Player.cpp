#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    
    // Instantiate playerPosList dynamically
    playerPos.setObjPos(boardCenterX, boardCenterY, '*');

    // Initialize the snake at the center of the board
    int boardCenterX = mainGameMechsRef->getBoardSizeX() / 2; 
    int boardCenterY = mainGameMechsRef->getBoardSizeY() / 2;
    objPos startingPos(boardCenterX, boardCenterY, '*');
    playerPosList->addToHead(startingPos); // Add initial position to the list 
     
}


Player::~Player()
{
    // Clean up the dynamically allocated playerPosList
    delete playerPosList;
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{ 
    // PPA3 input processing logic      
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
// PPA3 Finite State Machine logic
    if(myDir == STOP){
        return; 

    
     objPos headPos = playerPosList->getHeadElement(); 

     int x = playerPos.getObjPos().pos->x; 
     int y = playerPos.getObjPos().pos->y; 
     int boardWidth = mainGameMechsRef->getBoardSizeX(); 
     int boardHeight = mainGameMechsRef->getBoardSizeY(); 

     switch(myDir){ //Will continually loop through this and add/subtract for that direction 
         case UP: 
             y = (y - 1 + boardHeight) % boardHeight; //Adding boardHeight in order to avoid negative value here, modulus means its all the same anyways
             break; 
         case DOWN: 
             y = (y + 1) % boardHeight;    //When it goes higher then the value of boardheight, the modulus will wrap around
             break; 
         case LEFT:
             x = (x - 1 + boardWidth) % boardWidth;//Only in the event of negative 1 will this lead to the wrapound 
             break; //Up until -1, it will represent the value, and then after it it will do so too because of the modulus 
         case RIGHT: 
             x = (x + 1) % boardWidth;   
             break; 
         case STOP:
             break; 
     }

    // Create a new objPos for the new head position
    objPos newHeadPos;
    
    //playerPos.setObjPos(x, y, '*'); 
    //newHeadPos.setObjPos(x, y, '*'); 
    playerPosList->addToHead(newHeadPos); 
    playerPosList->removeTail; 
}

// More methods to be added

GameMechs* Player::getGameMechs() const
{
    return mainGameMechsRef;
}