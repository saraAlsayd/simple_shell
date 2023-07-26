#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * execmd: the function using system call
 * */
void execmd(char **argv)
{
char *command;
if (argv)
{
command = argv[0];
if (execve(command, argv, NULL) == -1)
{
perror("Error:");
};
}
}
