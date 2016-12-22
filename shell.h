#ifndef SHELL_H
#define SHELL_H

#define N_BUILTINS(x, y) (sizeof(x) / sizeof(y))

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <linux/limits.h>

/**
 * struct builtin_t - stores pointers to builtin functions
 *
 * @name:
 * @f:
 *
 */
typedef struct builtin_t
{
	char *name;
	int (*f)();
} builtin_t;

typedef struct pathdir_t {
	char *dir;
	struct pathdir_t *next;
} pathdir_t;

extern char **environ;

char **arr_alloc(char *p);
char **parsepath(char *p);
char **getpath(void);

int write_history(char *text_content);
int _cd(char **args);
int _help(void);
int my_exit(void);
int _env(void);
int _history(void);
int _launch(char **args, char **envp);
int _execute(char **args, char **envp);
char *read_line(void);
char **split_line(char *line);

/* _strings.c */
char *_strchr(char *s, char c);
char *_strstr(char *s, char *substr);
char *_strndup(char *s, int n);
int _strlen(char *s);

#endif
