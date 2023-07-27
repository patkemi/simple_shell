#include "shell_main.h"
/**
 * builtin_cd - function used to change working directory
 * @shell: command to be passed
 * @args: pointer to the shell
 * Return: return 0 (success) otherwise return 1.
 */
int builtin_cd(simple_shell *shell, char **args)
{
	char *home_dir, *pre_dir, *old_pwd;
	char current_dir[4096];

	(void)shell;
	if (args[1] == NULL)
	{
		home_dir = _getenv("HOME");
		if (chdir(home_dir) != 0)
		{
			perror("cd");
			returm (-1);
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		prev_dir = _getenv("OLDPWD");
		if (chdir(prev_dir) != 0)
		{
			perror("cd");
			return (1);
		}
		printf("%s\n", prev_dir);
	}
	else
	{
		old_pwd = _getenv("PWD");
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (1);
		}
	}
	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
	{
		setenv("PWD", current_dir, 1);
		setenv("OLDPWD", old_pwd, 1);
	}
	else
	{
		perror("cd");
		return (-1);
	}
	return (0);
}
