#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
/**
 * read_textfile- function that reads a text file and prints it to the POSIX
 *                standard output.
 * @filename:the const character to be used
 * @letters:the letters to be used
 * Return:the actual number of letters it could read and print
 *        if the file can not be opened or read, return 0
 *        if filename is NULL return 0
 *        if write fails or does not write the expected amount
 *        of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd;
	ssize_t a;
	ssize_t b;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	b = read(fd, buffer, letters);
	a = write(STDOUT_FILENO, buffer, b);

	free(buffer);
	close(fd);
	return (a);
}
