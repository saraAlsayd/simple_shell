#include "master.h"

/**
 * **strtow - spliting a string into words.
 * @str: the input string
 * @delim: the delimeter string
 * Return: the pointer to an array , or NULL.
 */

char **strtow(char *str, char *delim)
{
	int x, y, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], delim) && (is_delim(str[x + 1], delim) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[x], delim))
			x++;
		k = 0;
		while (!is_delim(str[x + k], delim) && str[x + k])
			k++;
		s[y] = malloc((k + 1) * sizeof(char));
		if (!s[y])
		{
			for (k = 0; k < y; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;
	return (s);
}

/**
 * **strtow2 - spliting a string into words
 * @str: input string.
 * @delim: delimeter
 * Return: a pointer to array of string, or NULL.
 */
char **strtow2(char *str, char delim)
{
	int x, y, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != delim && str[x + 1] == delim) ||
				    (str[x] != delim && !str[x + 1]) || str[x + 1] == delim)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (str[x] == delim && str[x] != delim)
			x++;
		k = 0;
		while (str[x + k] != delim && str[x + k] && str[x + k] != delim)
			k++;
		s[y] = malloc((k + 1) * sizeof(char));
		if (!s[y])
		{
			for (k = 0; k < y; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;
	return (s);
}

