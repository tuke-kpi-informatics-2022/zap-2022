# Problem Set 2: Numbers, Arrays

## Goals
- Practice using the math library and arithmetic expressions.
- Understand the representation of numbers in computer memory.
- Create custom functions according to specifications.
- Learn to terminate functions with different return values for different input parameters.

---

### [Task 1: Lift a Car](arrays.c)
A function was implemented to calculate the position where a stick must be supported to lift a car using only human weight. The result is rounded to two decimal places.

### [Task 2: Unit Price for Toilet Paper](arrays.c)
A function was created to compute the unit price per 100 pieces of toilet paper, given the pack price, number of rolls, and pieces per roll. The result is rounded to two decimal places.

### [Task 3: Collatz Conjecture](arrays.c)
A function was implemented to compute the length of the Collatz sequence for a given positive integer.

### [Task 4: Find Opposite Number](arrays.c)
A function was written to find the number opposite a given number on a circle of numbers from 0 to n-1.

### [Task 5: Count Numbers in Array](arrays.c)
A function was implemented to sum values at even and odd positions in an array and store the results in a result array.

### [Task 6: Pascal's Triangle](arrays.c)
A function was created to calculate the sum of the squares of all coefficients in a given row of Pascal's triangle.

### [Task 7: Min-and-Max Price](arrays.c)
Functions were implemented to find the minimum and maximum values in an array. If the input array is NULL, -1 is returned.

### [Task 8: Special Counter](arrays.c)
A function was written to sum all elements in an array, raising those at odd positions to the power of two before summing.

### [Task 9: Special Numbers](arrays.c)
A function was implemented to find all special numbers in an array (numbers greater than the sum of all numbers to their right) and store them in a result array.

All assignment requirements were followed: no global variables, correct function signatures, and the required project structure.

---

## How to Run

1. Make sure the file `arrays.c` is in the `ps2` directory.
2. Compile the code using:
   
   ```sh
   gcc -std=c11 -Werror -Wall -lm ps2/arrays.c -o arrays
   ```
3. Run the program (if a main function is present) or use the compiled file for testing the implemented functions.
4. Ensure the program contains no global variables and compiles without errors.

---