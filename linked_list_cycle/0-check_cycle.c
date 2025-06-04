#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of the list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list;
    listint_t *fast = list;

    /* Traverse the list with two pointers */
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       /* Move slow pointer by 1 */
        fast = fast->next->next; /* Move fast pointer by 2 */

        if (slow == fast)
            return (1); /* Cycle detected */
    }
    return (0); /* No cycle */
}