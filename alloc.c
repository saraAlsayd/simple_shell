#include "master.h"

/**
 * _memset - filling memory.
 * @str: the pointer.
 * @b: byte.
 * @m: amount of bytes.
 * Return: (s) a pointer.
 */
char *_memset(char *str, char b, unsigned int m)
{
	unsigned int j;

	for (j = 0; j < m; j++)
		str[j] = b;
	return (str);
}

/**
 * ffree - freeing a string.
 * @ppr: string of strings.
 */

void ffree(char **ppr)
{
	char **a = ppr;

	if (!ppr)
		return;
	while (*ppr)
		free(*ppr++);
	free(a);
}
/**
 * _realloc - reallocating a block of memory
 * @ptr: pointer to previous malloc'ated.
 * @old_size: the byte size .
 * @new_size: the byte size .
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pp;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pp = malloc(new_size);
	if (!pp)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pp[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pp);
}

