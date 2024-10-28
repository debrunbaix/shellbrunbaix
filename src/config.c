#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h>

/**
 * \brief           Function to get current directory.
 */
void 
get_current_directory(char *current_directory){
    char cwd[PATH_MAX];

    if (getcwd(cwd, PATH_MAX) != NULL) {
        char *last_slash = strrchr(cwd, '/');
    
        if (last_slash != NULL && *(last_slash + 1) != '\0') {
            strncpy(current_directory, last_slash + 1, 64);
            current_directory[63] = '\0';
        } else {
            printf("Error: unable to extract the directory name.\n");
        }
    } else {
        perror("getcwd() error");
    }
}