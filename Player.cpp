#include <stdio.h>

#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    
    mainGameFood = thisFood;

    direction = STOP;

    playerPosList = new objPosArrayList();

    objPos headPos(mainGameMechsRef-> getBoardSizeX()/2, mainGameMechsRef-> getBoardSizeY()/2, '@');

    playerPosList-> insertHead(headPos);

    // more actions to be included

    /*
    playerPos.pos-> x = mainGameMechsRef-> getBoardSizeX()/2;
    playerPos.pos-> y = mainGameMechsRef-> getBoardSizeY()/2;
    playerPos.symbol = '@';
    */


   //printf("Player: %d", playerPos->getSize();)
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list

    
    return playerPosList;
}

void Player::updatePlayerDir()
{

    char input = 0;
    input = mainGameMechsRef-> getInput();

    // PPA3 input processing logic        

    if(input == 27){ //is esc pressed then exit

        //printf("Escape Pressed");
        mainGameMechsRef -> setExitTrue();
    }
    
    if(input == 'a' || input == 'A'){ //a will only work if the direction before was down, up or nothing
        
        if(direction == DOWN || direction == UP || direction == STOP){
            direction = LEFT;
        }

    }

    else if(input == 'd'|| input == 'D'){

        if(direction == DOWN || direction == UP || direction == STOP){
            direction = RIGHT;
        }
    }

    else if(input == 'w' || input == 'W'){

        if(direction == RIGHT || direction == LEFT || direction == STOP){
            direction = UP;
        }

    }

    else if(input == 's' || input == 'S'){
        
        if(direction == RIGHT || direction == LEFT || direction == STOP){
            direction = DOWN;
        }

    }

    mainGameMechsRef-> clearInput();
  
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    int boardX = mainGameMechsRef-> getBoardSizeX();
    int boardY = mainGameMechsRef-> getBoardSizeY();

    objPos temp = playerPosList -> getHeadElement();
    
    
    //CHANGING DIRECTION
    if(direction == LEFT){ 
        temp.pos->x--;
    }
    else if(direction == RIGHT){
        temp.pos->x++;
    }
    else if(direction == UP){
        temp.pos->y--;
    }
    else if(direction == DOWN){
        temp.pos->y++;
    }


    //WRAP-AROUND
    if(temp.pos->x <= 0){ //horizontal
        temp.pos->x = boardX - 2; //so it does go on the border
    }
    else if(temp.pos->x >= boardX - 1){
        temp.pos->x = 1;
    }
    else{
        temp.pos->x = (temp.pos->x + boardX) % boardX; 
    }

    if(temp.pos->y <= 0){ //vertical
        temp.pos->y = boardY - 2;
    }
    else if(temp.pos->y >= boardY - 1){
        temp.pos->y = 1;
    }
    else{
        temp.pos->y = (temp.pos->y + boardY) % boardY; 
    }


    playerPosList -> insertHead(temp);

    
    objPos foodPos = mainGameFood-> getFoodPos();


    if(temp.isPosEqual(&foodPos) == 0){ //if no food collision
        
        playerPosList-> removeTail();
    }
    else if (temp.isPosEqual(&foodPos) == 1){

        //checkFoodConsumption();
    }

}

// More methods to be added

bool Player:: checkFoodConsumption(){
}


void Player::increasePlayerLength(){
}

void Player::checkSelfCollision(int sizeOfSnake, objPosArrayList* snakeBody){

    //doesn't need to be bool can be void

    int i = 0;

    //int playerSize = playerPos-> getSize();

    objPos headPos = snakeBody -> getHeadElement();

    for(i = 1; i < sizeOfSnake; i++){

        objPos bodySeg = snakeBody-> getElement(i);

            if(headPos.isPosEqual(&bodySeg) == 1){

                mainGameMechsRef-> setLoseFlag();
                mainGameMechsRef-> setExitTrue();
            }
    }
}

void Player::checkFoodCollision(int sizeOfSnake, objPosArrayList* snakeBody, objPos foodPosition){

    objPos headPos = snakeBody -> getHeadElement();


    if(headPos.isPosEqual(&foodPosition) == 1){ //if player hits food 

        mainGameFood-> generateFood(snakeBody); //generate new food
        mainGameMechsRef-> incrementScore(); //increase score
    }
}