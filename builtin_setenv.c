#include "shell_main.h"
/**
 * builtin_setenv - function that set environment
 * @shell: pointer to the struct
 * @args: arguments to be passed
 * Return: return 0 success
 */
int builtin_setenv(simple_shell *shell, char **args)
{
	char *variable, *value, **environ = shell->environ, *new_var;
	size_t len = 0;
	int i = 0;

	if (args[1] != NULL && args[2] != NULL)
	{
		variable = args[1];
		value = args[2];
		while (environ[i])
		{
			len = _strlen(variable);
			if (_strncmp(environ[i], variable, len) == 0)
			{
				free(environ[i]);
				new_var = malloc(len + strlen(value) + 2);
				if (new_var == NULL)
					return (1);
				_strcpy(new_var, variable);
				_strcat(new_var, "=");
				_strcat(new_var, value);
				environ[i] = new_var;
				return (0);
			}
			i++;
		}
		new_var = malloc(_strlen(variable) + strlen(value) + 2);
		if (!new_var)
			return (-1);
		_strcpy(new_var, variable);
		_strcat(new_var, "=");
		_strcat(new_var, value);
		environ[i] = new_var;
		environ[i + 1] = NULL;
		return (0);
	}
	else
	{
		fprintf(stderr, "setenv VARIABLE VALUE\n");
		return (-1);
	}
}
