# Problem Set 5: QR Code

## Goals
- The representation of numbers in computer memory was explored.
- Work with two-dimensional arrays was practiced.
- Custom functions were created according to specifications.
- Functions were terminated with different return values for different input parameters.

---

### [Task 1: (De)Coding a Character](qr.c)
Functions were implemented to encode a character into an array of 8 bits (as bool values) and to decode an array of 8 bits back into a character using ASCII values.

### [Task 2: (De)Coding a String](qr.c)
Functions were created to encode a string (including the null terminator) into a two-dimensional array of bytes (8 bits per character) and to decode such an array back into a string.

### [Task 3: (De)Coding Blocks](qr.c)
Functions were implemented to convert a two-dimensional array of bytes into a block structure (for QR code representation) and to convert blocks back into bytes. The data is stored vertically in blocks, and extra space is filled with zeros if needed.

All required functions were implemented in `qr.c` according to the assignment. No global variables were used, and all function signatures were followed.

---

## How to Run

1. Ensure the file `qr.c` is in the `ps5` directory.
2. Compile the code using:
   
   ```sh
   gcc -std=c11 -Werror -Wall -lm ps5/qr.c -o qr
   ```
3. Run the program (if a main function is present) or use the compiled file for testing the implemented functions.
4. Make sure the program contains no global variables and compiles without errors.

---