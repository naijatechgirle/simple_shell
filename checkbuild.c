#include "shell.h"

/**
 * my_checkbuild - checks if the command is a built-in
 * @arv: array of arguments
 * Return: pointer to function that takes arv and returns void
 */
void (*my_checkbuild(char **arv))(char **arv)
{
	mybuild builtins[] = {
		{"exit", my_exitt},
		{"env", my_env},
		{"setenv", my_setenv},
		{"unsetenv", my_unsetenv},
		{NULL, NULL}
	};
	
	int i;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		int j = 0;
		char *builtin_name = builtins[i].name;
		char *command_name = arv[0];

		while (builtin_name[j] == command_name[j])
		{
			if (builtin_name[j] == '\0')
				return (builtins[i].func);
			j++;
		}
	}

	return (NULL);
}
