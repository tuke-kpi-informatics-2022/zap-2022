#include "brick.h"

struct BRICK **CreateBricksMatrix(char **Matrix, int BrickLeght, int BrickHeight)
{
    int StructSize = sizeof(struct BRICK);
    struct BRICK **Board = (struct BRICK **)calloc(Y_BRICKS_COUNT, StructSize);

    for (int i = 0; i < Y_BRICKS_COUNT; i++)
    {
        Board[i] = (struct BRICK *)calloc(X_BRICKS_COUNT, StructSize);
    }

    for (int i = 0; i < Y_BRICKS_COUNT; i++)
    {
        for (int j = 0; j < X_BRICKS_COUNT; j++)
        {
            if (Matrix[i][j] == '1')
            {
                Board[i][j].Visible = TRUE;
                Board[i][j].Length = BrickLeght;
                Board[i][j].Height = BrickHeight;
                Board[i][j].Coord.X = (j * BrickLeght) + 1;
                Board[i][j].Coord.Y = (i * BrickHeight) + 1;
                Board[i][j].Color = 10 + (COLOR)rand() % 6;
            }
            else if (Matrix[i][j] == '0')
            {
                Board[i][j].Visible = FALSE;
            }
        }
    }
    return Board;
}
void DeleteBricksMatrix(struct BRICK **Matrix)
{
    for (int i = 0; i < Y_BRICKS_COUNT; i++)
    {
        free(Matrix[i]);
    }

    free(Matrix);
    Matrix = NULL;
}
void DrawBrick(struct BRICK *Brick)
{
    if (Brick->Visible == FALSE)
    {
        return;
    }

    attron(A_BOLD);
    mvwaddch(gameWin, Brick->Coord.Y, Brick->Coord.X, ACS_ULCORNER | COLOR_PAIR(Brick->Color));
    mvwaddch(gameWin, Brick->Coord.Y + Brick->Height - 1, Brick->Coord.X, ACS_LLCORNER | COLOR_PAIR(Brick->Color));

    for (int i = Brick->Coord.X + 1; i < Brick->Coord.X + Brick->Length - 1; i++)
    {
        mvwaddch(gameWin, Brick->Coord.Y, i, ACS_HLINE | COLOR_PAIR(Brick->Color));
        mvwaddch(gameWin, Brick->Coord.Y + Brick->Height - 1, i, ACS_HLINE | COLOR_PAIR(Brick->Color));
    }

    mvwaddch(gameWin, Brick->Coord.Y, Brick->Coord.X + Brick->Length - 1, ACS_URCORNER | COLOR_PAIR(Brick->Color));
    mvwaddch(gameWin, Brick->Coord.Y + Brick->Height - 1, Brick->Coord.X + Brick->Length - 1, ACS_LRCORNER | COLOR_PAIR(Brick->Color));

    attroff(A_BOLD);
    wrefresh(gameWin);
}
void DeleteBrick(struct BRICK *Brick)
{
    if (Brick->Visible == FALSE)
    {
        return;
    }

    attron(A_NORMAL);
    mvwaddch(gameWin, Brick->Coord.Y, Brick->Coord.X, ' ');
    mvwaddch(gameWin, Brick->Coord.Y + Brick->Height - 1, Brick->Coord.X, ' ');

    for (int i = Brick->Coord.X + 1; i < Brick->Coord.X + Brick->Length - 1; i++)
    {
        mvwaddch(gameWin, Brick->Coord.Y, i, ' ');
        mvwaddch(gameWin, Brick->Coord.Y + Brick->Height - 1, i, ' ');
    }

    mvwaddch(gameWin, Brick->Coord.Y, Brick->Coord.X + Brick->Length - 1, ' ');
    mvwaddch(gameWin, Brick->Coord.Y + Brick->Height - 1, Brick->Coord.X + Brick->Length - 1, ' ');

    attroff(A_NORMAL);
    wrefresh(gameWin);
}
void DrawAllBricks(struct BRICK **Bricks)
{
    for (int i = 0; i < Y_BRICKS_COUNT; i++)
    {
        for (int j = 0; j < X_BRICKS_COUNT; j++)
        {
            DrawBrick(&Bricks[i][j]);
        }
    }
}
void DeleteAllBricks(struct BRICK **Bricks)
{
    for (int i = 0; i < Y_BRICKS_COUNT; i++)
    {
        for (int j = 0; j < X_BRICKS_COUNT; j++)
        {
            DeleteBrick(&Bricks[i][j]);
        }
    }
}
int BricksLeft(struct BRICK **Bricks)
{
    int count = 0;

    for (int i = 0; i < Y_BRICKS_COUNT; i++)
    {
        for (int j = 0; j < X_BRICKS_COUNT; j++)
        {
            if (Bricks[i][j].Visible == TRUE)
            {
                count++;
            }
        }
    }

    return count;
}