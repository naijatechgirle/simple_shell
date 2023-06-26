#include "shell.h"

/**
 * my_exitt - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void my_exitt(char **arv)
{
	int i, n;

	if (arv[1])
	{
		n = my_atoi(arv[1]);
		if (n <= -1)
			n = 2;
		my_freearv(arv);
		exit(n);
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}

/**
 * my_atoi - converts a string into an integer
 * @s: pointer to a string
 *Return: the integer
 */
int my_atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * my_env - prints the current environment
 * @arv: array of arguments
 */
void my_env(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		my_puts(environ[i]);
		my_puts("\n");
	}

}

/**
 * my_setenv - Initialize a new environment variable, or modify an existing one
 * @arv: array of entered words
 */
void my_setenv(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(my_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = my_concat_all(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * my_unsetenv - Remove an environment variable
 * @arv: array of entered words
 */
void my_unsetenv(char **arv)
{
	int i, j;

	if (!arv[1])
	{
		perror(my_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

