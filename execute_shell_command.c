#include "shell_main.h"
/**
 * shell_execute_command - function that executes commands
 * inputed to the shell
 * @command: command inputed
 *
 */
void shell_execute_command(char *command, char **arg[])
{
	int result, status; 
	pid_t child_pid;
	char path[MAX_PATH_LENGTH];
    char* dir;

	if (command == NULL || args == NULL || args[0] == NULL)
	{
        return;
    }

	char* path_env = getenv("PATH");
    if (path_env == NULL) {
        fprintf(stderr, "Error: PATH environment variable is not set.\n");
        return;
    }

	strncpy(path, path_env, sizeof(path) - 1);
    dir = strtok(path, ":");

	while (dir != NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);

        result = access(full_path, X_OK);
        if (result == 0) {
            child_pid = fork();
	       if (child_pid == -1)
	        {
		       perror("fork error");
		       exit(EXIT_FAILURE);
            } else if (child_pid == 0) {

                execv(full_path, args);

                perror("Error executing command");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                int status;
                waitpid(child_pid, &status, 0);

                if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                    fprintf(stderr, "Command execution failed with exit status: %d\n", WEXITSTATUS(status));
                }
                return; // Command executed successfully
            }
        }

        dir = strtok(NULL, ":");
    }
     fprintf(stderr, "Command not found: %s\n", command);
		
}
