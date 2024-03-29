#include "lists.h"

/**
 * pop_listint-function that deletes the head node of a listint_t linked list
 * @head:points to the first part
 * Return:the head node’s data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);
	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;
	return (num);
}
