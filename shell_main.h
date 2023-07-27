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
extern char **environ;
typedef struct simple_shell
{
	char *input;
	char **environ;
	char **av;
	char **args;
	pid_t pid;
	int status; /*stores status of process*/
} simple_shell;
/**
 * struct builtin_f - structure of builting functions.
 * @name: name of the command.
 * @func: pointer that points to the function it must be returned.
 */
typedef struct builtin_f
{
	char *name;
	int (*func)(simple_shell *shell, char **args);
} builtin_t;
char *find_full_path(const char *command);
/****functions1 ******/
void _sigint(int __attribute__ ((unused)) signal);

void shell_loop(char *av[], simple_shell *shell);
char *_getenv(const char *name);
char **tokeniz(char *str, const char *delimiter);
char *user_input(simple_shell *shell);
void execute_command(char **av, char **args, simple_shell *shell);
/***builtin functions*****/
int builtin_setenv(simple_shell *shell, char **args);
int builtin_exit(simple_shell *shell, char **args);
int builtin_cd(simple_shell *shell, char **args);
int builtin_env(simple_shell *shell, char **args);
int builtin_unsetenv(simple_shell *shell, char **args);
int (*execute_builtin(char *command))(simple_shell *, char **args);
/*****helper functions******/
int _strcmp(char *str1, char *str2);
size_t _strlen(char *str);
char *_strdup(char *str);
int _atoi(char *s);
char *_itoa(int n);
int _get_len(int num);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strtok(char *str, const char *delimiter);
void free_args(char **args);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
bool is_delimiter(char ch, const char *delimiter);
/******free memory functions******/
void free_tokens(char **tokens);
void cleanup(simple_shell *shell);
#endif/*end SHELL_HEADER_FILE*/
