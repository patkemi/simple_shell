#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 4096
#define TOKEN_DELIMITERS " \t\r\n\a"
char *user_input(void);
void shell_execute_command(char *command, char **args);
void pat_shell_loop(void);
char **parse_user_input(char *input);
int main(void);

#endif
