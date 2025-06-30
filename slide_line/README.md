# slide_line

A C function to simulate sliding and merging of an integer array, similar to the 2048 game mechanics.

## Description

This project implements a function that slides and merges an array of integers left or right, following rules similar to the 2048 game. It is designed as a technical interview practice exercise.

## File Structure

- `slide_line.c` - Contains the main logic for sliding and merging.
- `slide_line.h` - Header file with function prototypes.
- `main.c` - Example usage and test cases.

## Usage

Compile with:

```sh
gcc -Wall -Werror -Wextra -pedantic main.c slide_line.c -o slide_line
```

Run:

```sh
./slide_line
```

## Function Prototype

```c
int slide_line(int *line, size_t size, int direction);
```

- `line`: Array of integers.
- `size`: Number of elements in the array.
- `direction`: `SLIDE_LEFT` or `SLIDE_RIGHT`.

## Example

```c
int array[5] = {2, 2, 0, 4, 4};
slide_line(array, 5, SLIDE_LEFT);
// array becomes {4, 8, 0, 0, 0}
```
