#include "lists.h"

/**
 * insert_node - Function that inserts a number into a sorted linked list.
 * @head: pointer to pointer of the first node of the listint_t list
 * @number: number to be inserted
 *
 * Return:
 *   The address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
  listint_t *new_node;
  listint_t *current = *head;

  new_node = malloc(sizeof(listint_t));

  if (!new_node)
    return NULL;

  new_node->n = number;

  if (!*head)
  {
    new_node->next = NULL;
    *head = new_node;
    return new_node;
  }

  if (number < (*head)->n)
  {
    new_node->next = *head;
    *head = new_node;
    return new_node;
  }

  while (current->next && current->next->n < number)
  {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  return new_node;
}