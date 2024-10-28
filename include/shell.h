#ifndef SHELL_H
#define SHELL_H

#define MAX_TOKENS 64
#define PROMPT "shellbrunbaix/> "

void tokenize(char *buffer, char **args);
void execute(char **args);
void change_directory(char *buffer);

#endif