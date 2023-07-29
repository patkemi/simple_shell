#include "shell_main.h"
/**
 * execute_command - function that executes shell command
 * @av: argument vector.
 * @args: command arguments
 * @shell: pointer to the struct
 */
void execute_command(char **av, char **args, simple_shell *shell)
{
	int status = 0;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		shell->pid = pid;
		waitpid(pid, &status, 0);
	}
}
