#include "hangman.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define printLine() printf("-------------\n");

#define printGuessedWord()                               \
    for (int i = 0; guessedWord[i]; i++)                 \
    {                                                    \
        printf((i != 0) ? " %c" : "%c", guessedWord[i]); \
    }                                                    \
    printf("\n")

int get_word(char secret[])
{
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;
    do
    {

        long int random = (rand() % size) + 1;

        fseek(fp, random, SEEK_SET);

        int result = fscanf(fp, "%*s %20s", secret);
        if (result != EOF)
        {
            break;
        }
    } while (1);

    fclose(fp);
    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[])
{

    for (int i = 0; secret[i]; i++)
    {
        if (strchr(letters_guessed, secret[i]) == NULL)
        {
            return 0;
        }
    }
    return 1;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[])
{
    int i = 0;

    for (; secret[i]; i++)
    {
        guessed_word[i] = (strlen(letters_guessed) != 0 && strchr(letters_guessed, secret[i]) != NULL) ? secret[i] : '_';
    }

    guessed_word[i] = '\0';
}

void get_available_letters(const char letters_guessed[], char available_letters[])
{

    char lettersArray[] = "abcdefghijklmnopqrstuvwxyz";

    int j = 0;

    for (int i = 0; lettersArray[i]; i++)
    {
        if (strchr(letters_guessed, lettersArray[i]) == NULL)
        {
            available_letters[j++] = lettersArray[i];
        }
    }

    available_letters[j] = '\0';
}

void hangman(const char secret[])
{

    int attemptsNumber = 8;
    int index = 0;
    char guessedWord[50] = "", guessedLetters[50] = "", availableLetters[50] = "";
    char enteredCharacter[50];

    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", (int)strlen(secret));
    printLine();

    get_guessed_word(secret, guessedLetters, guessedWord);

    for (;;)
    {
        printf("You have %d guesses left.\n", attemptsNumber);

        get_available_letters(guessedLetters, availableLetters);

        printf("Available letters: %s\n", availableLetters);
        printf("Please guess a letter: ");
        scanf("%s", enteredCharacter);

        if (strpbrk("ABCDEFGHIJKLMNOPQRSTUVWXYZ", enteredCharacter) != NULL)
        {
            for (int i = 0; enteredCharacter[i]; i++)
            {
                enteredCharacter[i] = tolower(enteredCharacter[i]);
            }
        }

        if (strpbrk("abcdefghijklmnopqrstuvwxyz", enteredCharacter) == NULL)
        {

            printf("Oops! '%c' is not a valid letter: ", enteredCharacter[0]);
            printGuessedWord();
            printLine();
            continue;
        }

        if (strlen(enteredCharacter) != 1)
        {

            if (is_word_guessed(secret, enteredCharacter))
            {
                printf("Congratulations, you won!\n");
            }
            else
            {
                printf("Sorry, bad guess. The word was %s\n", secret);
            }
            strcpy(enteredCharacter, "");

            break;
        }
        else
        {
            if (strchr(guessedLetters, enteredCharacter[0]))
            {
                printf("Oops! You've already guessed that letter: ");
                printGuessedWord();
                printLine();
                continue;
            }

            guessedLetters[index++] = enteredCharacter[0];
            get_guessed_word(secret, guessedLetters, guessedWord);

            if (strchr(secret, guessedLetters[index - 1]))
            {

                printf("Good guess: ");
                printGuessedWord();

                if (strcmp(secret, guessedWord) == 0)
                {
                    printLine();
                    printf("Congratulations, you won!\n");
                    break;
                }
                printLine();
            }
            else
            {
                printf("Oops! That letter is not in my word: ");
                printGuessedWord();

                if (--attemptsNumber == 0)
                {
                    printLine();
                    printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
                    break;
                }

                printLine();
            }
        }
    }
}
