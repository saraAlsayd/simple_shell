#include "main.h"

/**
 * _myhistory - displays the list of history,in one command line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments, Used to maintain
 *        constant in the function of the prototype.
 *  Return: 0 :Always.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, ch;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	ch = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = ch;
	return (ret);
}

/**
 * set_alias - it's sets alias of the string.
 * @info: parameterof the struct.
 * @str: the string of the alias.
 *
 * Return:  1 on error,Always 0 on success.
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - it will prints an alias of the string.
 * @node:the alias node.
 * Return:1 on error ,Always 0 on success.
 */
int print_alias(list_t *node)
{
	char *n = NULL, *a = NULL;

	if (node)
	{
		n = _strchr(node->str, '=');
		for (a = node->str; a <= n; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(n + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics alias builtin (man alias).
 * @info: Structure containing potential arguments. Used to maintain
 * Return: Always return : 0.
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *p = NULL;
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
		p = _strchr(info->argv[j], '=');
		if (p)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}

