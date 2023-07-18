#include "shell_main.h"
/**
 * shell_execute_command - function that executes commands
 * inputed to the shell
 * @command: command inputed
 *
 */
void shell_execute_command(char *command, char **arg[])
{
	int result, status; 
	pid_t child_pid;

	if (command == NULL || arg[0] == NULL)
	{
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		result = execlp(command, command, NULL);
		if (result == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Command execution failed with exit status: %d\n",
			WEXITSTATUS(status));
		}
	}
}
