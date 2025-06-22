#include "game.h"

void DrawMessage(char *msg, COLOR Color)
{
    wattron(gameWin, COLOR_PAIR(Color));
    mvwaddstr(gameWin, gameWin_ysize / 2 + 3, (gameWin_xsize - strlen(msg)) / 2, msg);
    wattroff(gameWin, COLOR_PAIR(Color));
    wrefresh(gameWin);
}
bool WaitForUserStartGame(void)
{
    DrawMessage("Hit Space to launch.", WHITE);

    int ch;
    while ((ch = getch()) != ' ' && ch != 27)
    {
    }

    DrawMessage("                    ", WHITE);
    return (ch == 27) ? FALSE : TRUE;
}
bool WaitForUserExitGame(void)
{
    DrawMessage("Really quit from game ? (y/n)", WHITE);

    int ch;
    while ((ch = getch()) != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
    {
    }

    DrawMessage("                             ", WHITE);
    return (ch == 'y' || ch == 'Y') ? TRUE : FALSE;
}
bool WaitForUserLostGame(void)
{
    DrawMessage("YOU LOST! restart all levels ? (y/n)", RED);

    int ch;
    while ((ch = getch()) != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
    {
    }

    DrawMessage("                                    ", RED);
    return (ch == 'y' || ch == 'Y') ? TRUE : FALSE;
}
bool WaitForUserNextGame(int CurrentLevel, int LevelCount)
{
    int ch;
    if (CurrentLevel == LevelCount)
    {
        DrawMessage("YOU WIN ALL LEVELS! Hit Space to quit", YELLOW);
        while ((ch = getch()) != ' ')
        {
        }

        DrawMessage("                                     ", YELLOW);
        return FALSE;
    }
    else
    {
        DrawMessage("YOU WIN! Launch next level ? (y/n)", YELLOW);
        while ((ch = getch()) != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
        {
        }

        DrawMessage("                                  ", YELLOW);
        return (ch == 'y' || ch == 'Y') ? TRUE : FALSE;
    }
}

char ***CreateLevelFromFile(const char *FileName, int *LevelCount)
{
    FILE *TxtLevel = fopen(FileName, "r");
    char *buffer;

    if (TxtLevel)
    {
        if (fseek(TxtLevel, 0, SEEK_END) != 0)
        {
            fclose(TxtLevel);
            endwin();
            printf("Error: The file is empty\n");
            exit(-1);
        }

        int file_size = ftell(TxtLevel);
        buffer = (char *)malloc(file_size);
        rewind(TxtLevel);
        fread(buffer, sizeof(char), file_size, TxtLevel);
        fclose(TxtLevel);
    }
    else
    {
        endwin();
        printf("Error: There was a problem reading the file\n");
        exit(-1);
    }
    if (buffer == NULL)
    {
        endwin();
        printf("Error: There was a problem with buffer\n");
        exit(-1);
    }

    int iterator = 0;
    while (buffer[iterator] != '%')
    {
        if (buffer[iterator] == '*')
        {
            while (buffer[iterator++] != '\n')
                ;
        }
        else
        {
            (*LevelCount)++;
            while (buffer[iterator++] != '\n')
                ;
        }
    }
    (*LevelCount) /= Y_BRICKS_COUNT;

    char ***array = (char ***)calloc((*LevelCount), sizeof(char **));
    for (int i = 0; i < (*LevelCount); i++)
    {
        array[i] = (char **)calloc(Y_BRICKS_COUNT, sizeof(char *));
        for (int j = 0; j < Y_BRICKS_COUNT; j++)
        {
            array[i][j] = (char *)calloc(X_BRICKS_COUNT, sizeof(char));
        }
    }

    iterator = 0;
    int k = 0;

    while ((buffer[iterator]) != '%' && k < (*LevelCount))
    {
        if (buffer[iterator] == '*')
        {
            while (buffer[iterator++] != '\n')
            {
            }
        }
        else
        {
            for (int i = 0; i < Y_BRICKS_COUNT; i++)
            {
                for (int j = 0; j < X_BRICKS_COUNT; j++)
                {
                    array[k][i][j] = buffer[iterator++];
                }
                iterator++;
            }
            k++;
        }
    }
    return array;
}
void DeleteLevelMarixArray(char ***array, int *LevelCount)
{
    for (int i = 0; i < (*LevelCount); i++)
    {
        for (int j = 0; j < Y_BRICKS_COUNT; j++)
        {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
    array = NULL;
}
void UpdateGameStats(int CurrentScore, int CurrentLives, int CurrentLevel)
{
    mvwaddstr(gameBarWin, 1, 2, "Lives:             ");
    wattron(gameBarWin, COLOR_PAIR(RED));
    for (int i = 0; i < CurrentLives; i++)
    {
        mvwaddch(gameBarWin, 1, 2 + strlen("Lives: ") + i * 2, ACS_DIAMOND);
    }
    wattroff(gameBarWin, COLOR_PAIR(RED));
    mvwprintw(gameBarWin, 1, (gameWin_xsize - 7) / 2, "Level            ");
    mvwprintw(gameBarWin, 1, (gameWin_xsize - 7) / 2, "Level %d", CurrentLevel);
    mvwprintw(gameBarWin, 1, (gameWin_xsize - strlen("Score: ")) - 6, "Score:      ");
    mvwprintw(gameBarWin, 1, (gameWin_xsize - strlen("Score: ")) - 6, "Score: %d", CurrentScore);
    wrefresh(gameBarWin);
}
void GameLoop(struct BALL *const Ball, struct PADDLE *Paddle, char ***Levels, int LevelCount)
{
    int ch, CurrentLevel = 0, CurrentLives = 3, CurrentScore = 0;
    struct BRICK **Bricks = CreateBricksMatrix(Levels[CurrentLevel], BRICKS_LEGHT, BRICKS_HEIGHT);
    DrawAllBricks(Bricks);
    DrawBall(Ball);
    DrawPaddle(Paddle);
    UpdateGameStats(CurrentScore, CurrentLives, CurrentLevel + 1);

    if (WaitForUserStartGame())
    {
        for (;;)
        {
            ch = getch();
            if (ch != ERR)
            {

                if (ch == 27 && WaitForUserExitGame())
                {
                    break;
                }
                switch (ch)
                {
                case KEY_LEFT:
                    Paddle->IsMoved = TRUE;
                    Paddle->DirX = (DirectionX)LEFT;
                    MovePaddle(Paddle);
                    break;
                case KEY_RIGHT:
                    Paddle->IsMoved = TRUE;
                    Paddle->DirX = (DirectionX)RIGHT;
                    MovePaddle(Paddle);
                    break;
                }
                flushinp();
            }

            if (Ball->Coord.Y == 1)
            {
                DirectionBallY(Ball, DOWN);
            }
            else if (Ball->Coord.Y >= Paddle->Coord.Y - 1 && CheckPaddleHitBall(Ball, Paddle))
            {
                DirectionBallY(Ball, UP);
                if (Paddle->IsMoved)
                {
                    DirectionBallX(Ball, Paddle->DirX);
                }
                else
                {
                    if (Ball->Coord.X <= Paddle->Coord.X + (Paddle->Length / 3))
                    {
                        DirectionBallX(Ball, LEFT);
                    }
                    else if (Ball->Coord.X > Paddle->Coord.X + (Paddle->Length / 3) && Ball->Coord.X <= Paddle->Coord.X + (Paddle->Length / 3) + (Paddle->Length / 3)) // ���� ���������� � �����
                    {
                        if (rand() & 1)
                        {
                            DirectionBallX(Ball, X_NEUTRAL);
                        }
                    }
                    else
                    {
                        DirectionBallX(Ball, RIGHT);
                    }
                }
            }
            Paddle->IsMoved = FALSE;

            if (!CheckPaddleHitBall(Ball, Paddle) && Ball->Coord.Y >= Paddle->Coord.Y - 1)
            {
                CurrentLives--;
                UpdateGameStats(CurrentScore, CurrentLives, CurrentLevel + 1);
                if (CurrentLives <= 0)
                {
                    if (!WaitForUserLostGame())
                    {
                        break;
                    }
                    else
                    {
                        CurrentLives = 3;
                        CurrentScore = 0;
                        CurrentLevel = 0;
                        DeleteBall(Ball);
                        DeletePaddle(Paddle);
                        DeleteAllBricks(Bricks);
                        ResetBall(Ball, gameWin_xsize / 2, gameWin_ysize - 5, Ball->Symbol, Ball->Color);
                        ResetPaddle(Paddle, Paddle->Length, Paddle->Height, Paddle->Symbol, Paddle->Color);
                        DeleteBricksMatrix(Bricks);
                        Bricks = CreateBricksMatrix(Levels[CurrentLevel], BRICKS_LEGHT, BRICKS_HEIGHT);
                        DrawAllBricks(Bricks);
                        DrawBall(Ball);
                        DrawPaddle(Paddle);
                        UpdateGameStats(CurrentScore, CurrentLives, CurrentLevel + 1);
                        WaitForUserStartGame();
                        continue;
                    }
                }
                DeleteBall(Ball);
                DeletePaddle(Paddle);
                ResetBall(Ball, gameWin_xsize / 2, gameWin_ysize - 5, Ball->Symbol, Ball->Color);
                ResetPaddle(Paddle, Paddle->Length, Paddle->Height, Paddle->Symbol, Paddle->Color);
                DrawBall(Ball);
                DrawPaddle(Paddle);
                WaitForUserStartGame();
            }

            int tmp = CurrentScore;
            CurrentScore += BallHitBrick(Ball, Bricks) * 100;
            if (tmp != CurrentScore)
            {
                UpdateGameStats(CurrentScore, CurrentLives, CurrentLevel + 1);
            }

            if (BricksLeft(Bricks) == 0)
            {
                if (WaitForUserNextGame(CurrentLevel + 1, LevelCount))
                {
                    DeleteBall(Ball);
                    DeletePaddle(Paddle);
                    DeleteAllBricks(Bricks);
                    ResetBall(Ball, gameWin_xsize / 2, gameWin_ysize - 5, Ball->Symbol, Ball->Color);
                    ResetPaddle(Paddle, Paddle->Length, Paddle->Height, Paddle->Symbol, Paddle->Color);
                    DeleteBricksMatrix(Bricks);

                    Bricks = CreateBricksMatrix(Levels[++CurrentLevel], BRICKS_LEGHT, BRICKS_HEIGHT);
                    DrawAllBricks(Bricks);
                    DrawBall(Ball);
                    DrawPaddle(Paddle);
                    CurrentScore += 1000;
                    UpdateGameStats(CurrentScore, CurrentLives, CurrentLevel + 1);
                }
                else
                {
                    break;
                }
            }
            MoveBall(Ball);
            // 90 easy
            // 70 normal
            // 50 hard
            napms((LevelDifficult == EASY) ? 90 : (LevelDifficult == NORMAL) ? 70
                                                                             : 50);
        }
    }
    DeleteBricksMatrix(Bricks);
}
void StartLevels(const char *FileName)
{
    /* Draw windows*/
    gameWin = newwin(gameWin_ysize, gameWin_xsize, term_yMin, term_xMin);
    gameBarWin = newwin(gameBarWin_ysize, gameBarWin_xsize, term_yMin + gameWin_ysize, term_xMin);
    box(gameWin, 0, 0);
    box(gameBarWin, 0, 0);
    mvwprintw(gameWin, 0, 3, "[ARKANOID by ANDREW]");
    wrefresh(gameWin);
    wrefresh(gameBarWin);
    refresh();
    /*Start initialization*/
    struct BALL Ball;
    ResetBall(&Ball, gameWin_xsize / 2, gameWin_ysize - 5, (int)'*', WHITE);
    struct PADDLE Paddle;
    ResetPaddle(&Paddle, 16, 1, ACS_CKBOARD, BLACK);
    int LevelCount = 0;
    char ***Levels = CreateLevelFromFile(FileName, &LevelCount);
    GameLoop(&Ball, &Paddle, Levels, LevelCount);
    DeleteLevelMarixArray(Levels, &LevelCount);
}