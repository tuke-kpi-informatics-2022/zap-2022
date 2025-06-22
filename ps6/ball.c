#include "ball.h"

/* Ball functions */
void DirectionBallX(struct BALL *const Ball, DirectionX Direction)
{
    Ball->DirX = (DirectionX)Direction;
}
void DirectionBallY(struct BALL *const Ball, DirectionY Direction)
{
    // Don't let us keep bouncing in a loop forever up and down.
    if (Direction == (DirectionY)DOWN && Ball->DirX == (DirectionX)X_NEUTRAL)
    {
        Ball->DirX = rand() & 1;
    }
    Ball->DirY = Direction;
}
void DrawBall(struct BALL *Ball)
{
    attron(A_BOLD);
    mvwaddch(gameWin, Ball->Coord.Y, Ball->Coord.X, Ball->Symbol | COLOR_PAIR(Ball->Color));
    attroff(A_BOLD);
    wrefresh(gameWin);
}
void DeleteBall(struct BALL *Ball)
{
    attron(A_NORMAL);
    mvwaddch(gameWin, Ball->Coord.Y, Ball->Coord.X, ' ');
    attroff(A_NORMAL);
    wrefresh(gameWin);
}
void ResetBall(struct BALL *Ball, int PosX, int PosY, int Symbol, COLOR Color)
{
    Ball->Coord.X = PosX;
    Ball->Coord.Y = PosY;
    Ball->DirX = X_NEUTRAL;
    Ball->DirY = DOWN;
    Ball->Symbol = (int)Symbol;
    Ball->Color = (COLOR)Color;
}
void MoveBall(struct BALL *Ball)
{
    DeleteBall(Ball);

    if (Ball->Coord.X <= 1)
    {
        DirectionBallX(Ball, RIGHT);
    }
    else if (Ball->Coord.X >= gameWin_xsize - 2)
    {
        DirectionBallX(Ball, LEFT);
    }

    if (Ball->DirX == (DirectionX)RIGHT)
    {
        (Ball->Coord.X) = (Ball->Coord.X <= gameWin_xsize - BORDER_WIDHT) ? Ball->Coord.X + BORDER_WIDHT : gameWin_xsize - BORDER_WIDHT;
    }
    else if (Ball->DirX == (DirectionX)LEFT)
    {
        (Ball->Coord.X) = (Ball->Coord.X > BORDER_WIDHT) ? Ball->Coord.X - BORDER_WIDHT : BORDER_WIDHT;
    }

    if (Ball->DirY == (DirectionY)DOWN)
    {
        (Ball->Coord.Y) = ((Ball->Coord.Y <= gameWin_ysize - BORDER_WIDHT) ? Ball->Coord.Y + BORDER_WIDHT : gameWin_ysize - BORDER_WIDHT);
    }
    else if (Ball->DirY == (DirectionY)UP)
    {
        (Ball->Coord.Y) = ((Ball->Coord.Y > BORDER_WIDHT) ? (Ball->Coord.Y) - BORDER_WIDHT : BORDER_WIDHT);
    }

    DrawBall(Ball);
}

bool CheckPaddleHitBall(struct BALL *Ball, struct PADDLE *Paddle)
{
    return (Ball->Coord.X >= Paddle->Coord.X && Ball->Coord.X <= (Paddle->Coord.X + Paddle->Length));
}

int BallHitBrick(struct BALL *Ball, struct BRICK **Bricks)
{
    int HitBricksNumber = 0;
    for (int i = 0; i < Y_BRICKS_COUNT; i++)
    {
        for (int j = 0; j < X_BRICKS_COUNT; j++)
        {
            if (Bricks[i][j].Visible == TRUE &&
                Ball->Coord.X >= Bricks[i][j].Coord.X - 1 && Ball->Coord.X <= Bricks[i][j].Coord.X + Bricks[i][j].Length &&
                Ball->Coord.Y >= Bricks[i][j].Coord.Y - 1 && Ball->Coord.Y <= Bricks[i][j].Coord.Y + Bricks[i][j].Height)
            {
                if (Ball->Coord.Y == Bricks[i][j].Coord.Y - 1)
                {
                    DirectionBallY(Ball, UP);
                }
                else if (Ball->Coord.Y == Bricks[i][j].Coord.Y + (Bricks[i][j].Height - 1) + 1)
                {
                    DirectionBallY(Ball, DOWN);
                }

                if (Ball->Coord.X == Bricks[i][j].Coord.X - 1)
                {
                    DirectionBallX(Ball, LEFT);
                }
                else if (Ball->Coord.X == Bricks[i][j].Coord.X + (Bricks[i][j].Length - 1) + 1)
                {
                    DirectionBallX(Ball, RIGHT);
                }

                HitBricksNumber++;
                DeleteBrick(&Bricks[i][j]);
                Bricks[i][j].Visible = FALSE;
            }
        }
    }
    return HitBricksNumber;
}
