#include "master.h"

/**
 * free - free  pointer to the address
 * @ptr: address of the pointer
 *
 * Return: 1 if free
 */
int free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
