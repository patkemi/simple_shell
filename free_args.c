#include "shell_main.h"
/**
 * free_args - function that frees args
 * @args: arguments to free
 */
void free_args(char **args)
{
	int i;

	if (*args == NULL)
	{
		return;
	}
	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
