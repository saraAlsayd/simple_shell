
#ifndef _MASTER_H_
#define _MASTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;



/*proto*/

/*exit.c file*/
char *_strchr(char *str, char ch);
char *_strncpy(char *dest, char *src, int m);
char *_strncat(char *dest, char *src, int m);

/*argument.c file*/
int __exit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/*argument1.c file*/
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *s);
int set_alias(info_t *info, char *s);

/*argue.c file*/
int print_alias(list_t *node);
int _myalias(info_t *info);

/*enviro.c fillle*/
int _myenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int populate_env_list(info_t *info)

/*setenv.c fille*/
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);

/*atoi.c file*/
int interactive(info_t *info);
int is_delim(char ch, char *delim);
int _isalpha(int ch);
int _atoi(char *str);

/*error.c file*/
void _eputs(char *str);
int _eputchar(char ch);
int _putfd(char ch, int filedes);
int _putsfd(char *str, int filedes);

/*error1.c file*/
int _erratoi(char *str);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);

/*error2.c file*/
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);


/*getline.c file*/
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buf, size_t *z);

/*getline1.c file*/
int _getline(info_t *info, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused))int sig_num);

/*getenv.c file*/
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *vars);
int _setenv(info_t *info, char *vars, char *value);

/*getinfo.c file*/
void clear_info(info_t *info);
void set_info(info_t *info, char **av);
void free_info(info_t *info, int all);

/*vars.c file*/
int is_chain(info_t *info, char *buf, size_t *ptr);
void check_chain(info_t *info, char *buf, size_t *ptr, size_t x, size_t len);
int replace_alias(info_t *info);

/*vars1.c file*/
int replace_vars(info_t *info);
int replace_string(char **old, char *new);

/*token.c file*/
char **strtow(char *str, char *delim);
char **strtow2(char *str, char delim);

/*function_string.c*/
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);

/*function_string1.c*/
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char ch);

/*shell.c file*/
int hsh(info_t *info, char **av);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);

/*list.c*/
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *ptr);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

/*list1.c file*/
size_t list_len(const list_t *ptr);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *p);
list_t *node_starts_with(list_t *node, char *prefix, char ch);
ssize_t get_node_index(list_t *head, list_t *node);

/*main.c*/
int main(int ac, char **av);

/*memory.c file*/
int bfree(void **ptr);

/*path.c file*/
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);

/*alloc.c file*/
char *_memset(char *str, char b, unsigned int m);
void ffree(char **ppr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif
