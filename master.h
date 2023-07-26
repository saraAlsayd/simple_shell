
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


/*proto*/

/*exit.c file*/
char *_strchr(char *str, char ch);
char *_strncpy(char *dest, char *src, int m);
char *_strncat(char *dest, char *src, int m);


#endif
