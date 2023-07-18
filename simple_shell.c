#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

char* read_user_input() {
    char* input = malloc(sizeof(char) * BUFFER_SIZE);

    if (!input) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    printf("$ ");
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        // Handle end of file condition (Ctrl+D)
        free(input);
        return NULL;
    }

    // Remove newline character at the end
    size_t length = strlen(input);
    if (input[length - 1] == '\n')
        input[length - 1] = '\0';

    return input;
}

void execute_command(char* command) {
    if (command == NULL) {
        // Empty command, do nothing
        return;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        int result = execlp(command, command, NULL);

        if (result == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Command execution failed with exit status: %d\n", WEXITSTATUS(status));
        }
    }
}

void shell_loop() {
    char* input;
    int status = 1; // Initialize status to a non-zero value

    do {
        input = read_user_input();

        if (input == NULL) {
            // Handle end of file (Ctrl+D)
            break;
        }

        execute_command(input);

        free(input);
    } while (status);
}

int main() {
    shell_loop();

    return EXIT_SUCCESS;
}
