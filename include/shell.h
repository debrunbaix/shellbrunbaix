#ifndef SHELL_H
#define SHELL_H

#define MAX_TOKENS 64
#define PROMPT "shellbrunbaix/> "

void get_current_directory(char *current_directory);
void change_directory(char *buffer);
void tokenize(char *buffer, char **args);
void execute(char **args);

#endif