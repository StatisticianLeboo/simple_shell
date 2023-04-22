#include "shell.h"

/**
 * interactive - checks if shell is running in interactive mode
 * @info: pointer to struct containing information about the shell
 *
 * Return: 1 if running in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: character to check
 * @delim: string of delimiter characters
 *
 * Return: 1 if c is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer or 0 if no numbers in string
 */
int _atoi(char *s)
{
	int sign = 1, output = 0;
	unsigned int result = 0;
	int flag = 0; /* 0 = no numbers found yet, 1 = numbers found, 2 = finished */	
	int i;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

