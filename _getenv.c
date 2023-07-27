#include "shell_main.h"
/**
 * _strncmp - function that compares n number of character of
 * strings
 * @str1: string one to compare
 * @str2: string 2 to compare
 * @n: number of characters to compare
 * Return: return 0 if success and difference in characters if
 * otherwise.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}


/**
 * _getenv - function that gets the environment
 * @name: name of directory to such.
 * Return: returns the directory if fund or NULL
 */
char *_getenv(const char *name)
{
	char **var;
	size_t name_len = strlen(name);

	if (!name)
	{
		return (NULL);
	}

	var = environ;

	while (*var != NULL)
	{
		if (strncmp(name, *var, name_len) == 0 && (*var)[name_len]  == '=')
		{
			return (*var + name_len + 1);
		}
		var++;
	}
	return (NULL);
}
