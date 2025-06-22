# Problem Set 3: Hangman

## Goals
- Custom functions were created according to specifications.
- Routine work with one-dimensional arrays and strings was practiced.
- Arrays were used as input and output parameters in functions.

---

### [Task 1: Is the Word Guessed?](hangman.c)
A function was implemented to check if the secret word has been guessed based on the guessed letters.

### [Task 2: Update Guessed Word](hangman.c)
A function was created to update the guessed word, showing correctly guessed letters and underscores for unknown letters.

### [Task 3: Update Available Letters](hangman.c)
A function was implemented to update the list of available letters, omitting those already guessed.

### [Task 4: Hangman Game](hangman.c)
A function was written to implement the interactive Hangman game, using the above functions and handling user input, guesses, and game logic.

All required functions were implemented in `hangman.c` and declared in `hangman.h`. The main program is in `main.c` and loads a random word using `get_word()` before starting the game.

All assignment requirements were followed: correct function signatures, use of arrays and strings, and the required project structure.

---

## How to Run

1. Ensure the files `hangman.c`, `hangman.h`, and `main.c` are in the `ps3` directory.
2. If a Makefile is present, compile the project using:
   
   ```sh
   make all
   ```
   Otherwise, compile manually with:
   ```sh
   gcc -std=c11 -Werror -Wall -lm ps3/main.c ps3/hangman.c -o hangman
   ```
3. Run the program:
   ```sh
   ./hangman
   ```
4. Make sure all required files are in the correct directories and the program compiles without errors.

---