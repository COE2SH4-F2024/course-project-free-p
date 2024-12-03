#include <iostream>
#include "MacUILib.h"

//#include "objPos.h"

#include "Player.h"
//#include "Food.h"

#include <stdlib.h>
#include <time.h>

using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM;
Player *myPlayer; //global point meant to make a player object on the heap

Food *snakeFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{
    srand(time(NULL));
    Initialize();


    while(myGM-> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    snakeFood = new Food();

    myPlayer = new Player(myGM, snakeFood);

}

void GetInput(void)
{

    //printf("Input");
    myGM-> collectAsyncInput();
}

void RunLogic(void)
{

    //printf("\nRunLogic");

    objPosArrayList* playerPos = myPlayer-> getPlayerPos(); //is this ok to have in draw string
    
    int playerSize = playerPos-> getSize();

    objPos foodPos = snakeFood-> getFoodPos();

    objPos headPos = playerPos -> getHeadElement();


    //////Generate food for first time
    if((foodPos.pos-> x == -10 && foodPos.pos-> y == -10)){ //generate new food when player first moves
        snakeFood->generateFood(playerPos); //???
    }

    //////Updates players direction
    myPlayer-> updatePlayerDir(); //in charge of directions

    //////Moves players direction
    myPlayer-> movePlayer(); //in charge of actually moving the player

    //////Checks for self hit
    myPlayer->checkSelfCollision(playerSize, playerPos);

    //////Checks to see if player hit food
    myPlayer->checkFoodCollision(playerSize, playerPos, foodPos);

}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    objPosArrayList* playerPos = myPlayer-> getPlayerPos(); //global?
    int playerSize = playerPos-> getSize(); //global?


   //MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
   
   //MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", foodPos.pos->x, foodPos.pos->y, foodPos.symbol);

    int i = 0;
    int j = 0; 


    int boardX = myGM-> getBoardSizeX();
    int boardY = myGM-> getBoardSizeY();

    int k = 0;

    objPos foodPos = snakeFood-> getFoodPos(); //global?

    for(i = 0; i < boardY; i++){
    
        for(j = 0; j < boardX; j++){

            bool sign = false;

            for(int k = 0; k < playerSize; k++){

                objPos thisSeg = playerPos-> getElement(k);

                if(j == thisSeg.pos-> x  && i == thisSeg.pos-> y){

                    MacUILib_printf("%c", thisSeg.symbol);
                    sign = true;

                    break;
                }
            }

            if(sign == false && j == foodPos.pos-> x && i == foodPos.pos-> y){

                MacUILib_printf("%c", foodPos.symbol);
                sign = true;
            }

            if(sign == false){

                if(i == 0 || j == 0 || i == 14 || j == 29){

                    printf("#");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }


    int score = 0;

    score = myGM-> getScore();

    MacUILib_printf("\nSnake Game\n");

    MacUILib_printf("\nSorce: %d", score);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();   

    if(myGM->getLoseFlagStatus()== true){


        MacUILib_printf("You Lose\n\n");
    }

    if(myGM->getExitFlagStatus() == true && myGM->getLoseFlagStatus()== false){
        
        MacUILib_printf("You are exiting without losing\n\n");

    }

    delete myGM;
    delete myPlayer;
    delete snakeFood;

    MacUILib_uninit();
}
