#include "io.h"
#include "compiler.h"

FILE* safe_open(const char* filename, const char* mode) {
	if(!filename || !mode) 
		return NULL;
	
	FILE* file = fopen(filename, mode);
	if(!file) 
		return NULL;
	
	return file;
}

FILE* touch_mode(const char* filename, const char* mode) {
	FILE* file = safe_open(filename, mode);
	if(!file) 
		return NULL;
	return file;
}

int read_file(FILE* file, char** out_buffer, size_t* out_size) {
	char* buffer;
	size_t file_size;

	if(!file || !out_buffer || !out_size)
		return ERR_MISSING_ARG;
		
	if(fseek(file, 0, SEEK_END) != 0)
		return ERR_SEEK;

	long size;	
	if((size = ftell(file)) < 0)
		return ERR_TELL;

	file_size = (size_t)size;
	rewind(file);

	buffer = malloc(file_size + 1);
	if(!buffer)
		return ERR_MALLOC;

	size_t read = fread(buffer, 1, file_size, file);
	if(read != file_size) {
		free(buffer);
		return ERR_READ;
	}
	
	buffer[file_size] = '\0';
	*out_buffer = buffer;
	*out_size = file_size;
	return OK;
}







