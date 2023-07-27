#include "master.h"

/**
 * print_alias - printing alias.
 * @node: the alias.
 *
 * Return: Always 0 in success,Or 1 in error
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *art = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (art = node->str; art <= ptr; art++)
		_putchar(*art);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin.
 * @info: Structure containing potential the arguments.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		ptr = _strchr(info->argv[j], '=');
		if (ptr)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}

