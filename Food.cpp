#include "Food.h"
#include <cstdlib>
#include <ctime>
// #include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

Food::Food() // Default Constructor
{
    foodPos.setObjPos(0, 0, '\0');
}

Food::~Food()
{
    // No dynamic memory used here
}

objPos Food::getFoodPos() const{
    return foodPos; 
}

void Food::generateFood(const objPosArrayList& playerPosList)
{
    srand(time(NULL));

    int x, y;
    bool isValid = false; // assume position is invalid

    while (!isValid)
    {
        x = rand() % (18) + 1; // random number between 1 and 18 for the x values (no food on border)
        y = rand() % (8) + 1; // between 1 and 8 for y

        // Use a temporary objPos object for comparison
        objPos tempPos(x, y, 'F');
        isValid = true; 
        int i; 
        for(i = 0; i < playerPosList.getSize(); ++i){
            objPos element = playerPosList.getElement(i); 
            if(tempPos.isPosEqual(&element)){
                isValid = false; 
                break; 
            }
        }
    }
        // Set the position and symbol for the food
        char symbol = 'F'; 
        foodPos.setObjPos(x, y, symbol); // assign the valid position to the food object
}
