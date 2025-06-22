#ifndef PCH_H
#define PCH_H

/*-----------Necessary libraries-------------------------*/
#ifdef WIN32 // preprocessor directive have the same effect as the #if (if we compile in Windows) then
#define _CRT_SECURE_NO_WARNINGS // Define to disable c++ warnings for vs
#else // else
#include <sys/ioctl.h>
#include <unistd.h>
#endif //WIN32
// connect all necessary libraries
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*-------------------------------------------------------*/

/*--------------Necessary defines------------------------*/
// define that defines the current version of the program
#define ARKANOID_VERSION 0.9
// define that defines the required height of the console
#define Y_SIZE 29
// define that defines the required width of the console
#define X_SIZE 92
// define that defines the width of the frame, it is necessary to not to get confused due to random subtractions/adding units in the code
#define BORDER_WIDHT 1
// define, which defines the max number of bricks in width in the playing field
#define X_BRICKS_COUNT 18
// define, which defines the max number of bricks in height in the playing field
#define Y_BRICKS_COUNT 6
// define, which defines width of brick
#define BRICKS_HEIGHT 2
// define, which defines height of brick
#define BRICKS_LEGHT 5
/*-------------------------------------------------------*/

/*------Necessary variables and defines for window-------*/
//global pointer to the type of WINDOW used for display start window
extern WINDOW* startWin;
//global variable that contains the origin of the y coordinate of the start window 
extern int term_yMin;
//global variable that contains the origin of the x coordinate of the start window 
extern int term_xMin;
//global variable that contains the end of the y coordinate of the start window
extern int term_yMax;
//global variable that contains the end of the x coordinate of the start window
extern int term_xMax;
//global pointer to the type of WINDOW used for display menu window in start window
extern WINDOW* menuWin;
// define, which defines height of menu window
#define menuWin_ysize 27
// define, which defines width of menu window
#define menuWin_xsize 26
//global pointer to the type of WINDOW used for display game window
extern WINDOW* gameWin;
// define, which defines height of game window
#define gameWin_ysize 26
// define, which defines width of game window
#define gameWin_xsize 92
//global pointer to the type of WINDOW used for display gamebar window
extern WINDOW* gameBarWin;
// define, which defines height of gamebar window
#define gameBarWin_ysize 3
// define, which defines width of gamebar window
#define gameBarWin_xsize 92
/*-------------------------------------------------------*/

/*------Necessary enums or struct for all program--------*/
//enum Difficult, which is used to determine the difficulty of the level
enum Difficult
{
    // enum starts from 1
    EASY = 1,
    NORMAL,
    HARD,
};
//global LevelDifficult variable that contains the difficulty of the level
extern int LevelDifficult;
//anonymous enums COLOR, which is used to determine color pair in console
typedef enum
{
    // enum starts from 10
    GREEN = 10,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN,
    RED,
    WHITE,
    BLACK,
} COLOR;
//global UseColor variable that stores the color usage values
extern bool UseColor;
//anonymous enums DirectionX, which is used to determine direction on the axis X
typedef enum
{
    LEFT,
    RIGHT,
    X_NEUTRAL,
} DirectionX;
//anonymous enums DirectionY, which is used to determine direction on the axis Y
typedef enum
{
    DOWN,
    UP,
    Y_NEUTRAL,
} DirectionY;
//structure COORD, which stores coordinates x and y
struct COORD
{
    int X;
    int Y;
};
/*-------------------------------------------------------*/
#endif 



