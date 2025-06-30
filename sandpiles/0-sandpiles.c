#include "sandpiles.h"

/**
 * is_stable - Checks if a sandpile grid is stable
 * @grid: 3x3 sandpile grid to check
 *
 * Return: 1 if stable (all cells <= 3), 0 if unstable
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}
/**
 * print_grid - Prints a 3x3 sandpile grid
 * @grid: 3x3 grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - Performs a single toppling round on a sandpile grid
 * @grid1: 3x3 grid to topple (modified in-place)
 */
static void topple(int grid1[3][3])
{
	int i, j;
	int temp[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
				{
					temp[i - 1][j] += 1;
				}
				if (i < 2)
				{
					temp[i + 1][j] += 1;
				}
				if (j > 0)
				{
					temp[i][j - 1] += 1;
				}
				if (j < 2)
				{
					temp[i][j + 1] += 1;
				}
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += temp[i][j];
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First sandpile (will be updated in-place)
 * @grid2: Second sandpile
 *
 * Adds grid2 to grid1, then repeatedly topples until grid1 is stable.
 * Prints grid1 before each toppling round if unstable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Topple until stable */
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}