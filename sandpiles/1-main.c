#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int grid1[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        };
    int grid2[3][3] = {
            {3, 3, 3},
            {3, 3, 3},
            {3, 3, 3}
        };
    print_grid_sum(grid1, grid2);

    sandpiles_sum(grid1, grid2);

    printf("=\n");
    print_grid(grid1);

    return (EXIT_SUCCESS);
}