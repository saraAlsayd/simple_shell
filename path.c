#include "master.h"

/**
 * is_cmd - determining if a file executable.
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat str;

	(void)info;
	if (!path || stat(path, &str))
		return (0);

	if (str.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}


/**
 * dup_chars - duplicatting characters
 * @pathstr: the PATH.
 * @start: starting.
 * @stop: stopping.
 *
 * Return: pointer.
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[y++] = pathstr[x];
	buf[y] = 0;
	return (buf);
}

/**
 * find_path - finds=ing the cmd of PATH.
 * @info: info struct.
 * @pathstr: PATH string.
 * @cmd: cmd to find.
 *
 * Return: path of cmd.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
	char *pathc;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			pathc = dup_chars(pathstr, curr_pos, x);
			if (!*pathc)
				_strcat(pathc, cmd);
			else
			{
				_strcat(pathc, "/");
				_strcat(pathc, cmd);
			}
			if (is_cmd(info, pathc))
				return (pathc);
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
	}
	return (NULL);
}

