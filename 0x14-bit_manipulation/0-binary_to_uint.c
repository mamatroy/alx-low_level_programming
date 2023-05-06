#include <stdlib.h>
/**
 * binary_to_uint-function that converts a binary number to an unsigned int
 * @x:the character to be used
 * Return:the converted number
 *        otherwise return 0 there is one or more chars in the string
 */
unsigned int binary_to_uint(const char *x)
{
	unsigned int dig = 0;
	int t = 0;

if (x == NULL)
return (0);
for (t = 0; x[t] != '\0'; t++)
{
if (x[t] == '0' || x[t] == '1')
{
	dig = dig << 1;
	dig += x[t] - '0';
}
else
		{
return (0);
		}
	}
return (dig);
}
