#include "main.h"
/**
 * flip_bits-function that returns the number of bits you would need to flip
 *          to get from one number to another.
 * @n:the unsigned long integer
 * @m:another unsigned long integer
 * Return:the bits to be transformed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, add = 0;
	unsigned long int new;
	unsigned long int big = n ^ m;

	for (x = 63; x >= 0; x++)
	{
		new = big >> x;
		if (new & 1)
			add++;
	}
	return (add);
}
