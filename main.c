#include "main.h"
/**
 * main - Entry point to the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	pid_t pid;
	int status;
	(void)argc, (void)argv;

	while (1)
	{
		char *line;
		char *args[256];
		int nargs = 0;
		char *p;

		printf("$ ");
		fflush(stdout);
		line = read_line(); /* read a line of input */

		if (!line) /* end of file or error */
			break;
		for (p = line; *p; ) /* split the line into arguments */
		{
			while (*p == ' ' || *p == '\t')
			{*p++ = '\0'; }
			if (*p)
			{args[nargs++] = p; }
			while (*p && *p != ' ' && *p != '\t')
			{p++; }
		}
		args[nargs] = NULL;
		pid = fork(); /* create a child process to execute the command */
		if (pid == -1)
		{perror("fork");
			exit(1); }
		else if (pid == 0) /* child process */
		{execvp(args[0], args);
			perror("execvp");
			exit(1); }
		else /* parent process */
			waitpid(pid, &status, 0);
		free(line);
	}
	return (0);
}
