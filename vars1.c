#include "master.h"

/**
 * replace_vars - replacing vars in the tokenized.
 * @info: parameter struct
 *
 * Return: 1 if it replaced, 0 other.
 */
int replace_vars(info_t *info)
{
	int j = 0;
	list_t *node;

	for (j = 0; info->argv[j]; j++)
	{
		if (info->argv[j][0] != '$' || !info->argv[j][1])
			continue;

		if (!_strcmp(info->argv[j], "$?"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[j], "$$"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[j][1], '=');
		if (node)
		{
			replace_string(&(info->argv[j]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[j], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replacing the string
 * @old: that ia a address of old string
 * @new: this is a new string
 *
 * Return: 1 if it  replacing, 0 other.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

