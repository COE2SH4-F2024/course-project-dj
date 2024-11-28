#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x; // x coordinate 
    int y; // y coordinate
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol; 

        objPos(); // Default Constructor
        objPos(int xPos, int yPos, char sym); // Other Constructor
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule

        objPos::objPos(const objPos &a); // Copy Constructor
        objPos& objPos:: operator=(const objPos &a); // Copy Assignment Operator
        ~objPos::objPos(); // Deconstructor
        
        // Setters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        // Getters
        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif