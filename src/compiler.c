#include "compiler.h"

ERRCODE check_stack(Instruction* program, int index) {
	int stack = 0;
	for(int i = 0; i < index; i++) {
		if(program[i].op == OP_LOOP_START)
			stack++;
		if(program[i].op == OP_LOOP_END)
			stack--;
		if(stack < 0) 
			return ERR_STACK;
	}

	if(stack != 0) 
		return ERR_STACK;

	return OK;	
}

void write_bases(FILE* file) {
	fprintf(file, "%s", INCLUDES);
	fprintf(file, "%s", MAIN);
	fprintf(file, "%s", BASE);
}

int generatec(Instruction* program, const size_t size) {
	FILE* out_file = touch_mode(OUT_FILENAME, MODE);
	if(!out_file) 
		return ERR_CREATE;
	
	write_bases(out_file);

	for(int i = 0; i < size; i++) {
		
		switch(program[i].op) {
			case OP_INC_PTR:
				fprintf(out_file, "%s", INC_PTR);
				break;
			case OP_DEC_PTR:
				fprintf(out_file, "%s", DEC_PTR);
				break;
			case OP_INC:
				fprintf(out_file, "%s", INC);
				break;
			case OP_DEC:
				fprintf(out_file, "%s", DEC);
				break;
			case OP_INPUT:
				fprintf(out_file, "%s", INPUT);
				break;	
			case OP_OUTPUT:
				fprintf(out_file, "%s", OUTPUT);
				break;
			case OP_LOOP_START:
				fprintf(out_file, "%s", LOOP_START);
				break;
			case OP_LOOP_END:
				fprintf(out_file, "%s", LOOP_END);
				break;
		}
	}
	fprintf(out_file, "%s", MAIN_END);
	fclose(out_file);
	return OK;
}

int execute() {
	system("gcc -Wall bf.c -o bf.out");
	system("./bf.out");
	return OK;
}

void compile(char* buffer, const size_t MAX_INSTRUCTIONS) {
	Instruction* program = malloc(sizeof(Instruction) * MAX_INSTRUCTIONS);
	if(!program) {
		perror("malloc");
		return;
	}
	int index = 0;

	for(char* p = buffer; *p; p++) {
		switch(*p) {
			case '>': 
				program[index++].op = OP_INC_PTR; 
				break;
			case '<':
				program[index++].op = OP_DEC_PTR;
				break;
			case '+':
				program[index++].op = OP_INC;
				break;
			case '-':
				program[index++].op = OP_DEC;
				break;
			case ',':
				program[index++].op = OP_INPUT;
				break;
			case '.':
				program[index++].op = OP_OUTPUT;
				break;
			case '[':
				program[index++].op = OP_LOOP_START;
				break;
			case ']':
				program[index++].op = OP_LOOP_END;
				break;
		}
	}
	
	ERRCODE check = check_stack(program, index);
	if(check != OK) {
		free(program);
		fprintf(stderr, "%s\n", errtostr(check));
		return;
	}
	
	ERRCODE gen = generatec(program, index);
	if(gen != OK) {
		free(program);
		fprintf(stderr, "%s\n", errtostr(gen));
		return;
	}

	ERRCODE exec = execute();
	if(exec != OK) {
		free(program);
		fprintf(stderr, "%s\n", errtostr(exec));
		return;
	}
	free(program);
}
