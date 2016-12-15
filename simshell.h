#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int _cd(char **args);
int _help(char **args);
int my_exit(char **args);
int _launch(char ** args);
int _execute(char **args);
char *read_line(void);
char **split_line(char *line);
void main_loop(void);


#endif
