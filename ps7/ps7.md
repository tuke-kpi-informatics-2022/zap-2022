# Problem Set 7: Files

## Goals
- Command line argument handling was practiced.
- Work with files was explored.
- Specific constraints were addressed (when a simple problem is not so simple).

---

### [Task 1: Count Words](count_words.c)
A program was implemented to count how many times the sequence of characters "ananas" appears in the input file, regardless of case. The result is written back to the same file, overwriting its original content. Only the functions fopen(), fclose(), fgetc(), and fputc() were used for file operations.

### [Task 2: Every Second Word](every_second.c)
A program was created to write every second word from an input file to an output file, but only the words found between the words START and STOP (inclusive of boundaries). Words are separated by spaces. Case sensitivity is preserved. Only the functions fopen(), fclose(), fgetc(), and fputc() were used for file operations.

All assignment requirements were followed: no global variables, only allowed file functions, and the required project structure.

---

## How to Run

1. Ensure the files `count_words.c` and `every_second.c` are in the `ps7` directory.
2. Compile the programs using:
   
   ```sh
   gcc -std=c11 -Werror -Wall -lm ps7/count_words.c -o count_words
   gcc -std=c11 -Werror -Wall -lm ps7/every_second.c -o every_second
   ```
3. Run the programs as follows:
   - For counting words:
     ```sh
     ./count_words <input_output_file>
     ```
   - For every second word:
     ```sh
     ./every_second <input_file> <output_file>
     ```
4. Make sure all required files are in the correct directories and the programs compile without errors.

--- 