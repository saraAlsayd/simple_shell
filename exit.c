#include "master.h"

/**
 **_strchr - locates a character
 *@str: string .
 *@ch: character.
 *Return: a pointer.
 */

char *_strchr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

/**
 **_strncpy - copies string.
 *@dest: the destination.
 *@src: the source.
 *@m: the amount.
 *Return: string.
 */

char *_strncpy(char *dest, char *src, int m)
{
	int y, x = 0;
	char *str = dest;

	while (src[x] != '\0' && x < m - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < m)
	{
		y = x;
		while (y < x)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (str);
}

/**
 **_strncat - concatenates strings
 *@dest: the first.
 *@src: the second.
 *@m: the amount of bytes.
 *Return: the string.
 */

char *_strncat(char *dest, char *src, int m)
{
	int x = 0; 
	int y = 0;
	char *str = dest;

	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < m)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < m)
		dest[x] = '\0';
	return (str);
}

