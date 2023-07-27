#include "shell_main.h"
/**
 * find_full_path - function the find path
 * @command: command to search
 * Return: returns the duplicate of the path or null
 */
char *find_full_path(const char *command)
{
	char *path, full_path[PATH_MAX], *dir;
	char *path_env;

	path_env = _getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found");
		return (NULL);
	}
	path = _strdup(path_env);
	if (path == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	dir = _strtok(path, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (_strdup(full_path));
		}
		dir = _strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
