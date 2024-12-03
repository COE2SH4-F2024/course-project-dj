
#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

#include <iostream>

//Constructor
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; 
    listSize = 0; 
    aList = new objPos[arrayCapacity];
}

//Destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList; 
}

//Returning the size of the array at that point in time
int objPosArrayList::getSize() const{
    return listSize; 
}

//Inserting an element at the head of the snake 
void objPosArrayList::insertHead(objPos thisPos)
{   
    //CHeckin g if the array is full 
    if(listSize >= arrayCapacity){
        std::cout << "List is full can't insert at the head.\n"; 
        return; 
    }

    //Shifting the position of all the current elements 
    int i; 
    for (i = listSize; i > 0 ; --i){
        aList[i] = aList[i-1]; 
    }

    //Adrding the new element and incrementing the list size 
    aList[0] = thisPos; 
    listSize++; 
}

//Inserting an element at the tail 
void objPosArrayList::insertTail(objPos thisPos){
    if(listSize >= arrayCapacity){
        std::cout << "List is full can't insert at the tail.\n"; 
        return; 
    }
    aList[listSize] = thisPos; 
    listSize++; 
}

//Remove the head 
void objPosArrayList::removeHead(){
    if(listSize == 0){
        std::cout << "List is empty\n"; 
    }
    int i; 
    for(i = 0; i <listSize -1; ++i){
        aList[i] = aList[i+1]; 
    }
    listSize--; 
}

//Return the element at the head to check if the list is empty now 
objPos objPosArrayList::getHeadElement() const{
    if(listSize == 0){
        std::cout << "List is empty"; 
    }
    return aList[0]; 
}

//Returning speciftic elements in the list 
objPos objPosArrayList::getElement(int index) const{
    if(index<0||index>=listSize){
        std::cout << "Index is out of range"; 
    }
    return aList[index]; 
}

//Removing the element at the tail of the list  
void objPosArrayList::removeTail() {
    if (listSize > 0) {
        listSize--;
    } else {
        std::cout <<"List is empty";
    }
}


//Returning the tail elemnent 
objPos objPosArrayList::getTailElement() const {
    if (listSize > 0) {
        return aList[listSize - 1]; 
    } else {
        throw std::out_of_range("List is empty"); 
        return objPos(); 
        //std::cout<<"List is empty";
    }
}
