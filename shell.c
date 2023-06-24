#include "shell.h"

/**
 * sig_handler - checks when Ctrl C is pressed
 * @sig_number: int
 */
void sig_handler(int sig_number)
{
	if (sig_number == SIGINT)
	{
		my_puts("\n#cisfun$ ");
	}
}

/**
* my_EOF - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void my_EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			my_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * my_isatty - verif if terminal
  */

void my_isatty(void)
{
	if (isatty(STDIN_FILENO))
		my_puts("#cisfun$ ");
}
/**
 * main - Shell
 * Return: on success 0
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		my_isatty();
		len = getline(&buff, &size, stdin);
		my_EOF(len, buff);
		arv = splitstring(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	free_list(head);
	freearv(arv);
	free(buff);
	return (0);
}
