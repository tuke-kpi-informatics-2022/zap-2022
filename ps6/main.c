#include "pch.h"
#include "menu.h"

void initTerm()
{
#ifdef WIN32
    initscr();
    resize_term(term_yMax, term_xMax);
#else
    struct winsize max; // struct max size of the terminal
    ioctl(0, TIOCGWINSZ, &max); // gets the max size of the terminal
    if (max.ws_row < term_yMax || max.ws_col < term_xMax) {
        printf("The terminal is too small. :(\nPlease resize it to at least %d by %d, and try again.\n\n", term_xMax, term_yMax);
        exit(1);
    }
    term_yMin = (max.ws_row - Y_SIZE) / 2;
    term_xMin = (max.ws_col - X_SIZE) / 2;
    term_yMax = term_yMin + Y_SIZE;
    term_xMax = term_xMin + X_SIZE;
#endif /*WIN32*/
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    if (has_colors() && UseColor)
    {
        start_color();
        init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
        init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
        init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
        init_pair(RED, COLOR_RED, COLOR_BLACK);
        init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(BLACK, COLOR_BLACK, COLOR_WHITE);
    }
    refresh();
}
int main(int argc, char const** argv)
{
#ifndef WIN32
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp("--version", argv[i]))
        {
            printf("Arcanoid v %0.1f \nBy Andrew.\n", ARKANOID_VERSION);
            fflush(NULL);
            exit(0);
        }
        else if (!strcmp("--nocolor", argv[i]))
        {
            UseColor = FALSE;
        }
        else if (!strcmp("--help", argv[i]))
        {
            printf("Command line options:\n--help: Show this help.\n--nocolor: Start game without color.\n--version: Display version and exit.\n");
            fflush(NULL);
            exit(0);
        }
        else
        {
            printf("Bad command line argument %s.\n Use --help for command line options.\n", argv[i]);
            fflush(NULL);
            exit(1);
        }
    }
#endif /*WIN32*/

	srand((unsigned int)time(NULL));
    initTerm();
    Menu();
    endwin();
    return 0;
}
