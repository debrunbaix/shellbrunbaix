#include <string.h>
#include "shell.h"

/**
 * \brief           Function to parse user's input into tokens (cmd, args)
 * 
 * \arg[buffer]     Contain user's input.
 * \arg[args]       Array of Args in user's command.
 */
void 
tokenize(char *buffer, char **args) {
    int i = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL && i < MAX_TOKENS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}
