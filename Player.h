#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  

        // Constructor and Destructor
        Player(GameMechs* thisGMRef); 
        ~Player();

        // objPos getPlayerPos() const; Upgrade this in iteration 3. 
        objPosArrayList* getPlayerPos() const;     
        GameMechs* getGameMechs() const;  

        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        bool checkFoodConsumption(objPos foodPos);  // Checks if food is consumed
        void increasePlayerLength();                // Increases the player's length
        bool checkSelfCollision();                  // Checks if the player collides with itself
        

    private:
        // objPos playerPos; Upgrade this in iteration 3. 
        objPosArrayList* playerPosList;      
        enum Dir myDir;

        // int boardWidth; 
        // int boardHeight; 

        // Reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif