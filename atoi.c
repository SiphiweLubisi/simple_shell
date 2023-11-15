#include "shell.h"

/**
 * interactive - return it true if shell is in interactive mode
 * @info: the struct address
 *
 * Return: 1 if is in interactive mode, 0 if otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the character is a delimeter
 * @c: char to check
 * @delim: the delimeter string
 * Return: 1 if is true, 0 if is false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - it checks for the alphabetic character
 *@c: the character to input
 *Return: 1 if c is alphabetic, 0 if is otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@r: the string to be converted
 *Return: 0 if no numbers in the string, converted number if is otherwise
 */

int _atoi(char *r)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  r[i] != '\0' && flag != 2; i++)
	{
		if (r[i] == '-')
			sign *= -1;

		if (r[i] >= '0' && r[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (r[i] - '0');
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
