#ifndef _COMPILER_H_
#define _COMPILER_H_

#include "call.h"

#define OUT_FILENAME "bf.c"
#define MODE "w"

#define INCLUDES "#include <stdio.h>\n\n"
#define MAIN "int main() {\n"
#define BASE "    unsigned char mem[30000] = {0};\n    unsigned char* p = mem;\n"
#define MAIN_END "    return 0;\n}"

#define INC_PTR "    p++;\n"
#define	DEC_PTR "    p--;\n"
#define	INC "    (*p)++;\n"
#define	DEC "    (*p)--;\n"
#define	INPUT "    *p = getchar();\n"
#define	OUTPUT "    putchar(*p);\n"
#define	LOOP_START "    while(*p) {\n"
#define	LOOP_END "    }\n"

typedef enum {
	OP_INC_PTR,
	OP_DEC_PTR,
	OP_INC,
	OP_DEC,
	OP_INPUT,
	OP_OUTPUT,
	OP_LOOP_START,
	OP_LOOP_END
} OpCode;

typedef struct {
	int argument;
	OpCode op;
} Instruction;

ERRCODE check_stack(Instruction* program, int index);
void compile(char* buffer, const size_t MAX_INSTRUCTIONS);
void write_bases(FILE* file);
int generatec(Instruction* program, const size_t size);
int execute();

#endif
