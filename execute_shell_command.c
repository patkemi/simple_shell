#include "shell_main.h"
/**
 * execute_command - function that executes shell command
 * @av: argument vector.
 * @args: command arguments
 * @shell: pointer to the struct
 */
void execute_command(char **av, char **args, simple_shell *shell)
{
	char *full_path;

	full_path = find_full_path(args[0]);
	if (full_path == 0)
	shell->pid = fork();
	if (shell->pid == -1)
	{
		perror("Fork failed");
	}
	else if (shell->pid == 0)
	{
		if (execvp(args[0], args) == -1)
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
