#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"
// #include "GameMechs.h"

using namespace std;

class Food
{
    private:
    objPos foodPos;

    public:
    Food(); // Default Constructor
    ~Food(); // Deconstructor
    
    void generateFood(objPos blockOff);
    objPos getFoodPos() const;
}