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
	int x, y;
	char *str = dest;

	x = 0;
	y = 0;
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

<<<<<<< HEAD
=======

/**
 **_strchr - locates a character.
 *@str: the string.
 *@ch: the character.
 *Return: (s) a pointer.
 */
char *_strchr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
>>>>>>> 1df2f08b810c826f80d4db6f2c25a0639c95ff30
