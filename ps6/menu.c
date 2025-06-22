#include "menu.h"

void DrawAsciiArt(void)
{
    char AcsiiArtBlocks[12][60] = {
        " ________  ________  ________  ________  ________  ________ ",
        "|        ||        ||        ||        ||        ||        |",
        "|________||________||________||________||________||________|",
        "                     ________  ________  ________  ________ ",
        "                    |        ||        ||        ||        |",
        "                    |________||________||________||________|",
        " ________                      ________  ________  ________ ",
        "|        |                    |        ||        ||        |",
        "|________|                    |________||________||________|",
        " ________                                          ________ ",
        "|        |                                        |        |",
        "|________|                                        |________|",
    };
    char AcsiiArtBall[5][60] = {
        "                        .---.                               ",
        "                       /     \\                              ",
        "                       \\     /                              ",
        "                        `---'                               ",
        "                                                            ",
    };
    char AcsiiArtPaddle[2][60] = {
        "                        ___________________                 ",
        "                       |___________________|                ",
    };
    char AcsiiArtLabel[6][64] = {
        "        _____         __                         __     ___     ",
        "       /  _  \\_______|  | ______    ____   ____ |__| __| _/     ",
        "      /  /_\\  \\_  __ \\  |/ |__  \\  /    \\ /  _ \\|  |/ __ |      ",
        "     /    |    \\  | \\/    < / __ \\|   |  (  <_> )  / /_/ |      ",
        "     \\____|__  /__|  |__|_ (____  /___|  /\\____/|__\\____ |      ",
        "             \\/           \\/    \\/     \\/               \\/      ",
    };
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mvwaddch(startWin, j + BORDER_WIDHT + 18, i + BORDER_WIDHT + 2, AcsiiArtPaddle[j][i]);
        }
    }
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mvwaddch(startWin, j + BORDER_WIDHT + 12, i + BORDER_WIDHT + 2, AcsiiArtBall[j][i]);
        }
    }
    for (int i = 0; i < 60; i += 10)
    {
        for (int j = 0; j < 12; j += 3)
        {
            COLOR color = 10 + (COLOR)rand() % 6;
            wattron(startWin, COLOR_PAIR(color));
            for (int k = 0; k < 10; k++)
            {
                mvwaddch(startWin, j + BORDER_WIDHT, i + k + BORDER_WIDHT + 2, AcsiiArtBlocks[j][i + k]);
                mvwaddch(startWin, j + BORDER_WIDHT + 1, i + k + BORDER_WIDHT + 2, AcsiiArtBlocks[j + 1][i + k]);
                mvwaddch(startWin, j + BORDER_WIDHT + 2, i + k + BORDER_WIDHT + 2, AcsiiArtBlocks[j + 2][i + k]);
            }
            wattroff(startWin, COLOR_PAIR(color));
        }
    }
    wattron(startWin, COLOR_PAIR(BLUE));
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            mvwaddch(startWin, j + BORDER_WIDHT + 21, i + BORDER_WIDHT, AcsiiArtLabel[j][i]);
        }
    }
    wattroff(startWin, COLOR_PAIR(BLUE));
    wrefresh(startWin);
}
void DrawStartPage(void)
{
    wclear(startWin);
    wclear(menuWin);
    box(startWin, 0, 0);
    box(menuWin, 0, 0);
    mvwprintw(startWin, 0, 3, "[ARKANOID by ANDREW]");
    mvwprintw(menuWin, 0, 3, "[MENU]");
    DrawAsciiArt();
    wrefresh(startWin);
    wrefresh(menuWin);
    refresh();
}
void ChooseLevelDifficult(WINDOW *tmpWin)
{
    init_pair(9, COLOR_BLUE, COLOR_WHITE);
    bool StopWhile = FALSE;
    mvwprintw(tmpWin, 0, 3, "[CHOOSE DIFFICULTY]");
    wrefresh(tmpWin);
    const int ItemCount = 4;
    int MenuChoice = 1;
    int key;
    char item[4][24] = {
        "Easy/Beginner         ",
        "Normal/Medium         ",
        "Hard/Expert           ",
        "Return to menu        ",
    };
    while (!StopWhile)
    {
        for (int i = 0; i < ItemCount; i++)
        {
            if (i + 1 == (int)LevelDifficult)
            {
                wattron(tmpWin, COLOR_PAIR(BLACK));
            }
            if (MenuChoice == i + 1)
            {
                if (MenuChoice == ItemCount)
                {
                    wattron(tmpWin, COLOR_PAIR(RED));
                }
                else if (MenuChoice == (int)LevelDifficult)
                {
                    wattron(tmpWin, COLOR_PAIR(9));
                }
                else
                {
                    wattron(tmpWin, COLOR_PAIR(BLUE));
                }
                if (!UseColor)
                {
                    wattron(tmpWin, A_STANDOUT);
                }
            }
            mvwprintw(tmpWin, (i + 1) * 2, 2, item[i]);
            if (i + 1 == (int)LevelDifficult)
            {
                wattroff(tmpWin, COLOR_PAIR(BLACK));
            }
            if (MenuChoice == ItemCount)
            {
                wattroff(tmpWin, COLOR_PAIR(RED));
            }
            else if (MenuChoice == (int)LevelDifficult)
            {
                wattroff(tmpWin, COLOR_PAIR(9));
            }
            else
            {
                wattroff(tmpWin, COLOR_PAIR(BLUE));
            }
            if (!UseColor)
            {
                wattroff(tmpWin, A_STANDOUT);
            }
        }
        wrefresh(tmpWin);

        key = getch();
        switch (key)
        {
        case KEY_UP:
            MenuChoice--;
            if (MenuChoice < 1)
                MenuChoice = ItemCount;
            break;
        case KEY_DOWN:
            MenuChoice++;
            if (MenuChoice > ItemCount)
                MenuChoice = 1;
            break;
        case 10:
            if (MenuChoice != ItemCount)
            {
                LevelDifficult = (enum Difficult)MenuChoice;
            }
            StopWhile = TRUE;
            break;
        case 27:
            StopWhile = TRUE;
            break;
        }
    }
    DrawAsciiArt();
    wrefresh(startWin);
}
void ChooseLevelsName(WINDOW *tmpWin)
{
    bool StopWhile = FALSE;
    mvwprintw(tmpWin, 0, 3, "[CHOOSE LEVELS MAPS]");
    wrefresh(tmpWin);
    const int ItemCount = 4;
    int MenuChoice = 1;
    int key;
    char item[4][15] = {
        "Hurricane",
        "Underdog",
        "Rookie",
        "Return to menu",
    };
    while (!StopWhile)
    {
        for (int i = 0; i < ItemCount; i++)
        {
            if (MenuChoice == i + 1)
            {
                if (MenuChoice == ItemCount)
                {
                    wattron(tmpWin, COLOR_PAIR(RED));
                }
                else
                {
                    wattron(tmpWin, COLOR_PAIR(BLUE));
                }
                if (!UseColor)
                {
                    wattron(tmpWin, A_STANDOUT);
                }
            }
            mvwprintw(tmpWin, (i + 1) * 2, 2, item[i]);
            if (MenuChoice == ItemCount)
            {
                wattroff(tmpWin, COLOR_PAIR(RED));
            }
            else
            {
                wattroff(tmpWin, COLOR_PAIR(BLUE));
            }
            if (!UseColor)
            {
                wattroff(tmpWin, A_STANDOUT);
            }
        }
        wrefresh(tmpWin);

        key = getch();
        switch (key)
        {
        case KEY_UP:
            MenuChoice--;
            if (MenuChoice < 1)
                MenuChoice = ItemCount;
            break;
        case KEY_DOWN:
            MenuChoice++;
            if (MenuChoice > ItemCount)
                MenuChoice = 1;
            break;
        case 10:
        {
            if (MenuChoice == ItemCount)
            {
                StopWhile = TRUE;
                continue;
            }
            char MapName[20] = "";
            strcat(MapName, item[MenuChoice - 1]);
            strcat(MapName, ".lvl");
            strcat(MapName, "\0");
            StartLevels(MapName);
            StopWhile = TRUE;
            break;
        }
        case 27:
            StopWhile = TRUE;
            break;
        }
    }
    wclear(startWin);
    wclear(menuWin);
    box(startWin, 0, 0);
    box(menuWin, 0, 0);
    mvwprintw(startWin, 0, 3, "[ARKANOID by ANDREW]");
    mvwprintw(menuWin, 0, 3, "[MENU]");
    DrawAsciiArt();
    wrefresh(startWin);
    wrefresh(menuWin);
    refresh();
}
void PrintAboutGame(WINDOW *tmpWin)
{
    delwin(tmpWin);
    int tmpWin_xsize = X_SIZE - menuWin_xsize - 2 * BORDER_WIDHT;
    tmpWin = newwin(menuWin_ysize, tmpWin_xsize, term_yMin + 1, term_xMin + 1);
    box(tmpWin, 0, 0);
    mvwprintw(tmpWin, 0, tmpWin_xsize - 16, "[ABOUT GAME]");
    wattron(tmpWin, COLOR_PAIR(BLUE));
    mvwprintw(tmpWin, 1, 2, "Gameplay");
    mvwprintw(tmpWin, 10, 2, "Control in game");
    mvwprintw(tmpWin, 17, 2, "Author of the project");
    mvwprintw(tmpWin, 25, (tmpWin_xsize - 21) / 2, "Press space to exit.");
    wattroff(tmpWin, COLOR_PAIR(BLUE));

    mvwprintw(tmpWin, 2, 2, "The player controls the \"Vaus\",  a space vessel that acts as");
    mvwprintw(tmpWin, 3, 2, "the game's  \"paddle\" which prevents a ball from falling from");
    mvwprintw(tmpWin, 4, 2, "falling from the playing field, and attempts to  bounce  the");
    mvwprintw(tmpWin, 5, 2, "ball against a number of bricks.  The ball striking a  brick");
    mvwprintw(tmpWin, 6, 2, "causes the brick to disappear. When all the bricks are gone,");
    mvwprintw(tmpWin, 7, 2, "the player advances to the next level, where another pattern");
    mvwprintw(tmpWin, 8, 2, "of bricks appears.");
    mvwprintw(tmpWin, 11, 2, "Use the paddle to direct the \"Vaus\" left or right across the");
    mvwprintw(tmpWin, 12, 2, "bottom of the playfield. Press the arrow keys, right to move");
    mvwprintw(tmpWin, 13, 2, "\"Vaus\" to the right,  and left key to move Vaus to the left.");
    mvwprintw(tmpWin, 14, 2, "By pressing the escape key you can exit the current game and");
    mvwprintw(tmpWin, 15, 2, "return to the main menu.");
    mvwprintw(tmpWin, 18, 2, "Game was written by a first-year student  of the FEI faculty,");
    mvwprintw(tmpWin, 19, 2, "speciality in Informatics, (Andrew) Andrian-Maksym Balaichuk.");
    mvwprintw(tmpWin, 20, 2, "This game is an curses based Arkanoid clone for UNIX/Windows.");
    mvwprintw(tmpWin, 21, 2, "This is free, unencumbered software released into the public.");
    mvwprintw(tmpWin, 22, 2, "Anyone is free to copy, modify,  use, compile  or distribute");
    mvwprintw(tmpWin, 23, 2, "this software, either in source code form  or as a  compiled");
    mvwprintw(tmpWin, 24, 2, "binary, for any purpose, commercial or non - commercial.");
    wrefresh(tmpWin);
    while (getch() != ' ')
        ;
    wclear(startWin);
    wclear(menuWin);
    box(startWin, 0, 0);
    box(menuWin, 0, 0);
    mvwprintw(startWin, 0, 3, "[ARKANOID by ANDREW]");
    mvwprintw(menuWin, 0, 3, "[MENU]");
    DrawAsciiArt();
    wrefresh(startWin);
    wrefresh(menuWin);
    refresh();
}
void CallFunctionMenu(int MenuChoice)
{
    WINDOW *tmpWin = newwin(menuWin_ysize, menuWin_xsize, term_yMin + BORDER_WIDHT, term_xMax - menuWin_xsize - BORDER_WIDHT);
    switch (MenuChoice)
    {
    case 1:
        box(tmpWin, 0, 0);
        wrefresh(tmpWin);
        ChooseLevelsName(tmpWin);
        break;
    case 2:
        box(tmpWin, 0, 0);
        wrefresh(tmpWin);
        ChooseLevelDifficult(tmpWin);
        break;
    case 3:
        PrintAboutGame(tmpWin);
        break;
    case 4:
        delwin(gameBarWin);
        delwin(gameWin);
        delwin(menuWin);
        delwin(startWin);
        delwin(tmpWin);
        endwin();
        exit(0);
        break;
    }
    wclear(tmpWin);
    delwin(tmpWin);
    refresh();
    wclear(menuWin);
    box(menuWin, 0, 0);
    mvwprintw(menuWin, 0, 3, "[MENU]");
    wrefresh(menuWin);
    refresh();
}
void Menu(void)
{
    startWin = newwin(term_yMax - term_yMin, term_xMax - term_xMin, term_yMin, term_xMin);
    menuWin = newwin(menuWin_ysize, menuWin_xsize, term_yMin + BORDER_WIDHT, term_xMax - menuWin_xsize - BORDER_WIDHT);
    DrawStartPage();

    const int ItemCount = 4;
    int MenuChoice = 1;
    int key;
    char item[4][25] = {
        "Choose levels",
        "Set Difficulty",
        "About game",
        "Quit",
    };
    while (TRUE)
    {
        for (int i = 0; i < ItemCount; i++)
        {
            if (MenuChoice == i + 1)
            {
                wattron(menuWin, COLOR_PAIR(BLUE));
                if (MenuChoice == ItemCount)
                {
                    wattron(menuWin, COLOR_PAIR(RED));
                }
                if (!UseColor)
                {
                    wattron(menuWin, A_STANDOUT);
                }
            }
            mvwprintw(menuWin, (i + 1) * 2, 2, item[i]);
            wattroff(menuWin, COLOR_PAIR(BLUE));
            if (MenuChoice == ItemCount)
            {
                wattroff(menuWin, COLOR_PAIR(RED));
            }
            if (!UseColor)
            {
                wattroff(menuWin, A_STANDOUT);
            }
        }
        wrefresh(menuWin);

        key = getch();
        switch (key)
        {
        case KEY_UP:
            MenuChoice--;
            if (MenuChoice < 1)
                MenuChoice = ItemCount;
            break;
        case KEY_DOWN:
            MenuChoice++;
            if (MenuChoice > ItemCount)
                MenuChoice = 1;
            break;
        case 10:
            CallFunctionMenu(MenuChoice);
            break;
        case 27:
            endwin();
            exit(0);
            break;
        default:
            break;
        }
    }

    while (getch() != ' ')
        ;

    delwin(gameBarWin);
    delwin(gameWin);
    delwin(menuWin);
    delwin(startWin);
}
