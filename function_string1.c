#include "master.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

/**
 * _strdup - duplicating a string
 * @str: the string to duplicate
 *
 * Return: the pointer.
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}

/**
 * _puts - printing an input of the string.
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - writing the character ch.
 * @ch: character to print
 *
 * Return: On success 1,On error if -1 is returned.
 */
int _putchar(char ch)
{
	static int s;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || s >= WRITE_BUF_SIZE)
	{
		write(1, buf, s);
		s = 0;
	}
	if (ch != BUF_FLUSH)
		buf[s++] = ch;
	return (1);
}

