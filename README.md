0x16. C - Simple Shell team project
This is a group project by ALX students on shell.

Group Project:

0. Write a beautiful code that passes the Betty checks

1. Write a UNIX command line interpreter.

2. Handle command lines with arguments

3. Handle the PATH
Fork must not be called if the command doesn’t exist


4. Implement the exit built-in, that exits the shell
You don’t have to handle any argument to the built-in exit


5. Implement the env built-in, that prints the current environment


6. Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline


7. You are not allowed to use strtok


8. handle arguments for the built-in exit
Usage: exit statue, where statue is an integer used to exit the shell


9. Implement the setenv and unsetenv builtin commands


10. Implement the builtin command cd:


11. Handle the commands separator ;


12. Handle the && and || shell logical operators


13. Implement the alias builtin command


14. Handle variables replacement
Handle the $? variable
Handle the $$ variable


15. Handle comments (#)


16. Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin
