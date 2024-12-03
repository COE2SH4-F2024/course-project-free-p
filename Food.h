#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"


using namespace std;

class Food
{
    private:
    objPos foodPos;


    public:
    Food();
    ~Food();

    void generateFood(objPosArrayList* blockOff);
    objPos getFoodPos() const; 

    int getX1();
    int getY1();
    char getSymbol1();

};

#endif

