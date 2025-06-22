#ifndef BRICK_H
#define BRICK_H
#include "pch.h"

/* structure BRICK */
struct BRICK
{
    /* structure COORD that stores x and y coordinates */
    struct COORD Coord;
    /* length of the brick */
    int Length;
    /* height of the brick */
    int Height;
    /* enum color with which paddle is displayed */
    COLOR Color;
    /* variable that contains the values 1 and 0 that will determine whether this block is visible */
    int Visible;
};

/**
* Function that draws Brick on the display
* @param Brick structure that want display
*/
void DrawBrick(struct BRICK* Brick);
/**
* Function that deletes Brick from the display
* @param Brick structure that want delete from display
*/
void DeleteBrick(struct BRICK* Brick);
/*
* Function that draws Bricks on the display
* @param Bricks structure 2d array that want display
*/
void DrawAllBricks(struct BRICK** Bricks);
/**
* Function that deletes Bricks from the display
* @param Bricks structure BRICK 2d array that want delete from display
*/
void DeleteAllBricks(struct BRICK** Bricks);
/**
* Function which counts the number of displayed bricks
* @param Bricks structure BRICK 2d array that want count
* @return number of displayed bricks 
*/
int BricksLeft(struct BRICK** Bricks);
/**
* Function which generates a two-dimensional array of bricks
* @param Matrix two-dimensional array template for generating the positions of each brick
* @param BrickLeght leght of the brick
* @param BrickHeight height of the brick
* @return double pointer to an array of type BRICK
*/
struct BRICK** CreateBricksMatrix(char** Matrix, int BrickLeght, int BrickHeight);
/**
* Function which frees dynamically allocated memory for two-dimensional array of bricks
* @param Matrix two-dimensional array which we want to delete
*/
void DeleteBricksMatrix(struct BRICK** Matrix);

#endif /* BRICK_H */