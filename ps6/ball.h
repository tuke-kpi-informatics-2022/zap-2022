#ifndef BALL_H
#define  BALL_H
#include "pch.h"
#include "brick.h"
#include "paddle.h"

/* structure BALL */
struct BALL
{ 
    /* structure COORD that stores x and y coordinates */
    struct COORD Coord;
    /* symbol with which ball is displayed */
    int Symbol;
    /* enum color with which ball is displayed */
    COLOR Color;
    /* structure DirectionX that stores which way on coordinate X ball is moving */
    DirectionX DirX;
    /* structure DirectionY that stores which way on coordinate Y ball is moving */
    DirectionY DirY;
};

/**
* Function that changes the direction of movement of the ball on the x coordinate
* @param Ball structure to which we assign value
* @param Direction the direction of movement of the ball 
*/
void DirectionBallX(struct BALL* const Ball, DirectionX Direction);
/**
* Function that changes the direction of movement of the ball on the y coordinate
* @param Ball structure to which we assign value
* @param Direction the direction of movement of the ball
*/
void DirectionBallY(struct BALL* const Ball, DirectionY Direction);
/**
* Function that draws Ball on the display
* @param Ball structure that want display
*/
void DrawBall(struct BALL* Ball);
/**
* Function that deletes Ball from the display
* @param Ball structure that want delete from display
*/
void DeleteBall(struct BALL* Ball);
/**
* Function that initializes the structure Ball by setting default values
* or passed via function parameters
* @param Ball structure to which we assign values
* @param PosX start x coordinate
* @param PosY start y coordinate
* @Symbol Symbol symbol that is displayed Ball
* @Symbol Color Ball color
*/
void ResetBall(struct BALL* Ball, int PosX, int PosY, int Symbol, COLOR Color);
/**
* Function that moves Ball on the display
* @param Ball structure that want move on the display
*/
void MoveBall(struct BALL* Ball);
/**
* Function that checks whether the ball will hit the paddle
* @param Ball structure BALL that want check
* @param Paddle structure PADDLE that want check
* @return true, if ball hits paddle; false otherwise
*/
bool CheckPaddleHitBall(struct BALL* Ball, struct PADDLE* Paddle);
/**
* Function that checks whether the ball will hit the Bricks 
* @param Ball structure BALL that want check
* @param Bricks structure array BRICK that want check
* @return number of bricks hit
*/
int BallHitBrick(struct BALL* Ball, struct BRICK** Bricks);

#endif /*BALL_H*/