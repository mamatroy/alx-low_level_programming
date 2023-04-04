#include "lists.h"

/**
 * add_nodeint-function that adds a new node at the beginning of listint_t list
 * @head: pointer to the first node in the list
 * @n:information to add in the new node
 * Return:Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *first;

	first = malloc(sizeof(listint_t));
	if (!first)
		return (NULL);
	first->n = n;
	first->next = *head;
	*head = first;
	return (first);
}
