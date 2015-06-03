#include <cstdio>
#include "CokeMachine.h"

/**
 * Just a little sparker to get everyting started,
 * nothing much to see here, just initialize a new machine
 * and give it the name of files to load.
 */
int main(int argc, char **argv){
	if(argc <= 1){
		fprintf(stderr, "Error: at least one file is required.\n");
		return 1;
	}

	CokeMachine cokeMachine;

	for(int i = 1; i < argc; i++){
		cokeMachine.add_class(std::string(argv[i]));
	}

	cokeMachine.start();

	return 0;
}
