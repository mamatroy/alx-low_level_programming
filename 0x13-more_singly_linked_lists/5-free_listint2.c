#include "lists.h"

/**
 * free_listint2-function that frees a listint_t list
 * @head:points to the list being freed
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	*head = NULL;
}
