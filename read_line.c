#include "main.h"
/**
 * read_line - Read a line of input from the user
 *
 * Return: A pointer to a string containing the line read from input
 */
char *read_line()
{
	char *line = NULL;
	size_t bufsize = 0;
	size_t len = 0;
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (len + 1 >= bufsize)
		{ /* if the buffer is full, resize it */
			bufsize += 256;
			line = realloc(line, bufsize);
		}
		line[len++] = c;
	}

	if (len == 0 && c == EOF)
	{ /* if there was no input, return NULL */
		return (NULL);
	}

	/* append a null terminator to the end of the string */
	if (len + 1 >= bufsize)
	{
		bufsize += 1;
		line = realloc(line, bufsize);
	}
	line[len] = '\0';

	return (line);
}
