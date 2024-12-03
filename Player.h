#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();

        //objPos getPlayerPos() const; // Upgrade this in iteration 3.   
        objPosArrayList* getPlayerPos() const;


        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

        /*int getX();
        int getY();
        char getSymbol();*/

        bool checkFoodConsumption(); //?
        void increasePlayerLength(); //why do we need this if the insertHead() function already increase the list by 1

        void checkSelfCollision(int sizeOfSnake, objPosArrayList* snakeBody);
        
        void checkFoodCollision(int sizeOfSnake, objPosArrayList* snakeBody, objPos foodPosition);


    private:
        //objPos playerPos; // Upgrade this in iteration 3.
        objPosArrayList* playerPosList;       
        enum Dir direction;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* mainGameFood;
};

#endif