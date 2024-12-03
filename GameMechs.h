#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "Food.h"
class objPosArrayList; 
using namespace std;

//Declaring the class and functions 

class GameMechs
{
    //Only accessible within the class 
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        Food food;


    //accessible within the entire program
    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); //Not needed 
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        const objPos& getFood() const; 
        void generateFood(const objPosArrayList& blockOff); 
        
        // More methods should be added here
};

#endif