#include "lists.h"
/**
 * find_listint_loop-function that finds the loop in a linked list.
 * @head:point at the beginning of the node
 * Return:Address of the node where the loop starts or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *blue = head;
	listint_t *black = head;

	if (!head)
		return (NULL);

	while (blue && black && black->next)
	{
		black = black->next->next;
		blue = blue->next;
		if (black == blue)
		{
			blue = head;
			while (blue != black)
			{
				blue = blue->next;
				black = black->next;
			}
			return (black);
		}
	}
	return (NULL);
}
