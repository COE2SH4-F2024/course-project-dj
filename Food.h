#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
// #include "GameMechs.h"
class objPosArrayList; 
using namespace std;

class Food
{
    private:
    objPos foodPos;

    public:
    Food(); // Default Constructor
    ~Food(); // Deconstructor
    
    void generateFood(const objPosArrayList& snakeBody);
    const objPos& getFoodPos() const;
};

#endif