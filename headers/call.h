#ifndef _CALL_H_
#define _CALL_H_

#include "io.h"

#include <string.h>
#include <stdio.h>


char* errtostr(ERRCODE err);
int index_max_size();
void help_caller();
void print_help();
void compile_caller(const char* filename);

#endif
