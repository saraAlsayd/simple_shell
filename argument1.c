#include "master.h"

/**
 * _myhistory - displays the history list.
 * @info: Structure containing potential the arguments.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets string to the alias.
 * @info: the parameter.
 * @s: string .
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *s)
{
	char *p, ch;
	int ret;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	ch = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, s, -1)));
	*p = ch;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info:  the parameter struct
 * @s: string alias
 *
 * Return: Always 0 on success.
 */
int set_alias(info_t *info, char *s)
{
	char *p;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, s));

	unset_alias(info, s);
	return (add_node_end(&(info->alias), s, 0) == NULL);
}

