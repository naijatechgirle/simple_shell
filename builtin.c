#include "shell.h"

/**
* my_exit - exits the shell
* @info: Structure containing potential arguments.
* Return: exits with a given exit status
*         (0) if info.argv[0] != "exit"
*/
int my_exit(info_t *info)
{
	int checkExit;

		if (info->argv[1]) /* If there is an exit argument */
		{
			checkExit = my_erratoi(info->argv[1]);
			if (checkExit == -1)
			{
				info->status = 2;
				print_error(info, "Illegal number: ");
				my_eputs(info->argv[1]);
				my_eputchar('\n');
				return (1);
			}
			info->err_num = my_erratoi(info->argv[1]);
			return (-2);
		}
		info->err_num = -1;
		return (-2);
}

/**
* my_cd - changes the current directory of the process
* @info: Structure containing potential arguments.
* Return: Always 0
*/
int my_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		my_eputs("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = my_getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = my_getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (my_strcmp(info->argv[1], "-") == 0)
	{
		if (!my_getenv(info, "OLDPWD="))
		{
			my_eputs(s);
			my_eputchar('\n');
			return (1);
		}
		my_eputs(my_getenv(info, "OLDPWD=")), my_eputchar('\n');
		chdir_ret = chdir((dir = my_getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	{
		chdir_ret = chdir(info->argv[1]);
	}
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		my_eputs(info->argv[1]), my_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", my_getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * my_help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * Return: Always 0
 */
int my_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
