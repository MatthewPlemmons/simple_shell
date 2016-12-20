#ifndef SHELL_H
#define SHELL_H

#define N_BUILTINS(x, y) (sizeof(x) / sizeof(y))

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * struct builtin_t - stores pointers to builtin functions
 */
typedef struct builtin_t {
	char *name;
	int (*f)();
} builtin_t;


extern char **environ;

int _cd(char **args);
int _help(void);
int sh_exit(void);
int _env(void);
int _launch(char **args);
int _execute(char **args);
char *read_line(void);
char **split_line(char *line);

#endif
