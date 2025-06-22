#include <stdbool.h>
#define BLANK ' '

/**
 * Colors
 */
#define COLOR_RED() printf("\033[0;31m")    // red
#define COLOR_GREEN() printf("\033[0;32m")  // green
#define COLOR_YELLOW() printf("\033[0;33m") // yellow
#define COLOR_BLUE() printf("\033[0;34m")   // blue
#define COLOR_PURPLE() printf("\033[0;35m") // purple
#define COLOR_CYAN() printf("\033[0;36m")   // cyan
#define COLOR_WHITE() printf("\033[0;37m")  // white
#define COLOR_BLACK() printf("\033[0;30m")  // black
#define COLOR_STANDART() printf("\033[0m")  // black background and white text

/**
 * Function moves the cursor to another line
 */
#define NEXT_LINE() printf("\n")

/**
 * Function draw char symbol with color
 * @param symbol symbol to output
 */
void printSymbol(char symbol);

/**
 * Function returns 2D array of randomly generated characters
 * There must be two blank columns and other should be full of characters without '\0' or blank spaces
 * @param rows count of rows
 * @param columns count of columns
 * @param field hold 2d array of characters in game
 */
void generator(const int rows, const int columns, char field[rows][columns]);

/**
 * Function draw game field
 * @param rows count of rows
 * @param columns count of columns
 * @param field hold 2d array of characters in game
 */
void game_field(const int rows, const int columns, char field[rows][columns]);

/**
 * Check fields rows if there are same characters
 * @param rows count of rows
 * @param columns count of columns
 * @param field hold 2d array of characters in game
 * @return true, if columns are complete; false otherwise
 */
bool check(const int rows, const int columns, char field[rows][columns]);

/**
 * Function returns 2D array after moving characters based on player input
 * When characters are not same, nothing happens and warning appears
 * Function also find the most upper character and the lower character from columns
 * @param rows count of rows
 * @param columns count of columns
 * @param field hold 2d array of characters in game
 * @param x is column from where character should be moved
 * @param y is column where character should be moved
 */
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y);

/**
 * Starts interactive ball sort puzzle game
 */
void ball_sort_puzzle();
