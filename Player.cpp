#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

//Constructor to initialize the player object 
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

//Destructor 
Player::~Player()
{
    delete playerPosList;
}
//Return current position of the player 
objPos Player::getPlayerPos() const
{
    return playerPosList->getHeadElement(); 
}

//Update the players direction based on input 
void Player::updatePlayerDir()
{ 
    char input = mainGameMechsRef->getInput(); 

    switch(input) //Switches between different viable user inputs 
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

//Move the player based on direction 
void Player::movePlayer()
{
    if(myDir == STOP){
        return; 
    }

    objPos headPos = playerPosList->getHeadElement(); //Get the current head position

    int x = headPos.pos->x;  //Get the x and y positions of the head 
    int y = headPos.pos->y; 
    int boardWidth = mainGameMechsRef->getBoardSizeX(); 
    int boardHeight = mainGameMechsRef->getBoardSizeY(); 

    switch(myDir){  //Moves the player based on the directions 
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
    //Create a new position for the head 
    objPos newHeadPos(x, y, '*');
    objPos foodPos = food->getFoodPos(); //Get the position of the food 
    int i; 
    for(i = 1; i <playerPosList->getSize(); i++){ //Check for collisions 
        objPos bodySegment = playerPosList->getElement(i); 
        if(newHeadPos.isPosEqual(&bodySegment)){
            mainGameMechsRef->setLoseFlag(); 
            mainGameMechsRef->setExitTrue(); 
            return; 
        }
    }
    if (newHeadPos.isPosEqual(&foodPos)){ //Check if there is food eaten 
        playerPosList->insertHead(newHeadPos); //Add the new position to the list 
        mainGameMechsRef->incrementScore(); //Increase the score 
        food->generateFood(*playerPosList); //Generate new food 
    }else{
        playerPosList->insertHead(newHeadPos);
        playerPosList->removeTail(); //In the event that food has not been eaten, the player head moves forward while the current tail gets deleted
    }
}

bool Player::checkSelfCollision() //Checks if the snakje collides with itself
{
    objPos head = playerPosList->getHeadElement();

    for (int i = 1; i < playerPosList->getSize(); i++) //Checks if it collided with any part of the snake 
    {
        objPos bodySegment = playerPosList->getElement(i);
        if (head.isPosEqual(&bodySegment))
        {
            return true;
        }
    }

    return false;
}

int Player::getScore() const{ //Gets the players score 
    return playerPosList->getSize() - 1; 
}

GameMechs* Player::getGameMechs() const { //Returns a referene to gameMechs object 
    return mainGameMechsRef; 
}

objPosArrayList* Player::getPlayerPosList() const { //Returns a reference to the player position list 
    return playerPosList;
}