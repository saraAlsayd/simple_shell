#include "master.h"
/**
 * _echo - function echo the input
 *
 * @av: list of arguments
 *
 * Return: 0
 */
int _echo(char **avs)
{
	int pid;

	if (av[2])
		write(2, "enter yor argument\n", 20);
	else
	{
		if (_strcmp(":)", av[1]) == 0)
		{
			pid = getpid();
			_printf("%i\n", pid);
		}
		else
			_printf("%s\n", av[1]);
	}
	return (0);
}
