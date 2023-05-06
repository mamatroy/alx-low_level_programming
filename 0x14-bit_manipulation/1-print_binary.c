#include "main.h"
/**
 * print_binary-function that prints the binary representation of a number
 * @n:the unsigned long integer
 */
void print_binary(unsigned long int n)
{
	int x, add = 0;
	unsigned long int new;

	for (x = 63; x >= 0; x++)
	{
		new = n >> x;
		if (new & 1)
		{
			_putchar ('1');
			add++;
		}
		else if (add)
			_putchar('0');
	}
	if (!add)
		_putchar('0');
}
