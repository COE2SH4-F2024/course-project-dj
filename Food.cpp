#include "Food.h"
#include <cstdlib>
#include <ctime>

#include "objPos.h"
#include "objPosArrayList.h"

Food::Food() // Default Constructor
{
    // Initialize the food bucket on the heap
    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    delete foodBucket;
}

/* objPos Food::getFoodPos() const{
    return foodPos; 
}
*/

void Food::generateFood(const objPosArrayList& playerPosList, int numFood)
{
    srand(time(NULL));

    for (int i = 0; i < numFood; ++i)
    {
        int x, y;
        bool isValid = false;

        while (!isValid)
        {
            x = rand() % 18 + 1; // Random x-coordinate (avoiding borders)
            y = rand() % 8 + 1;  // Random y-coordinate (avoiding borders)

            objPos tempPos(x, y, '\0');
            isValid = true;

            // Ensure no overlap with the player's position or other food items
            for (int j = 0; j < playerPosList.getSize(); ++j)
            {
                if (tempPos.isPosEqual(&playerPosList.getElement(j)))
                {
                    isValid = false;
                    break;
                }
            }

            for (int j = 0; j < foodBucket->getSize(); ++j)
            {
                if (tempPos.isPosEqual(&foodBucket->getElement(j)))
                {
                    isValid = false;
                    break;
                }
            }
        }

        // Assign a symbol to the food 
        char symbol = (i % 3 == 0) ? 'S' : 'F'; // Every third item is special ('S')

        // Add food to bucket
        objPos newFood(x, y, symbol);
        foodBucket->addToHead(newFood);
    }
}

objPosArrayList* Food::getFoodBucket() const
{
    return foodBucket;
}