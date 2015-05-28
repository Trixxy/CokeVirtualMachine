#include <cstdio>
#include <vector>
#include <fstream>
#include <fcntl.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <deque>
#include <cassert>
#include "ClassFile.h"
#include "FileHandler.h"
#include "FramedStack.h"
#include "ProgramCode.h"
#include "CPU.h"
#include "RunTimeEnvironment.h"
#include "MethodInfo.h"

int main(int argc, char **argv){
	if(argc <= 1){
		fprintf(stderr, "Error: at least one file is required.\n");
		return 1;
	}

	RunTimeEnvironment RTE;


	MethodInfo * main = NULL;
	for(int i = 1; i < argc; i++){
		auto current_class = new ClassFile(std::string(argv[i]));
		// current_class->print();
		if(main == NULL) main = current_class->get_method("main");
		RTE.add_class(current_class);
	}

	if(main == NULL){
		fprintf(stderr, "Couldn't find main.\n");
		return 1;
	}

	RTE.link();

//	RTE.print_all_classes();

	CPU cpu;
	cpu.set_environment(&RTE);
	cpu.start(main);

	// for(int i = 0; i < program.size(); i++){
	// 	std::cout << "[" << std::setfill ('0') << std::setw(4) << std::dec << i << "]: " 
	// 	<< std::setfill('0') << std::setw(2) << std::hex << instruction_tt[program[i]] << std::endl;
	// }

	return 0;
}
