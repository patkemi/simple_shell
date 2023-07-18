#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
char *user_input(void);
void shell_execute_command(char *command, char **arg[]);
void pat_shell_loop(void);
int main(void);
#endif
