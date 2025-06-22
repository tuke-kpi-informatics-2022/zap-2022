#include "ballsortpuzzle.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int rand_num(int min, int max)
{
    return (rand() % ((max + 1) - min)) + min;
}

void clearBuffer()
{
    char flush = 0;
    while (flush != '\n')
    {
        scanf("%c", &flush);
    }
}

void printErrorMsg(char str[])
{
    COLOR_RED();
    printf("\n %s\n", str);
    COLOR_STANDART();
    printf(" The error will disappear automatically...\n");
    sleep(2);
}

void printSymbol(char symbol)
{
    switch (symbol)
    {
    case '*':
        COLOR_RED();
        break;
    case '@':
        COLOR_BLUE();
        break;
    case '+':
        COLOR_YELLOW();
        break;
    case '^':
        COLOR_GREEN();
        break;
    case '#':
        COLOR_PURPLE();
        break;
    case '~':
        COLOR_CYAN();
        break;
    case '$':
        COLOR_WHITE();
        break;
    }
    printf("%c", symbol);
    COLOR_STANDART();
}

void generator(const int rows, const int columns, char field[rows][columns])
{
    char symbols[] = {'*', '@', '+', '^', '#', '~', '$', '<', '>', 'v', '%', '!', '-', '/', '&', '?', '`', '(', ')'};
    int *symbolsRepeat = (int *)calloc(columns - 2, sizeof(int));
    int columnBlank1 = rand_num(0, columns - 1);
    int columnBlank2 = 0;
    int randNum = 0;

    do
    {
        columnBlank2 = rand_num(0, columns - 1);
    } while (columnBlank1 == columnBlank2);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j == columnBlank1 || j == columnBlank2)
            {
                field[i][j] = BLANK;
                continue;
            }
            do
            {
                randNum = rand_num(0, columns - 2 - 1);
            } while (symbolsRepeat[randNum]++ > rows - 1);
            field[i][j] = symbols[randNum];
        }
    }

    free(symbolsRepeat);
}

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y)
{
    if ((x < 1 || x > columns) || (y < 1 || y > columns))
    {
        printErrorMsg("Error: no such column exists.");
        return;
    }
    else if (x == y)
    {
        printErrorMsg("Error: column what cannot equal column where.");
        return;
    }

    x--;
    y--;

    int rowSymbol = -1;
    int rowSymbol2 = -1;

    for (int i = 0; i < rows; i++)
    {
        if (field[i][x] != BLANK)
        {
            rowSymbol = i;
            break;
        }
    }

    if (rowSymbol == -1)
    {
        printErrorMsg("Error: not possible to move from an empty column.");
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        if (field[i][y] != BLANK)
        {
            rowSymbol2 = i - 1;
            break;
        }
        else if (i == rows - 1)
        {
            rowSymbol2 = i;
            break;
        }
    }

    if (rowSymbol2 == -1)
    {
        printErrorMsg("Error: not possible move to a full column.");
        return;
    }

    if (rowSymbol2 != rows - 1 && field[rowSymbol2 + 1][y] != field[rowSymbol][x])
    {
        printErrorMsg("Error: cannot put different symbols together.");
        return;
    }

    field[rowSymbol2][y] = field[rowSymbol][x];
    field[rowSymbol][x] = BLANK;
}

bool check(const int rows, const int columns, char field[rows][columns])
{
    int *symbolsInColumn = (int *)calloc(columns, sizeof(int));
    bool SymbolsAreSame = true;

    for (int i = 0; i < columns; i++)
    {
        symbolsInColumn[i] = 0;
        for (int j = 0; j < rows; j++)
        {
            if (field[j][i] == field[rows - 1][i])
            {
                symbolsInColumn[i]++;
            }
        }
    }

    for (int i = 0; i < columns; i++)
    {
        if (symbolsInColumn[i] != rows)
        {
            SymbolsAreSame = false;
            break;
        }
    }

    free(symbolsInColumn);

    return SymbolsAreSame;
}

void game_field(const int rows, const int columns, char field[rows][columns])
{
    system("clear");

    for (int j = 0; j < columns; j++)
    {
        printf(" \u2556 \u2553");
    }

    NEXT_LINE();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf(" \u2551");
            printSymbol(field[i][j]);
            printf("\u2551");
        }

        NEXT_LINE();
    }

    for (int j = 0; j < columns; j++)
    {
        printf(" \u255A\u2550\u255D");
    }
    printf("\n  ");

    for (int i = 1; i <= columns; i++)
    {
        printf("%d   ", i);
    }

    NEXT_LINE();
}

void ball_sort_puzzle()
{
    system("clear");
    srand(time(NULL));

    int rows = 4, columns = 6, x = 0, y = 0;

    while (true)
    {
        printf(" Enter the size of game field (rows,columns): ");
        while (scanf("%d %d", &rows, &columns) != 2)
        {
            printErrorMsg("Oops! Invalid input characters");
            clearBuffer();
            printf("\n Enter the size of game field (rows,columns): ");
        }

        if (rows < 4 || rows > 9)
        {
            printErrorMsg(" Error: enter column heights from 4 to 11.");
            NEXT_LINE();
            continue;
        }
        else if (columns < 4 || columns > 9)
        {
            printErrorMsg("Error: enter  number of columns from 4 to 11.");
            NEXT_LINE();
            continue;
        }
        break;
    }

    system("clear");

    char field[rows][columns];

    generator(rows, columns, field);
    game_field(rows, columns, field);

    while (!check(rows, columns, field))
    {
        printf("\n Enter from what to where: ");

        while (scanf("%d %d", &x, &y) != 2)
        {
            printErrorMsg("Oops! Invalid input characters");
            clearBuffer();
            game_field(rows, columns, field);
            printf("\n Enter from what to where: ");
        }

        down_possible(rows, columns, field, x, y);
        game_field(rows, columns, field);
    }

    COLOR_YELLOW();
    printf("\n\n Congratulations, you won!\n\n");
    COLOR_STANDART();
}
