#include "main.h"
/**
 * _print_rev_recursion-function that prints a string in reverse.
 * @s:the string to be printed
 * followed by a new line
 * Return:nothing on success
 */
void _print_rev_recursion(char *s)
{
	if (*s)

	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
