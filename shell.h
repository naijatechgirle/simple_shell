#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int my_putchar(char c);
void my_puts(char *str);
int my_strlen(char *s);
char *my_strdup(char *str);
char *my_concat_all(char *name, char *sep, char *value);

char **my_splitstring(char *str, const char *delim);
void my_execute(char **argv);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *my_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *my_which(char *filename, list_path *head);

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

void(*my_checkbuild(char **arv))(char **arv);
int my_atoi(char *s);
void my_exitt(char **arv);
void my_env(char **arv);
void my_setenv(char **arv);
void my_unsetenv(char **arv);

void my_freearv(char **arv);
void my_free_list(list_path *head);


#endif
