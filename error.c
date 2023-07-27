#include "master.h"

/**
 * _eputs - printin an input of the string.
 * @str: string to printing
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - writes the character.
 * @ch: The character.
 *
 * Return: On success 1,or -1 is returned error.
 */
int _eputchar(char ch)
{
	static int g;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || g >= WRITE_BUF_SIZE)
	{
		write(2, buf, g);
		g = 0;
	}
	if (ch != BUF_FLUSH)
		buf[g++] = ch;
	return (1);
}

/**
 * _putfd - writes=ing the character ch to given fildes.
 * @ch: The character.
 * @filedes: The filedescriptor.
 *
 * Return: On success 1, -1 On errorز
 */
int _putfd(char ch, int filedes)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(filedes, buf, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buf[j++] = ch;
	return (1);
}

/**
 * _putsfd - printing an input string.
 * @str: the string.
 * @filedes: the filedescriptor.
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int filedes)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, filedes);
	}
	return (j);
}

