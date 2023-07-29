#ifndef SHELL_HEADER_FILE
#define SHELL_HEADER_FILE

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
/**
 * struct simple_shell - structure for shell data.
 * @input: user input commands
 * @av: argument vectors
 * @environ: shell environment.
 * @pid: process identification number
 * @args: arguments passed
 * @status: process status
 */
typedef struct simple_shell
{
	char *input;
	char **av;
	char **args;
	pid_t pid;
	int status; /*stores status of process*/
} simple_shell;
/****functions1 ******/
extern char **environ;

void shell_loop(char *av[], simple_shell *shell);
char *user_input(simple_shell *shell);
void execute_command(char **av, char **args, simple_shell *shell);
/*****helper functions******/
int _strcmp(char *str1, char *str2);
size_t _strlen(char *str);
char *_strdup(char *str);
#endif/*end SHELL_HEADER_FILE*/
