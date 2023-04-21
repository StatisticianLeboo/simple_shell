#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: structure containing potential arguments
 *
 * This function exits the shell with a given exit status, provided as an arg
 * to the "exit" command. If no arg is provided, the function exits with a
 * default status of -1.
 *
 * Return: -2 if the "exit" command was found, or 0 otherwise.
 */
int _myexit(info_t *info)
{
	if (info->argv[1]) /* if there is an argument */
	{
		int exit_code = _erratoi(info->argv[1]);

		if (exit_code == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_code;
	}
	else
	{
		info->err_num = -1;
	}

	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: structure containing potential arguments
 *
 * This function changes the current working directory of the shell process, as
 * specified by the "cd" command. If no arg is provided, the function changes
 * the working dir to the user's home dir. If the argument is a hyphen
 * "-", the function changes the working dir to the previous working directory
 * (as stored in the OLDPWD environment var). If the argument is a valid path,
 * the function changes the working directory to that path.
 *
 * Return: Always 0.
 */
int _mycd(info_t *info)
{
	char *dir, buffer[1024];

	if (!getcwd(buffer, 1024))
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			dir = _getenv(info, "PWD=");
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(buffer);
			_putchar('\n');
			return (1);
		}
		dir = _getenv(info, "OLDPWD=");
	}
	else
	{
		dir = info->argv[1];
	}

	if (chdir(dir) == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}

	return (0);
}

/**
 * _myhelp - prints help information
 * @info: structure containing potential arguments
 *
 * This function prints information about the available commands in the shell.
 *
 * Return: Always 0.
 */
int _myhelp(info_t *info)
{
	(void)info; /* avoid "unused parameter" warning */

	_puts("help call works. Function not yet implemented\n");
	return (0);
}

