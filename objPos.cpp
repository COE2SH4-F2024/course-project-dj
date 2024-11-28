#include "objPos.h"

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
    cout << "Copy Constructor Called\n";
    symbol = a.symbol;
    if (a.pos != nullptr) 
    {
        pos = new Pos; // Allocate new memory for the current object
        pos->x = a.pos->x; // Copy x-coordinate
        pos->y = a.pos->y; // Copy y-coordinate
    } 

    else 
    {
        pos = nullptr; // Handle the case where the source object's pointer is null
        a.pos->x = pos.x;
        a.pos->y = pos.y;
    }
}

// Copy Assignment Operator (3/4)
objPos& objPos::operator=(const objPos &a)
{
    cout << "Copy Assignment Operator Called\n";

    if (this == &a) {
        return *this;
    }

    // Free the existing memory for `this->pos`
    delete pos;

    this->symbol = a.symbol; // Copy symbol

    // Deep copy for `pos`
    if (a.pos != nullptr)
    {
        pos = new Pos; // Allocate new memory for `this->pos`
        pos->x = a.pos->x; // Copy x-coordinate
        pos->y = a.pos->y; // Copy y-coordinate
    } 
    
    else 
    {
        pos = nullptr; // Handle case where `a.pos` is null
    }

    return *this; // Return the current object by reference
    }


// Destructor (4/4)
myArray::~myArray()
{
    cout << "Destructor Called\n";
    delete pos;
    pos = nullptr;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
