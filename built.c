#include "master.h"

/**
 * get_builtins - get the builtins
 * Return: pointer to a NULL-terminated statically-allocated array of builtins
 */
const builtin_t *get_builtins(void)
{
	static builtin_t builtins[] = {
		{"alias", __alias, ALIAS_HELP, ALIAS_DESC},
		{"cd", __cd, CD_HELP, CD_DESC},
		{"env", __env, ENV_HELP, ENV_DESC},
		{"exec", __exec, EXEC_HELP, EXEC_DESC},
		{"exit", __exit, EXIT_HELP, EXIT_DESC},
		{"help", __help, HELP_HELP, HELP_DESC},
		{"setenv", __setenv, SETENV_HELP, SETENV_DESC},
		{"unsetenv", __unsetenv, UNSETENV_HELP, UNSETENV_DESC},
		{0}
	};

	return (builtins);
}

/**
 * get_builtin - getting a builtin by the name.
 * @num: the name of the builtin to retrieve.
 * Return: NULL if no match, otherwise a pointer.
 */
const builtin_t *get_builtin(const char *num)
{
	const builtin_t *builtin = NULL;

	for (builtin = get_builtins(); builtin->name; builtin += 1)
	{
		if (_strcmp(num, builtin->num) == 0)
			return (builtin);
	}
	return (NULL);
}

