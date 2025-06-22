#ifndef GAME_H
#define  GAME_H
#include "pch.h"
#include "brick.h"
#include "paddle.h"
#include "ball.h"

/**
* Function that displays a message in the game window
* @param msg char arr to output
* @param Color text color
*/ 
void DrawMessage(char* msg, COLOR Color);
/**
* Function which displays a message about the start of the game in the game window,
* and waits for the input of a space or an escape
* @return true, if space was pressed; false, if escape was pressed
*/
bool WaitForUserStartGame(void);
/**
* Function Which displays an exit message in the game window,
* and waits for a character 'y' or 'n' to be entered
* @return true, if 'y' was pressed; false, if 'n' was pressed
*/
bool WaitForUserExitGame(void);
/**
* Which displays in the game window a message about a loss and a question about restarting the game,
* and waits for a character 'y' or 'n' to be entered
* @return true, if 'y' was pressed; false, if 'n' was pressed
*/
bool WaitForUserLostGame(void);
/** Function which displays in the game window a message about a level win and a question about go to the next level,
* and waits for a character 'y' or 'n' to be entered
* @return true, if 'y' was pressed; false, if 'n' was pressed
*/
bool WaitForUserNextGame(int CurrentLevel, int LevelCount);
/** Function that generates a three-dimensional array of levels by reading data from a file
* @param FileName name of the file from which the levels will be read
* @param LevelCount parameter passed as a pointer to return the number of levels
* @return triple pointer to an char arrays
*/
char*** CreateLevelFromFile(const char* FileName, int* LevelCount);
/**
* Function which frees dynamically allocated memory for three-dimensional array of char
* @param array three-dimensional array which we want to delete
* @param LevelCount three-dimensional array size of two-dimensional array
*/
void DeleteLevelMarixArray(char*** array, int* LevelCount);
/**
* Function which updates the statistics in the window gameBarWin
* @param CurrentScore number of points earned in the game
* @param CurrentLives number of lives in the game
* @param CurrentLevel current level in the game
*/
void UpdateGameStats(int CurrentScore, int CurrentLives, int CurrentLevel);
/**
* Functionthat is a loop of the game
* @param Ball ball in the game
* @param Paddle paddle in the game
* @param Levels three-dimensional array of levels
* @param LevelCount number of levels
*/
void GameLoop(struct BALL* const Ball, struct PADDLE* Paddle, char*** Levels, int LevelCount);
/**
* Function that starts game
* @param FileName name of the file from which the levels will be read
*/
void StartLevels(const char* FileName);

#endif /*GAME_H*/