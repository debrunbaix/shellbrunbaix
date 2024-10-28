#include <unistd.h> 
#include <stdio.h>

#include "shell.h"

/**
 * \brief           Function to change current directory.
 * 
 * \arg[buffer]     string of the user's input.
 */
void 
change_directory(char *buffer){
    char *path = buffer + 3;

    if (chdir(path) == -1) {
        perror("cd error");
    }
}