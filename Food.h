#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class objPosArrayList; 

class Food
{
    private:
    objPosArrayList* foodPos;

    public:
    Food(); // Default Constructor
    ~Food(); // Deconstructor
    
    void generateFood(const objPosArrayList& playerPosList);
    objPos getFoodPos() const;
}