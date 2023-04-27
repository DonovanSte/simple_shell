#include "main.h"
/**
 * _getline - Read a line of input from the user
 *
 * Return: A pointer to a string containing the line read from input
 */
char *_getline(void)
{
	char *line = NULL;
	size_t pos = 0;
	int c;

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			if (pos == 0 && c == EOF)
			{
				return (NULL);
			}
			else
			{
				line = realloc(line, pos + 1);
				line[pos] = '\0';
				return (line);
			}
		}
		else
		{
			line = realloc(line, pos + 1);
			line[pos] = c;
			pos++;
		}
	}
}
