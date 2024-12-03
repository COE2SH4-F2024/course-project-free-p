#include "Food.h"

#include <stdlib.h>
#include <stdio.h>
//#include <time.h>

Food::Food()
{
    //foodPos.pos = new Pos();
    foodPos.pos-> x = -10; //when the game begins don't want the food on the board
    foodPos.pos-> y = -10;
    foodPos.symbol = 'V';

}

Food::~Food()
{
    //delete foodPos.pos;

}

void Food::generateFood(objPosArrayList* blockOff)
{
    foodPos.symbol = 'V';

    int i = 0;
    int j = 0;

    bool sign = true;

    do{

        sign = true;

        foodPos.pos-> x = rand() % 30;
        foodPos.pos-> y = rand() % 15;

        //printf("X: %d, Y: %d", foodPos.pos-> x, foodPos.pos-> y);

        if(foodPos.pos-> y == 0 || foodPos.pos-> x == 0 || foodPos.pos-> x == 29 || foodPos.pos-> y == 14){
        
            sign = false;
        
            foodPos.pos-> x = rand() % 30;
            foodPos.pos-> y = rand() % 15;
        }

        for(i = 0; i < blockOff-> getSize(); i++){

            objPos blockPos = blockOff-> getElement(i);

            if(foodPos.pos-> x == blockPos.pos-> x && foodPos.pos-> y == blockPos.pos-> y){
                
                sign = false;
                
                foodPos.pos-> x = rand() % 30;
                foodPos.pos-> y = rand() % 15;

            }
        }

    }while(sign != true);
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

int Food:: getX1(){

    return foodPos.pos-> x;
}

int Food:: getY1(){

    return foodPos.pos-> y;
}

char Food:: getSymbol1(){

    return foodPos.symbol;
}