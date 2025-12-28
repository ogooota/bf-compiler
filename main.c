#include "call.h"
#include "main.h"

int main(int argc, char* argv[]) {
	int opt;
	bool help_flag = false, compile_flag = false;
	char* filename = NULL;

	while((opt = getopt(argc, argv, "hc:")) != -1) {
		switch(opt) {
			case 'h':
				help_flag = true;
				break;
			case 'c':
				compile_flag = true;
				filename = optarg;
				break;
			default:
				fprintf(stderr, "unknown command: %c\n", opt);
				break;
		}
	}

	if(help_flag) 
		help_caller();
	
	if(compile_flag)
		compile_caller(filename);
	return 0;
}
