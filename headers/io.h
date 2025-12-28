#ifndef _IO_H_
#define _IO_H_

#define DEFAULT_MODE "rb"
#define BUF_SIZE 2048

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	OK = 0,
	ERR_MISSING_ARG,
	ERR_SEEK,
	ERR_TELL,
	ERR_MALLOC,
	ERR_READ,
	ERR_STACK,
	ERR_CREATE,
	ERR_GNU
} ERRCODE;

FILE* safe_open(const char* filename, const char* mode);
FILE* touch_mode(const char* filename, const char* mode);
int read_file(FILE* file, char** out_buffer, size_t* out_size);

#endif
