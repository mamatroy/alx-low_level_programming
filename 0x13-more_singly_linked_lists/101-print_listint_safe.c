#include "lists.h"
#include <stdio.h>
size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
/**
 * looped_listint_len-function that prints a listint_t linked list.
 * @head:a node at the beginning
 * Return:the number of nodes in the list
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *blue, *black;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	blue = head->next;
	black = (head->next)->next;

	while (black)
	{
		if (blue == black)
		{
			blue = head;
			while (blue != black)
			{
				nodes++;
				blue = blue->next;
				black = black->next;
			}
			blue = blue->next;
			while (blue != black)
			{
				nodes++;
				blue = blue->next;
			}
			return (nodes);
		}
		blue = blue->next;
		black = (black->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe-function that prints a safe listint_t linked list
 * @head:points at the beginning of the list
 * Return:Nodes on the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodes);
}
