#include "main.h"
/**
 * _strlen_recursion-function that returns the length of a string.
 * @s:the string to be measured
 * followed by a new line
 * Return:the length of the string
 */
int _strlen_recursion(char *s)
{
	return (*s ? (1 + _strlen_recursion(++s)) : 0);
}
