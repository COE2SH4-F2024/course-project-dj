#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
// #include "GameMechs.h"
class objPosArrayList; 

class Food
{
    private:
    objPos foodPos;

    public:
    Food(); // Default Constructor
    ~Food(); // Deconstructor
    
    void generateFood(const objPosArrayList& playerPosList);
    objPos getFoodPos() const;
};

#endif