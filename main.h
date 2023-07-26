#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/*memory free*/
int free(void **ptr);
void shell(void);
/*Write a UNIX command line interpreter*/
void execmd(char **argv);
#endif
