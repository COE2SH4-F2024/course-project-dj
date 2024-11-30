#ifndef OBJPOSARRAYLIST_H
#define OBJPOSARRAYLIST_H

#include "objPos.h" // Required for using objPos.

#define ARRAY_MAX_CAP 200 // Maximum capacity for the array list.

class objPosArrayList {
private:
    objPos* aList;        // Dynamic array to store objPos elements.
    int listSize;         // Current size of the list.
    int arrayCapacity;    // Maximum capacity of the list.

public:
    objPosArrayList();    // Constructor.
    ~objPosArrayList();   // Destructor.

    int getSize() const;                     // Get the current size of the list.
    void insertHead(objPos thisPos);         // Insert an element at the head of the list.
    void insertTail(objPos thisPos);         // Insert an element at the tail of the list.
    void removeHead();                       // Remove the head element.
    void removeTail();                       // Remove the tail element.

    objPos getHeadElement() const;           // Get the head element.
    objPos getTailElement() const;           // Get the tail element.
    objPos getElement(int index) const;      // Get an element at a specific index.
};

#endif
