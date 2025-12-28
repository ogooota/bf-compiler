#include "io.h"
#include "call.h"
#include "compiler.h"

const char* commands[] = {
	"-h: help",
	"-c <FILENAME>: compiles .bf file"
};

int commands_size = sizeof(commands) / sizeof(commands[0]);

char* errtostr(ERRCODE err) {
	switch(err) {
		case OK:
			return "OK";
		case ERR_MISSING_ARG:
			return "compiler: missing args";
		case ERR_SEEK:
			return "compiler: seek error";
		case ERR_TELL:
			return "compiler: tell error";
		case ERR_MALLOC:
			return "compiler: memory allocation error";
		case ERR_READ:
			return "compiler: read error";
		case ERR_STACK:
			return "compiler: loop starting and not ending / ending and not starting";
		case ERR_CREATE:
			return "compiler: couldn't create source file";
		case ERR_GNU:
			return "compiler: couldn't compile c code";
		default:
			return "";	
	}
}

int index_max_size() {
	int max = 0, now;
	for(int i = 0; i < commands_size; i++) { 
		now = strlen(commands[i]);
		if(now > max)
			max = now;
	}
	return max;
}

void print_help() {
	int max_index = index_max_size();
	for(int i = 0; i < commands_size; i++) {
		int spaces = max_index - strlen(commands[i]);
		printf("### %s ", commands[i]);
		for(int j = 0; j < spaces; j++)
			putchar(' ');
		printf("###\n");
	}
}

void help_caller() {
	print_help();	
}

void print_buffer(char* buf, size_t size) {
	for(size_t i = 0; i < size; i++) 
		printf("%c", buf[i]);
}

void compile_caller(const char* filename) {
	ERRCODE err;
	char* buffer;
	size_t out_size;

	FILE* file = safe_open(filename, DEFAULT_MODE);
	if(!file) {
		fprintf(stderr, "compiler: could not open file\n");
		exit(1);
	}
	
	err = read_file(file, &buffer, &out_size);
	if(err != OK) {
		fprintf(stderr, "%s\n", errtostr(err));
		exit(1);
	}

	compile(buffer, out_size + 1);
}

