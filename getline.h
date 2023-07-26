#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <unistd.h>

#include "string.h"

#define BUFFER_SIZE 4096

/**
 * struct buf_s - input buffer from user
 * @buffer: the buffer of the line
 * @next: pointer to thhe value
 * @remaining: number of value
 */
typedef struct buf_s
{
	char buffer[BUFFER_SIZE];
	char *link;
	size_t remaining;
} buf_t;

#define TABLE_SIZE 127

/**
 * struct buf_table_node_s - input buffer hash table
 * @fd: file descriptor
 * @buf: associated buffer of the value
 * @next: next buffer 
 */
typedef struct buf_table_node_s
{
	int fd;
	struct buf_s buf;
	struct buf_table_node_s *link;
} buf_table_node_t;

typedef buf_table_node_t *buf_table_t[TABLE_SIZE];

char *_getline(const int ff);

#endif
