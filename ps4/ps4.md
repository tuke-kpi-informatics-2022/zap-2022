# Problem Set 4: Ball Sort Puzzle

## Goals
- Custom functions were created according to specifications.
- Routine work with two-dimensional arrays and strings was practiced.
- Arrays were used as input and output parameters in functions.
- A random number generator was used.

---

### [Task 1: Field Generation](ballsortpuzzle.c)
A function was implemented to randomly generate a two-dimensional game field with the required properties (two empty columns, each symbol appears exactly as many times as the number of rows, etc.).

### [Task 2: Move Characters in the Field](ballsortpuzzle.c)
A function was created to move a character from one column to another, ensuring the move is valid and the character is placed at the lowest possible position.

### [Task 3: Check Column Arrangement](ballsortpuzzle.c)
A function was implemented to check if all columns are filled with the same character (win condition).

### [Task 4: Game Field Rendering](ballsortpuzzle.c)
A function was written to render the game field in the terminal. Creativity in display is encouraged.

### [Task 5: Ball Sort Puzzle Game](ballsortpuzzle.c)
A function was implemented to control the entire game, using the above functions for field generation, moves, checking, and rendering. User interaction and win detection were handled.

All required functions were implemented in `ballsortpuzzle.c` and declared in `ballsortpuzzle.h`. The main program is in `main.c`.

All assignment requirements were followed: correct function signatures, use of arrays and strings, random generation, and the required project structure. Screenshots for tasks 4 and 5 were provided as `task_4.png` and `task_5.png`.

---

## How to Run

1. Ensure the files `ballsortpuzzle.c`, `ballsortpuzzle.h`, and `main.c` are in the `ps4` directory. Screenshots for tasks 4 and 5 should be named `task_4.png` and `task_5.png`.
2. If a Makefile is present, compile the project using:
   
   ```sh
   make all
   ```
   Otherwise, compile manually with:
   ```sh
   gcc -std=c11 -Werror -Wall -Wno-vla-parameter ps4/main.c ps4/ballsortpuzzle.c -o ballsortpuzzle
   ```
3. Run the program:
   ```sh
   ./ballsortpuzzle
   ```
4. Make sure all required files are in the correct directories and the program compiles without errors.

--- 