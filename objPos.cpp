#include "objPos.h"
#include <cstddef>
// Default Constructor (1/4)
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

// Other Constructor
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

// Copy Constructor (2/4)
objPos::objPos(const objPos &a)
{
    //cout << "Copy Constructor Called\n";
    symbol = a.symbol;
    if (a.pos != NULL) 
    {
        pos = new Pos; // Allocate new memory for the current object
        pos->x = a.pos->x; // Copy x-coordinate
        pos->y = a.pos->y; // Copy y-coordinate
    } 

    else 
    {
        pos = NULL; // Handle the case where the source object's pointer is null
        // a.pos->x = pos.x;
        // a.pos->y = pos.y;
    }
}

// Copy Assignment Operator (3/4)
objPos& objPos::operator=(const objPos &a)
{
    //cout << "Copy Assignment Operator Called\n";

    if (this == &a) {
        return *this;
    }

    // Free the existing memory for `this->pos`
    delete pos;

    this->symbol = a.symbol; // Copy symbol

    // Deep copy for `pos`
    if (a.pos != NULL)
    {
        pos = new Pos; // Allocate new memory for `this->pos`
        pos->x = a.pos->x; // Copy x-coordinate
        pos->y = a.pos->y; // Copy y-coordinate
    } 
    
    else //Might be uneccessary 
    {
        pos = NULL; // Handle case where `a.pos` is null
    }

    return *this; // Return the current object by reference
    }


// Destructor (4/4)
objPos::~objPos()
{
    //cout << "Destructor Called\n";
    delete pos;
    pos = NULL;
}

//Setting the position and symbol of object without any initial parameters
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}
//Setting the poition and the symbol of object with initial parameters
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}
//Rreturning all the qualities of the object 
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}
//Returning just the symbol of the object 
char objPos::getSymbol() const
{
    return symbol;
}
//Checking if the current psoition of the symbol is equal to another item 
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

//Returning the symbol of the one matched with the previous one 
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}