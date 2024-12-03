#include "objPosArrayList.h"
#include <iostream>
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; 
    listSize = 0; 
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; 
}

int objPosArrayList::getSize() const{
    return listSize; 
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize >= arrayCapacity){
        std::cout << "List is full can't insert at the head.\n"; 
        return; 
    }

    int i; 
    for (i = listSize; i > 0 ; --i){
        aList[i] = aList[i-1]; 
    }

    aList[0] = thisPos; 
    listSize++; 
}

void objPosArrayList::insertTail(objPos thisPos){
    if(listSize >= arrayCapacity){
        std::cout << "List is full can't insert at the tail.\n"; 
        return; 
    }
    aList[listSize] = thisPos; 
    listSize++; 
}

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

objPos objPosArrayList::getHeadElement() const{
    if(listSize == 0){
        std::cout << "List is empty"; 
    }
    return aList[0]; 
}

objPos objPosArrayList::getElement(int index) const{
    if(index<0||index>=listSize){
        std::cout << "Index is out of range"; 
    }
    return aList[index]; 
}

void objPosArrayList::removeTail() {
    if (listSize > 0) {
        listSize--;
    } else {
        std::cout <<"List is empty";
    }
}

objPos objPosArrayList::getTailElement() const {
    if (listSize > 0) {
        return aList[listSize - 1]; 
    } else {
        std::cout<<"List is empty";
    }
}

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
