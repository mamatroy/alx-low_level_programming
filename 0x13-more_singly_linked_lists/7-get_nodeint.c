#include "lists.h"
/**
 * get_nodeint_at_index-function that returns the nth node of a listint_t list
 * @head:node at the beginnong of the list
 * @index:node to return
 * Return:NULL if the node does not exist or a pointer
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x = 0;
	listint_t *temp = head;

	while (temp && x < index)
	{
		temp = temp->next;
		x++;
	}
	return (temp ? temp : NULL);
}
