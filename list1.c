#include "master.h"

/**
 * list_len - determin length of linked.
 * @ptr: pointer to first node.
 *
 * Return: size of list
 */
size_t list_len(const list_t *ptr)
{
	size_t j = 0;

	while (ptr)
	{
		ptr = ptr->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - returning an array of the strings.
 * @head: the pointer.
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t x = list_len(head), y;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (y = 0; y < x; y++)
				free(strs[y]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}


/**
 * print_list - printing all elements.
 * @p: pointer to first node
 *
 * Return: size the list.
 */
size_t print_list(const list_t *p)
{
	size_t x = 0;

	while (p)
	{
		_puts(convert_number(p->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		x++;
	}
	return (x);
}

/**
 * node_starts_with - returning node whose string.
 * @node: the pointer to list.
 * @prefix: the string to match.
 * @ch: the next character.
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char ch)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = starts_with(node->str, prefix);
		if (ptr && ((ch == -1) || (*ptr == ch)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - getting the index of the node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: the index or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t k = 0;

	while (head)
	{
		if (head == node)
			return (k);
		head = head->next;
		k++;
	}
	return (-1);
}

