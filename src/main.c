#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "shell.h"

/**
 * \brief           Function to get user's input and delete newline.
 * 
 * \arg[buffer]     Contains the input.
 * \arg[bufsize]    Maximum input's length. 
 * \arg[prompt]     The prompt to display before reading user input.
 */
void 
get_user_input(char **buffer, size_t *bufsize, const char *prompt) {
    printf("%s", prompt);
    
    if (getline(buffer, bufsize, stdin) == -1) {
        perror("Erreur de lecture");
        free(*buffer);
        exit(EXIT_FAILURE);
    }
    (*buffer)[strcspn(*buffer, "\n")] = '\0';
}

/**
 * \brief           Function to create prompt based on username and current directory.
 * 
 * \arg[prompt]     The buffer to store the generated prompt.
 * \arg[size]       The size of the prompt buffer.
 */
void
get_prompt(char *prompt, size_t size) {
    
    char current_directory[PATH_MAX];
    char user[64];

    get_current_directory(current_directory);
    strncpy(user, getlogin(), sizeof(user) - 1);
    user[sizeof(user) - 1] = '\0';

    snprintf(prompt, size, "[\x1B[36m%s\x1B[37m] in [\x1B[36m%s\x1B[37m]/> ", user, current_directory);
}

int 
main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    char *args[MAX_TOKENS];
    char prompt[PATH_MAX + 128];

    while (1) {
        get_prompt(prompt, sizeof(prompt)); 
        get_user_input(&buffer, &bufsize, prompt);

        if (strncmp(buffer, "cd ", 3) == 0) {
            change_directory(buffer);
            continue;
        }

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        tokenize(buffer, args);
        execute(args);
    }

    free(buffer);
    return 0;
}
