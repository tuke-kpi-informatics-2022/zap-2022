#include <stdio.h>

#define bool int
#define false 0
#define true 1

#define StartWord "START"
#define StopWord " STOP"
#define WordsSize 6

bool StringCompare(const char *stringForComparison, char *seachWord)
{
    for (int i = 0; *seachWord;)
    {
        if (*(stringForComparison + (i++)) != *seachWord++)
        {
            return false;
        }
    }
    return true;
}

void MyFunction(const char *const FileNameToRead, const char *const FileNameToWrite)
{
    FILE *TxtFileRead = fopen(FileNameToRead, "r");
    FILE *TxtFileWrite = fopen(FileNameToWrite, "w");

    if (!TxtFileRead)
    {
        return;
    }

    char ReadBuffer[WordsSize] = "";
    char readSymbol = ' ';
    char WriteBuffer[1000] = "";
    int FirstWordRead = 0;
    int iterator = 0;
    bool CanWrite = false;
    bool SecondWord = false;
    bool first = true;

    while ((readSymbol = (char)fgetc((FILE *)TxtFileRead)) != EOF)
    {
        if (FirstWordRead < WordsSize)
        {
            ReadBuffer[FirstWordRead++] = (char)readSymbol;
            continue;
        }

        if (!CanWrite)
        {
            CanWrite = StringCompare(ReadBuffer, StartWord);
        }

        for (int i = 0; i < WordsSize - 1; i++)
        {
            ReadBuffer[i] = (char)ReadBuffer[i + 1];
        }

        ReadBuffer[WordsSize - 1] = (char)readSymbol;

        if (!CanWrite)
        {
            continue;
        }

        if (StringCompare(ReadBuffer, StopWord))
        {
            break;
        }

        if (readSymbol == ' ')
        {
            if (SecondWord)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    fputc(' ', TxtFileWrite);
                }
                for (int i = 0; i < iterator; i++)
                {
                    fputc(WriteBuffer[i], TxtFileWrite);
                }
                SecondWord = false;
            }
            else
            {
                SecondWord = true;
            }
            iterator = 0;
            continue;
        }

        WriteBuffer[iterator++] = readSymbol;
    }

    fclose(TxtFileRead);
    fclose(TxtFileWrite);
}

int main(int argc, char const **argv)
{
    if (argc > 2)
    {
        MyFunction(argv[1], argv[2]);
    }
    else
    {
        return -1;
    }
    return 0;
}
