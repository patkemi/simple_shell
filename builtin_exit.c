#include "shell_main.h"
/**
 * builtin_exit - function that exit the shell
 * @shell: pointer to the struct
 * @args: argument to be passed
 * Return: return 0 success
 */
int builtin_exit(simple_shell *shell, char **args)
{
	int status;

	(void)shell;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
