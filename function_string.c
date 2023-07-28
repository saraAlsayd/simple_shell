#include "master.h"

/**
 * _strlen - returning the length of the string
 * @str: the string 
 *
 * Return: the integer.
 */
int _strlen(char *str)
{
	int j = 0;

	if (!str)
		return (0);

	while (*str++)
		j++;
	return (j);
}

/**
 * _strcmp - performing the lexicogarphic comparison .
 * @str1: first string
 * @str2: second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with - checking if the needle starting with haystack.
 * @haystack: the string.
 * @needle: substring.
 *
 * Return: address of next ,or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenating a two strings
 * @dest: destination.
 * @src: source.
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

