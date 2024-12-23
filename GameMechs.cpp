#include "GameMechs.h"
#include "MacUILib.h"

#include <stdio.h>

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{

    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}


 void GameMechs::collectAsyncInput(){

    if(MacUILib_hasChar()){
        
        input = MacUILib_getChar(); 
    }
 }


char GameMechs::getInput()
{
    return input;
}

int GameMechs::getScore() const
{

    return score;

}

void GameMechs::incrementScore()
{

    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{

    //printf("Escape triggered"); //why doesn't this print
    
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{

    //MacUILib_printf("Lose");
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{

    input = 0;

}

// More methods should be added here