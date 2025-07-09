#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_avl_node - Creates a new AVL tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * build_avl_from_sorted - Recursively builds AVL tree from sorted array
 * @array: Pointer to the sorted array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root of the created subtree, or NULL on failure
 */
static avl_t *build_avl_from_sorted(int *array, int start, int end,
									avl_t *parent)
{
	avl_t *root;
	int mid;

	/* Base case: if start > end, no elements to process */
	if (start > end)
		return (NULL);

	/* Find the middle element to maintain balance */
	mid = (start + end) / 2;

	/* Create the root node with the middle element */
	root = create_avl_node(parent, array[mid]);
	if (!root)
		return (NULL);

	/* Recursively build left subtree from left half */
	root->left = build_avl_from_sorted(array, start, mid - 1, root);
	if (root->left == NULL && start <= mid - 1)
	{
		/* If we failed to create left child but should have */
		free(root);
		return (NULL);
	}

	/* Recursively build right subtree from right half */
	root->right = build_avl_from_sorted(array, mid + 1, end, root);
	if (root->right == NULL && mid + 1 <= end)
	{
		/* If we failed to create right child but should have */
		free(root);
		return (NULL);
	}

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	/* Start the recursive building process */
	return (build_avl_from_sorted(array, 0, (int)size - 1, NULL));
}