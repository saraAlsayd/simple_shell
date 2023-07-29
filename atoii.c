#include "master.h"

/**
 * interactive - returning true if interactive shell.
 * @info: struct.
 *
 * Return: 1 if interactive mode.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @ch: the char.
 * @delim: the delimeter.
 * Return: 1 if true, 0.
 */

int is_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	else
		return (0);
}

/**
 * _isalpha - checking for alphabetic.
 * @ch: The character.
 * Return: 1 if ch is alphabetic,other 0.
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to integer.
 * @str: the string.
 * Return: 0 if no numbers,otherwise converted
 */

int _atoi(char *str)
{
	int j, sin = 1, flg = 0, output;
	unsigned int result = 0;

	for (j = 0; str[j] != '\0' && flg != 2; j++)
	{
		if (str[j] == '-')
			sin *= -1;

		if (str[j] >= '0' && str[j] <= '9')
		{
			flg = 1;
			result *= 10;
			result += (str[j] - '0');
		}
		else if (flg == 1)
			flg = 2;
	}

	if (sin == -1)
		output = -result;
	else
		output = result;

	return (output);
}

