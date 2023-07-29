#include "shell_main.h"
/**
 * execute_builtin - pointer function that return appropirate command to
 * be executed
 * Return: returns the appropirate function to be executed
 * @command: inputed command to be passed to the function.
 */
int (*execute_builtin(char *command))(simple_shell *, char **args)
{
	builtin_t builtins[] = {
		{"exit", builtin_exit},
		{NULL, NULL}
	};

	int i;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(builtins[i].name, command) == 0)
		{
			return (builtins[i].func);
		}
	}
	return (NULL);
}
