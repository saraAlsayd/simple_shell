#ifndef _MASTER_H_
#define _MASTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>

#define ALIAS_HELP "alias [KEY[=VALUE] ...]"
#define ALIAS_DESC   \
	"Define + display aliases.\n\0"	\
	"If have not arguments, existing the alias are.\0"\
	"Otherwise, an alias is defined for each KEY=VALUE pair provided.\0"\
	"For each KEY with no VALUE the alias is displayed.\0"\
	"If VALUE ends with a space, will be expanded.\0"\
	"\0"

#define CD_HELP "cd [DIR]"
#define CD_DESC									\
	"Change the current working directory to DIR.\n\0"\
	"If DIR is omitted, it defaults to the value .\0"\
	"If DIR is -, the current directory reverts to its previous.\0"\
	"\0"

#define ENV_HELP "env"
#define ENV_DESC   \
	"Print the environment.\0" \
	"\0"

#define EXEC_HELP "exec COMMAND [ARGS ...]"
#define EXEC_DESC								\
	"Replace the shell with th command.\n\0"\
	"COMMAND is executed, replacing shell the executing.\0"	\
	"ARGS are passed as positional the arguments.\0" \
	"If the command cannot be executed, exits.\0" \
	"\0"

#define EXIT_HELP "exit [STATUS]"
#define EXIT_DESC								\
	"Exit the shell with a status of STATUS.\n\0"	\
	"If STATUS is omitted, the exit status in last command.\0"	\
	"\0"

#define HELP_HELP "help [BUILTIN]"
#define HELP_DESC								\
	"Display information of builtin.\n\0"	\
	"If BUILTIN is omitted, display the available.\0"	\
	"\0"

    #define SETENV_HELP "setenv [NAME [VALUE]]"
#define SETENV_DESC								\
	"Set the environment variable NAME to VALUE.\n\0"	\
	"If NAME is omitted, displayed  the shell execution.\0"	\
	"If the VALUE is omitted, the NAME is set to an empty string.\0" \
	"\0"

#define UNSETENV_HELP "unsetenv NAME"
#define UNSETENV_DESC								\
	"Remove the variable NAME .\0"	\
	"\0"
#define SIZEBUFFER 1024;
void shell();
    
typedef int (*builtin_fp)(info_t *);
typedef dict_t env_t;
extern char **environ;
typedef struct builtin builtin_t;
typedef struct cmdlist cmdlist_t;
typedef struct cmdtree cmdtree_t;
typedef struct dict dict_t;
typedef struct history history_t;
typedef struct info info_t;
typedef struct list list_t;
typedef dict_t alias_t;


/**
 * struct builtin - builtin command
 * @name: command name
 * @f: function to call
 * @help: command usage
 * @desc: command description
 */
struct builtin
{
	const char *name;
	builtin_fp f;
	const char *help;
	const char *desc;
};
/**
  * struct info - shell state
  * @interactive: arguments passed
  * @argc: arguments passed
  * @argv: arguments passed
  * @file: arguments passed
  * @fileno: arguments passed
  * @status: arguments passed
  * @line: arguments passed
  * @lineno: arguments passed
  * @tokens: arguments passed
  * @pid: arguments passed
  * @cwd: arguments passed
  * @exe: arguments passed
  * @env: arguments passed
  * @path: arguments passed
  * @aliases: arguments passed
  * @history: arguments passed
  * @commands: arguments passed
  */

 struct info
{
	int interactive;
	int argc;
	char **argv;
	char *file;
	int fileno;
	int status;
	char *line;
	size_t lineno;
	char **tokens;
	pid_t pid;
	char *cwd;
	char *exe;
	env_t *env;
	list_t *path;
	alias_t *aliases;
	history_t *history;
	cmdlist_t *commands;
};



    /*protos*/

    /*built.c file*/
    const struct builtin *get_builtin(const char *num);
    const struct builtin *get_builtins(void);

    /*alias.c file*/
    void __alias_add(alias_t **aliases, const char *num, const char *value);
    void __alias_print(alias_t *alias);
    int __alias(info_t *info);

    /*cd.c file*/
    void __cd_error(info_t *info, char *dir);
    void __cd_success(info_t *info)
    int __cd(info_t *info);

    /*env.c file*/
    int __env(info_t *info);
    int __exec(info_t *info);

    /*hell.c*/
    int __help(struct info *info);

    /*exit.c file*/
    int __exit(info_t *info);

    /*setenv file*/
    int __setenv(info_t *info);

    /*unsetnev file*/
    int __unsetenv(info_t *info);
    /*echo*/
    int _echo(char **avs);
    /*memory free*/
    int free(void **ptr);
    void shell(void);
    /*Write a UNIX command line interpreter*/
    void execmd(char **argv);
    #endif

