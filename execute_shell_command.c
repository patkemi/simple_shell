#include "shell_main.h"
/**
 * execute_command - function that executes shell command
 * @av: argument vector.
 * @args: command arguments
 * @shell: pointer to the struct
 */
void execute_command(char **av, char **args, simple_shell *shell)
{
	shell->pid = fork();
	if (shell->pid == -1)
	{
		perror("Fork failed");
	}
	else if (shell->pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", av[0]);
		}
	}
	else
	{
		waitpid(shell->pid, &(shell->status), 0);
	}
	if (WIFEXITED(shell->status) && WEXITSTATUS(shell->status) != 0)
	{
		printf("\n");
	}
}
