#include "hangman.h"

int main()
{
    char secretWord[30];

    get_word(secretWord);
    hangman(secretWord);

    return 0;
}