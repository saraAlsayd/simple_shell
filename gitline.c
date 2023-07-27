#include "master.h"

/**
 * input_buf - buffers chained command.
 * @info: the parameter struct.
 * @buf: the address of buffer.
 * @len: the address of len.
 *
 * Return: read bytes.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t k = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		k = getline(buf, &len_p, stdin);
#else
		k = _getline(info, buf, &len_p);
#endif
		if (k > 0)
		{
			if ((*buf)[k - 1] == '\n')
			{
				(*buf)[k - 1] = '\0'; /* remove trailing newline */
				k--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = k;
				info->cmd_buf = buf;
			}
		}
	}
	return (k);
}

/**
 * get_input - getting  line minus newline.
 * @info: the parameter.
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t x, y, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		y = x; /* init new iterator to current buf position */
		p = buf + x; /* get pointer for return */

		check_chain(info, buf, &y, x, len);
		while (y < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &y))
				break;
			y++;
		}

		x = y + 1; /* increment past nulled ';'' */
		if (x >= len) /* reached end of buffer? */
		{
			x = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reading the buffer
 * @info: the parameter.
 * @buf: the buffer.
 * @z: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *z)
{
	ssize_t r = 0;

	if (*z)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*z = r;
	return (r);
}

