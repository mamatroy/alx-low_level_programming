#include "main.h"
#include <stdlib.h>
/**
 * create_file- function that creates a file.
 * @filename:the name of the file to create
 * @text_content:terminated string to write to the file
 * Return:1 on success
 *        otherwise return  -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int ab, x, red = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (red = 0; text_content[red];)
			red++;
	}

	ab = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(ab, text_content, red);

	if (ab == -1 || x == -1)
		return (-1);

	close(ab);

	return (1);
}
