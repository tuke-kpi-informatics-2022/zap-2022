#ifndef MENU_H
#define  MENU_H
#include "pch.h"
#include "game.h"

/**
* Function that draws ascii art on the main page
*/
void DrawAsciiArt(void);
/**
* Function that draws start page on the main page
*/
void DrawStartPage(void);
/**
* Function which brings up a level difficulty selection menu 
* @param tmpWin the window in which the menu will be displayed
*/
void ChooseLevelDifficult(WINDOW* tmpWin);
/**
* Function which brings up a level selection menu
* @param tmpWin the window in which the menu will be displayed
*/
void ChooseLevelsName(WINDOW* tmpWin);
/**
* Function which prints about the game
* @param tmpWin the window in which the text will be displayed
*/
void PrintAboutGame(WINDOW* tmpWin);
/**
* Function that calls the selected menu item
* @param MenuChoice selected menu item
*/
void CallFunctionMenu(int MenuChoice);
/** Menu function
*/
void Menu(void);

#endif /*MENU_H*/