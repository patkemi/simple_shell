#include "shell_main.h"

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"
#define MAX_PATH_LENGTH 4096

/**
 * Parses the user input into tokens.
 *
 * Arguments:
 *   - input: The user input string.
 *
 * Returns:
 *   - An array of dynamically allocated strings containing the tokens.
 *   - The caller is responsible for freeing the allocated memory.
 */
char** parse_user_input(char* input)
 {
    char** tokens = malloc(sizeof(char*) * BUFFER_SIZE);

    if (!tokens)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    char* token = strtok(input, TOKEN_DELIMITERS);
    int i = 0;
    while (token)
    {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[i] = NULL;

    return tokens;
}