#include "main.h"
#include <stdlib.h>
/**
 * read_textfile-function that reads text file and prints it to standard output
 * @filename:the character to be used
 * @letters:the letters to be printed
 * Return:0 if the file can not be opened or read
 *        or return 0 if filename in NULL
 *        otherwise return 0 if it fails or does not write the expected amount
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t ab;
	ssize_t x;
	ssize_t y;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	y = read(ab, buffer, letters);
	x = write(STDOUT_FILENO, buffer, y);

	free(buffer);
	close(ab);
	return (x);
}
