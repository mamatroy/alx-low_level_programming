#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *filename);
void close_file(int z);

/**
 * create_buffer-program that copies the content of a file to another file.
 * @filename:Where the characters in the buffer are stored
 * Return:Pointer to the new buffer
 */
char *create_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file-Closes the file interpreter
 * @z:the interpreter to be closed
 */
void close_file(int z)
{
	int x;

	x = close(z);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close z %d\n", z);
		exit(100);
	}
}

/**
 * main-used to copy the contents of the file
 * @argc:arguments provided for the program
 * @argv:arrays of pointers to the arguments
 * Return:0 if successful
 */
int main(int argc, char *argv[])
{
	int by, to, x, y;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	by = open(argv[1], O_RDONLY);
	x = read(by, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (by == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		y = write(to, buffer, x);
		if (to == -1 || y == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		x = read(by, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (x > 0);

	free(buffer);
	close_file(by);
	close_file(to);

	return (0);
}
