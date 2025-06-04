#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the list
 *
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered a palindrome
 */
int is_palindrome(listint_t **head)
{
    // 1. Handle edge cases:
    //    - If the list is empty or has only one node, return 1 (palindrome).
    if (*head == NULL || (*head)->next == NULL)
    {
        return 1;
    }

    // 2. Use two pointers (slow and fast) to find the middle of the list:
    //    - Initialize slow and fast pointers at the head.
    //    - Move slow by one node and fast by two nodes each iteration.
    //    - When fast reaches the end, slow will be at the middle.
    listint_t *slow = *head;
    listint_t *fast = *head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 3. Reverse the second half of the list starting from the slow pointer:
    //    - Use a helper function to reverse the list from slow onwards.
    //    - Store the head of the reversed second half.
    listint_t *second_half = reverse_list(&slow);

    // 4. Compare the first half and the reversed second half:
    //    - Initialize two pointers: one at the head, one at the head of the reversed half.
    //    - Compare values node by node.
    //    - If any values differ, the list is not a palindrome.
    listint_t *first_half = *head;
    listint_t *second_half_reversed = second_half;

    while (first_half != NULL && second_half_reversed != NULL)
    {
        if (first_half->n != second_half_reversed->n)
        {
            return 0;
        }
        first_half = first_half->next;
        second_half_reversed = second_half_reversed->next;
    }

    // 5. Restore the second half to its original order:
    //    - Reverse the second half again to restore the original list structure.
    reverse_list(&second_half);

    // 6. Return 1 if all values matched (palindrome), otherwise return 0.
    return 1;
}