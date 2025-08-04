#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array
 * @array: The array containing the integers
 * @size: Size of the array
 * @a: Index of first integer
 * @b: Index of second integer
 */
void swap(int *array, size_t size, size_t a, size_t b)
{
	int temp;

	if (a != b)
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * sift_down - Maintains heap property by sifting down
 * @array: The array to sift down
 * @size: Size of the array
 * @start: Starting index
 * @end: Ending index
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root, child, swap_idx;

	root = start;
	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap_idx = root;

		/* Find the largest among root and its children */
		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		/* If root is already the largest, heap property is satisfied */
		if (swap_idx == root)
			return;

		/* Swap and continue sifting down */
		swap(array, size, root, swap_idx);
		root = swap_idx;
	}
}

/**
 * heapify - Builds a max heap from an array
 * @array: The array to heapify
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	int start;

	/* Start from the last parent node and sift down */
	start = (size - 2) / 2;
	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	/* Check for invalid input or arrays that don't need sorting */
	if (!array || size < 2)
		return;

	/* Build max heap */
	heapify(array, size);

	/* Extract elements from heap one by one */
	end = size - 1;
	while (end > 0)
	{
		/* Move current root to end */
		swap(array, size, 0, end);
		/* Reduce heap size and sift down */
		end--;
		sift_down(array, size, 0, end);
	}
}
