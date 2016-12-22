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
#include <sys/types.h>
#include <sys/stat.h>


/**
 * struct builtin_t - stores pointers to builtin functions
 *
 * @name: name of builtin.
 * @f: function pointer to builtin.
 *
 */
typedef struct builtin_t
{
	char *name;
	int (*f)();
} builtin_t;

extern char **environ;

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
char *findfile(char **path, char *args);

/* _getpath.c */
void _freemem(char **dirs);
char **arr_alloc(int n);
char **parsepath(char *p);
char **getpath(void);

/* _strings.c */
char *_strchr(char *s, char c);
char *_strstr(char *s, char *substr);
char *_strndup(char *s, int n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

/* _strings2.c */
char *_strcpy(char *dest, char *src);
char *_memset(char *s, char b, unsigned int n);

#endif
