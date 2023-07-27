#include "shell_main.h"
/**
 * builtin_env - function that print the current environment
 * @shell: pointer shell to the struct.
 * @args: arguments to be passed
 * Return: returns 0 success.
 */
int builtin_env(simple_shell *shell, char **args)
{
	char **env = environ;

	(void)shell;
	(void)args;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

