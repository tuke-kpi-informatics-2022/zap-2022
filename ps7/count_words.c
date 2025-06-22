#include <stdio.h>

#define bool int
#define false 0
#define true 1

#define SeachWord "ananas"
#define SeachWordSize 6

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

char ChangeCaseFromUpper(char symbol)
{
    if (symbol >= 65 && symbol <= 90)
    {
        symbol += 32;
    }
    return symbol;
}

void MyFunction(const char *const FileName)
{
    FILE *TxtFile = fopen(FileName, "r");
    if (!TxtFile)
    {
        return;
    }

    char ReadBuffer[SeachWordSize] = "";
    char readSymbol = ' ';
    char WriteBuffer[SeachWordSize] = "";
    int countSeachWord = 0;
    int FirstWordRead = 0;
    int NumberSize = 0;

    while ((readSymbol = (char)fgetc((FILE *)TxtFile)) != EOF)
    {
        readSymbol = ChangeCaseFromUpper(readSymbol);

        if (FirstWordRead < SeachWordSize)
        {
            ReadBuffer[FirstWordRead++] = (char)readSymbol;
            continue;
        }
        else
        {
            for (int i = 0; i < SeachWordSize - 1; i++)
            {
                ReadBuffer[i] = (char)ReadBuffer[i + 1];
            }
            ReadBuffer[SeachWordSize - 1] = (char)readSymbol;
            countSeachWord += StringCompare(ReadBuffer, SeachWord);
        }
    }

    fclose(TxtFile);

    TxtFile = fopen(FileName, "w");

    if (countSeachWord < 9)
    {
        fputc((int)(countSeachWord + (int)'0'), (FILE *)TxtFile);
    }
    else
    {
        for (NumberSize = 0; countSeachWord; countSeachWord /= 10, NumberSize++)
        {
            WriteBuffer[NumberSize] = (char)(countSeachWord % 10 + (int)'0');
        }
        for (int i = NumberSize - 1; i >= 0; i--)
        {
            fputc((int)WriteBuffer[i], (FILE *)TxtFile);
        }
    }

    fclose(TxtFile);
}

int main(int argc, char const **argv)
{
    if (argc > 1)
    {
        MyFunction(argv[1]);
    }
    else
    {
        return -1;
    }

    return 0;
}
