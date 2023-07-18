#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * Reads user input from stdin.
 *
 * Returns:
 *   - Dynamically allocated string containing the user input.
 *   - The caller is responsible for freeing the allocated memory.
 */
char *shell_read_user_input()
{
    char *input = malloc(sizeof(char) * BUFFER_SIZE);

    if (!input)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    printf("$ ");
    if (fgets(input, BUFFER_SIZE, stdin) == NULL)
    {
        free(input);
        return NULL;
    }

    size_t length = strlen(input);
    if (input[length - 1] == '\n')
        input[length - 1] = '\0';

    return input;
}

/**
 * Executes the given command.
 *
 * Arguments:
 *   - command: A single word representing the executable.
 *
 * Notes:
 *   - If the command is empty, it does nothing.
 */
void shell_execute_command(char *command)
{
    if (command == NULL)
    {
        return;
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        int result = execlp(command, command, NULL);

        if (result == -1)
        {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            fprintf(stderr, "Command execution failed with exit status: %d\n", WEXITSTATUS(status));
        }
    }
}

/**
 * Implements the main shell loop.
 *
 * Notes:
 *   - Reads user input, executes the command,
 *  and repeats until the end of file condition is encountered
 */
void pat_shell_loop()
{
    char *input;
    int status = 1;

    do
    {
        input = shell_read_user_input();

        if (input == NULL)
        {
            break;
        }

        shell_execute_command(input);

        free(input);
    } while (status);
}

/**
 * Entry point of the program.
 *
 * Notes:
 *   - Starts the shell loop.
 */
int main()
{
    pat_shell_loop();

    return EXIT_SUCCESS;
}
