#include "main.h"
/**
 * binary_to_uint-function that converts a binary number to an unsigned int
 * @b:the character to be used
 * Return:the converted number, or 0
 *     there is one or more chars in the string b that is not 0 or 1
 *     b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int s = 0;

	if (!b)
		return (0);
	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);
		s = 2 * s + (b[x] - '0');
	}
	return (s);
}
