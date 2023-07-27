#include "master.h"

/**
 * get_environ - returning the string 
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Removing  an environment.
 * @info: Structure containing potential arguments.
 * @vars: the string.
 * Return: 1 on delete, 0 otherwise.
 */
int _unsetenv(info_t *info, char *vars)
{
	list_t *node = info->env;
	size_t j = 0;
	char *ptr;

	if (!node || !vars)
		return (0);

	while (node)
	{
		ptr = starts_with(node->str, vars);
		if (ptr && *ptr == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable.
 * @info: Structure containing potential arguments.
 * @vars: the string of env.
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *vars, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!vars || !value)
		return (0);

	buf = malloc(_strlen(vars) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, vars);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, vars);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

