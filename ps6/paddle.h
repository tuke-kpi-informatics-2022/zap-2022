#ifndef PADDLE_H
#define PADDLE_H
#include "pch.h"

/* structure PADDLE */
struct PADDLE
{
    /* structure COORD that stores x and y coordinates */
    struct COORD Coord;
    /* symbol with which paddle is displayed */
    int Symbol;
    /* enum color with which paddle is displayed */
    COLOR Color;
    /* length of the Paddle */
    int Length;
    /* height of the Paddle */
    int Height;
    /* stores whether paddle currently moving */
    bool IsMoved;
    /* structure DirectionX that stores which way paddle moving*/
    DirectionX DirX;
};

/**
* Function that initializes the structure Paddle by setting default values 
* or passed via function parameters
* @param Paddle structure to which we assign values
* @param PaddleLength length of the Paddle
* @param PaddleHeight height of the Paddle
* @Symbol Symbol symbol that is displayed Paddle
* @Symbol Color Paddle color
*/
void ResetPaddle(struct PADDLE* Paddle, int PaddleLength, int PaddleHeight, int Symbol, COLOR Color);
/**
* Function that draws Paddle on the display
* @param Paddle structure that want display
*/
void DrawPaddle(struct PADDLE* Paddle);
/**
* Function that deletes Paddle from the display
* @param Paddle structure that want delete from display
*/
void DeletePaddle(struct PADDLE* Paddle);
/**
* Function that moves Paddle on the display
* @param Paddle structure that want on the display 
*/
void MovePaddle(struct PADDLE* Paddle);

#endif /*PADDLE_H*/