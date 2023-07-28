#include "master.h"

/**
 * bfree - freeing a the pointer and the NULL .
 * @ptr: the address of the pointer.
 *
 * Return: 1 if freed, other 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

