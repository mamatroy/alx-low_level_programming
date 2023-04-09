#include "main.h"
/**
 * flip_bits-function that returns the number of bits needed
 * @n:the unsigned long integer
 * @m:the unsigned integer to use
 * Return:Number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		current = exclusive >> x;
		if (current & 1)
			count++;
	}

	return (count);
}
