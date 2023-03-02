#include "main.h"
#include <stdio.h>
/**
 * print_buffer-function that prints a buffer.
 * @b:buffer
 * @size:size
 * return:void
 */
void print_buffer(char *b, int size)
{
	int j, k, l;

	j = 0;
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (j < size)
	{
		k = size - j < 10 ? size - j : 10;
		printf("%08x:", j);
		for (l = 0; l < 10; l++)
		{
			if (l < k)
			printf("%02x", *(b + j + l));
			else
				printf(" ");
			if (l % 2)
			{
				printf(" ");
			}
		}
		for
			(l = 0; l < k; l++);
		{
			int c = *(b + j + l);

			if (c < 32 || c > 132)

			{
				c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		j += 10;
	}
}
