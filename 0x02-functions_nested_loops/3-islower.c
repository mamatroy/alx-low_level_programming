#include "main.h"
/**
 * _islower - Checks if a character is lowercase.
 * @c: The character c to be checked.
 * Return: 0 if character is lowercase, 1 otherwise.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{	return (0);
	}
}
