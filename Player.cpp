// #include "Player.h"

// Player::Player(GameMechs* thisGMRef)
// {
//     mainGameMechsRef = thisGMRef;
//     myDir = STOP;
//     int boardCenterX = mainGameMechsRef->getBoardSizeX() / 2; 
//     int boardCenterY = mainGameMechsRef->getBoardSizeY() / 2; 
//     playerPos.setObjPos(boardCenterX, boardCenterY, '*'); 

//     // more actions to be included
// }


// Player::~Player()
// {
//     // delete any heap members here
// }

// objPos Player::getPlayerPos() const
// {
//     return playerPos; 
//     // return the reference to the playerPos arrray list
// }

// void Player::updatePlayerDir()
// {
//     char input = mainGameMechsRef->getInput(); 
//     switch(input) //All the different states of cmd user input that is viable  
//         {                      
//             case ' ':  
//                 myDir = STOP; 
//                 break; 
//             case 'w': 
//                 if (myDir != DOWN){ 
//                     myDir = UP; 
//                     }
//                     break;
//             case 's': 
//                 if (myDir != UP){
//                     myDir = DOWN; 
//                 }
//                 break; 
//             case 'a':
//                 if(myDir != RIGHT){
//                     myDir = LEFT; 
//                 }
//                 break; 
//             case 'd': 
//                 if(myDir != LEFT){
//                     myDir = RIGHT; 
//                 }
//                 break; 
//             default: 
//                 break; 
//         // PPA3 input processing logic
//         }  
//     mainGameMechsRef->clearInput(); 
// }
// void Player::movePlayer()
// {
//     if(myDir == STOP){
//         return; 
//     }
//     //objPos headPos = playerPosList->getHeadElement(); 
//     int x = playerPos.getObjPos().pos->x; 
//     int y = playerPos.getObjPos().pos->y; 
//     int boardWidth = mainGameMechsRef->getBoardSizeX(); 
//     int boardHeight = mainGameMechsRef->getBoardSizeY(); 
//     switch(myDir){ //Will continually loop through this and add/subtract for that direction 
//         case UP: 
//             y = (y - 1 + boardHeight) % boardHeight; //Adding boardHeight in order to avoid negative value here, modulus means its all the same anyways
//             break; 
//         case DOWN: 
//             y = (y + 1) % boardHeight;    //When it goes higher then the value of boardheight, the modulus will wrap around
//             break; 
//         case LEFT:
//             x = (x - 1 + boardWidth) % boardWidth;//Only in the event of negative 1 will this lead to the wrapound 
//             break; //Up until -1, it will represent the value, and then after it it will do so too because of the modulus 
//         case RIGHT: 
//             x = (x + 1) % boardWidth;   
//             break; 
//         case STOP:
//             break; 
//     }
//     playerPos.setObjPos(x, y, '*'); 
//     //objPos newHeadPos; 
//     //newHeadPos.setObjPos(x, y, '*'); 
//     //playerPosList->insertHeade(newHeadPos); 
//     //playerPosList->removeTail; 
//     // PPA3 Finite State Machine logic
// }
// GameMechs* Player::getGameMechs() const{
//     return mainGameMechsRef;
// }
// // More methods to be added