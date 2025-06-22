# Problem Set 6: Curses

## Goals
- The ncurses ASCII-graphics library was explored.
- Creativity was demonstrated in the project.
- Documentation for the assignment was created.

---

## Project Overview
A game was developed using the ncurses library, featuring a 2D world and multiple advanced features. The project goes beyond basic examples and demonstrates a sufficient level of complexity.

### Features Implemented
- 2D world with interactive gameplay.
- Use of colors for enhanced visual experience.
- Keyboard controls without the need for Enter confirmation.
- Multiple levels (level files such as `Rookie.lvl`, `Hurricane.lvl`, `Underdog.lvl`).
- Timer and time-based events.
- Command line arguments for level selection.
- File operations for loading and saving levels.

### Game Description
The game is an arcade-style brick breaker, where the player controls a paddle to bounce a ball and break bricks. The game includes several levels of increasing difficulty, power-ups, and a scoring system. The player must prevent the ball from falling below the paddle while clearing all bricks to advance to the next level. The game uses ncurses for rendering, color effects, and real-time keyboard input.

For a detailed description of the game mechanics, features, and implementation, see the [documentation.pdf](documentation.pdf) included in the `ps6` directory.

---

## How to Run

1. Ensure all source files and `documentation.pdf` are in the `ps6` directory.
2. Compile the program using the provided Makefile:
   
   ```sh
   make all
   ```
   or manually with:
   ```sh
   gcc -std=c11 -Werror -Wall -lncurses ps6/*.c -o game
   ```
3. Run the program:
   ```sh
   ./game
   ```
   Command line arguments can be used to select levels or enable additional features (see documentation).
4. Make sure all required files are in the correct directories and the program compiles without errors.

---

## Documentation
A comprehensive documentation is provided in [documentation.pdf](documentation.pdf), which includes:
- Assignment statement
- Solution design and approach
- Instructions for use and example scenarios
- Conclusion, limitations, and possible extensions

--- 