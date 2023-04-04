#include "lists.h"

/**
 * add_nodeint_end- function that adds a new node at the end of listint_t lis
 * @head:points the first part of the list
 * @n:information included
 * Return:the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *first;
	listint_t *temp = *head;

	first = malloc(sizeof(listint_t));
	if (!first)
		return (NULL);
	first->n = n;
	first->next = NULL;
	if (*head == NULL)
	{
		*head = first;
		return (first);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	return (first);
}
