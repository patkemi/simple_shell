#include "shell_main.h"
/**
 * builtin_unsetenv - function that unset environment
 * @shell: pointer to the struct shell
 * @args: arguments
 * Return: return 0 if succes and -1 if otherwise
 */
int builtin_unsetenv(simple_shell *shell, char **args)
{
	char **environ = shell->environ;
	size_t len = strlen(args[1]);
	int i = 0;
	int j;

	if (args[1] == NULL)
	{
		fprintf(stderr, "unsetenv: Missing variable name\n");
		return (-1);
	}
	while (environ[i])
	{
		if (_strncmp(environ[i], args[1], len) == 0 && environ[i][len] == '=')
		{
			free(environ[i]);

			for (j = i; environ[j]; j++)
			{
				environ[j] = environ[j + 1];
			}
			return (0);
		}
		i++;
	}
	fprintf(stderr, "unsetenv: Variable '%s' not found\n", args[1]);
	return (-1);
}

