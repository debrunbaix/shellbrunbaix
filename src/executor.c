#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * \brief           This function creates a child process using fork() to execute user's cmd.
 * 
 * \arg[args]       Array of Args in user's command.
 */
void 
execute(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork error !!");
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Execution error !!");
        }
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}
