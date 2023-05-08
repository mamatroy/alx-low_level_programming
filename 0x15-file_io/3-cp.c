#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *filename);
void file_to(int fd);

/**
 * create_buffer-program that copies the content of a file to another file.
 * @filename:the name of the file
 * Return:the pointer
 */
char *create_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error:Can't write to %s/n", filename);
			exit(99);
	}
	return (buffer);
}
/**
 * file_to-function that can close the descriptors
 * @fd:the descriptor to be closed
 */
void file_to(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error:Cant close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main-function that copy a file to another file
 * @argc:The arg to be used
 * @argv:the pointers to the argument
 * Return:0 if successful
 */
int main(int argc, char *argv[])
{
	int from, to, a, b;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage:cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		b = write(to, buffer, a);
		if (to == -1 || b == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		a = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (a > 0);
	free(buffer);
	return (0);
}
