#include "paddle.h"

/* Paddle functions*/
void ResetPaddle(struct PADDLE *Paddle, int PaddleLength, int PaddleHeight, int Symbol, COLOR Color)
{
    Paddle->Length = PaddleLength;
    Paddle->Height = PaddleHeight;
    Paddle->Symbol = (int)Symbol;
    Paddle->Color = (COLOR)Color;
    Paddle->IsMoved = FALSE;
    Paddle->DirX = (DirectionX)X_NEUTRAL;
    /*Standart start Coord is center of screen*/
    Paddle->Coord.X = ((gameWin_xsize - 2 * BORDER_WIDHT) - PaddleLength) / 2;
    Paddle->Coord.Y = gameWin_ysize - BORDER_WIDHT - PaddleHeight;
}
void DrawPaddle(struct PADDLE *Paddle)
{
    attron(A_BOLD);
    for (int i = Paddle->Coord.X; i < Paddle->Coord.X + Paddle->Length; i++)
    {
        mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, i, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
    }
    attroff(A_BOLD);
    wrefresh(gameWin);
}
void DeletePaddle(struct PADDLE *Paddle)
{
    attron(A_NORMAL);
    for (int i = Paddle->Coord.X; i < Paddle->Coord.X + Paddle->Length; i++)
    {
        mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, i, ' ');
    }
    attroff(A_NORMAL);
    wrefresh(gameWin);
}
void MovePaddle(struct PADDLE *Paddle)
{
    if (Paddle->DirX == LEFT)
    {
        if (Paddle->Coord.X > BORDER_WIDHT + 2)
        {
            Paddle->Coord.X -= 3;
            attron(A_NORMAL);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length, ' ');
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length + 1, ' ');
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length + 2, ' ');
            attroff(A_NORMAL);
            attron(A_BOLD);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + 2, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + 1, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            attroff(A_BOLD);
        }
        else if (Paddle->Coord.X > BORDER_WIDHT)
        {
            Paddle->Coord.X -= 1;
            attron(A_NORMAL);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length, ' ');
            attroff(A_NORMAL);
            attron(A_BOLD);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            attroff(A_BOLD);
        }
    }
    if (Paddle->DirX == RIGHT)
    {
        if (Paddle->Coord.X + Paddle->Length < gameWin_xsize - BORDER_WIDHT - 2)
        {
            Paddle->Coord.X += 3;
            attron(A_NORMAL);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X - 3, ' ');
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X - 2, ' ');
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X - 1, ' ');
            attroff(A_NORMAL);
            attron(A_BOLD);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length - 3, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length - 2, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length - 1, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            attroff(A_BOLD);
        }
        else if (Paddle->Coord.X + Paddle->Length < gameWin_xsize - BORDER_WIDHT)
        {
            Paddle->Coord.X += 1;
            attron(A_NORMAL);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X - 1, ' ');
            attroff(A_NORMAL);
            attron(A_BOLD);
            mvwaddch(gameWin, gameWin_ysize - BORDER_WIDHT - Paddle->Height, Paddle->Coord.X + Paddle->Length - 1, Paddle->Symbol | COLOR_PAIR(Paddle->Color));
            attroff(A_BOLD);
        }
    }
    wrefresh(gameWin);
}