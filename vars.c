#include "master.h"

/**
 * is_chain - test if current char in buffer of the chain delimeter.
 * @info: the parameter.
 * @buf: the char.
 * @ptr: the address of current position.
 *
 * Return: 1 if chain delimeter, 0 other.
 */
int is_chain(info_t *info, char *buf, size_t *ptr)
{
	size_t j = *ptr;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = j;
	return (1);
}

/**
 * check_chain - checking  continue chaining based on last status
 * @info: parameter struct
 * @buf: char buffer
 * @ptr: the address of the current position.
 * @x: starting position.
 * @len: the length of buf.
 *
 * Return: Void (no thing).
 */
void check_chain(info_t *info, char *buf, size_t *ptr, size_t x, size_t len)
{
	size_t y = *ptr;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[x] = 0;
			y = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[x] = 0;
			y = len;
		}
	}

	*ptr = y;
}

/**
 * replace_alias - replacing an aliases in the string.
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 other.
 */
int replace_alias(info_t *info)
{
	int j;
	list_t *node;
	char *ptr;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ptr = _strchr(node->str, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		info->argv[0] = ptr;
	}
	return (1);
}

