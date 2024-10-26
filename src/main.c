#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * \brief           Function to get user's input and delete newline
 * 
 * \arg[buffer]     Contain the input.
 * \arg[bufsize]    Maximum input's length. 
 */
void 
get_user_input(char **buffer, size_t *bufsize) {
    printf("%s", PROMPT);
    
    if (getline(buffer, bufsize, stdin) == -1) {
        perror("Erreur de lecture");
        free(*buffer);
        exit(EXIT_FAILURE);
    }
    (*buffer)[strcspn(*buffer, "\n")] = '\0';
}

int 
main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    char *args[MAX_TOKENS];

    while (1) {

        get_user_input(&buffer, &bufsize);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        tokenize(buffer, args);

        execute(args);
    }

    free(buffer);
    return 0;
}
