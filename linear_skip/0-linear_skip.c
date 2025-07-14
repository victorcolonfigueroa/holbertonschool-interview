#include "search.h"

/**
 * handle_no_express - Handle case when there's no express lane
 * @list: Pointer to the head of the skip list
 * @start: Pointer to store the start of search range
 * @end: Pointer to store the end of search range
 */
void handle_no_express(skiplist_t *list, skiplist_t **start, skiplist_t **end)
{
	skiplist_t *prev = list;

	while (prev->next)
		prev = prev->next;
	printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, prev->index);
	*start = list;
	*end = prev;
}

/**
 * handle_end_of_express - Handle case when express lane ends
 * @current: Current node in express lane
 * @prev: Previous node in express lane
 * @start: Pointer to store the start of search range
 * @end: Pointer to store the end of search range
 */
void handle_end_of_express(skiplist_t *current, skiplist_t *prev,
				skiplist_t **start, skiplist_t **end)
{
	prev = current;
	while (current->next)
		current = current->next;
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);
	*start = prev;
	*end = current;
}

/**
 * find_express_range - Find the range to search using express lane
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 * @start: Pointer to store the start of search range
 * @end: Pointer to store the end of search range
 */
void find_express_range(skiplist_t *list, int value,
			skiplist_t **start, skiplist_t **end)
{
	skiplist_t *current, *prev;

	current = list->express;
	prev = list;

	if (current == NULL)
	{
		handle_no_express(list, start, end);
		return;
	}

	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);

		if (current->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					prev->index, current->index);
			*start = prev;
			*end = current;
			break;
		}

		if (current->express == NULL)
		{
			handle_end_of_express(current, prev, start, end);
			break;
		}

		prev = current;
		current = current->express;
	}
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *search_start, *search_end;

	if (list == NULL)
		return (NULL);

	search_start = list;
	search_end = NULL;

	find_express_range(list, value, &search_start, &search_end);

	current = search_start;
	while (current != NULL && current->index <= search_end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);

		if (current->n == value)
			return (current);

		if (current->n > value)
			break;

		current = current->next;
	}

	return (NULL);
}