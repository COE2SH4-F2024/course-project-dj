#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  

        // Constructor and Destructor
        Player(GameMechs* thisGMRef, Food* foodRef); 
        ~Player();

        int getScore() const; 
        objPos getPlayerPos() const;    
        GameMechs* getGameMechs() const;  

        void updatePlayerDir();
        void movePlayer();

        // New methods
        bool checkSelfCollision();
        objPosArrayList* getPlayerPosList() const;

    private:
        Food* food; 
        objPosArrayList* playerPosList;      
        enum Dir myDir;
        GameMechs* mainGameMechsRef;
};

#endif