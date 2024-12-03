#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;

    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(const objPosArrayList &sList){

    int i =0;

    listSize = sList.listSize;
    arrayCapacity = sList.arrayCapacity;

    aList = new objPos[ARRAY_MAX_CAP];

    for(i = 0; i < listSize; i++){

        aList[i] = sList.aList[i];
    }

}


int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    int i = 0; 

    if(listSize == arrayCapacity){
        return;
    }


    for(i = listSize; i > 0; i--){

        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    int i = 0; 

    if(listSize == arrayCapacity){
        return;
    }

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    int i = 0;

    if(listSize == 0){
        return;
    }

    for(i = 0; i < listSize; i++){
        
        aList[i] = aList[i+1];
    }

    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize == 0){
        return;
    }

    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    //if(index < 0 || index >= listSize){
        //return;
    //}

    return aList[index];
}