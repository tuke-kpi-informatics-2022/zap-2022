# Problem Set 1: Karel the Robot

In this project, several tasks with Karel the Robot were solved, focusing on algorithmic thinking and programming without variables. Each task is implemented in a separate file as required.

---

### [Task 1: Orienteering Run](task_1.c)
Karel was programmed to cross obstacles, find a marker, pick it up, and return to the starting position. No variables were used.

### [Task 2: Treasure in the Tunnel](task_2.c)
A solution was created where Karel searches for a treasure in a spiral-shaped tunnel. After finding the marker, Karel returns to the starting position.

### [Task 3: Cleaning the Wardrobe](task_3.c)
Karel was made to sort the markers (representing clothes) in the wardrobe from longest to shortest, right to left, and return to the original position.

### [Task 4: Repairing Krásna Hôrka](task_4.c)
Karel was programmed to repair columns by filling missing markers and move to the southeast corner at the end.

### [Task 5: Framing the Picture](task_5.c)
Karel was instructed to mark all four edges of the world and finish in the center.

### [Task 6: Treasure on the Map](task_6.c)
A program was written where Karel follows clues (numbers on markers), changes direction accordingly, and collects markers until the treasure is found.

### [Task 7: Warehouse](task_7.c)
Karel was programmed to check warehouse spaces and mark those that are not safe (with more than one entrance).

All assignment requirements were followed: no variables, correct map names in the `turn_on()` function, and the required project structure.

---

## How to Run

1. First, download the Karel library from [https://git.kpi.fei.tuke.sk/kpi/karel-the-robot](https://git.kpi.fei.tuke.sk/kpi/karel-the-robot) and install it as described in the repository.

2. Create a map file for each task. For example, for Task 1, create a file named `task_1.kw` with the required map content (you can use a text editor to create or edit this file).

3. Compile each task using:
   
   ```sh
   gcc -std=c11 -Werror -Wall -lsuperkarel -lcurses task_X.c -o task_X
   ```
   (replace `task_X.c` with the specific file, e.g., `task_1.c`)

4. Run the program with the corresponding map file. For example, for Task 1:
   
   ```sh
   ./task_1
   ```
   Make sure that the map file (e.g., `task_1.kw`) is in the same directory as the compiled program.

5. Ensure the program contains no variables and compiles without errors.

---
