#include "main.h"
/**
 * prompt - Prints a prompt and reads a line of input from the user
 *
 * @ac: The argument count
 * @av: The argument vector
 *
 * Return: Always 0
 */
int prompt(int ac, char **av)
{
	(void)ac, (void)av;
	while (1)
	{
		char buffer[1024];
		int i = 0;
		char c;

		printf("$ ");
		fflush(stdout);

		while ((c = getchar()) != '\n' && c != EOF)
		{
			buffer[i] = c;
			i++;
		}

		buffer[i] = '\0';
		printf("%s\n", buffer);
		continue;
	}
	return (0);
}
