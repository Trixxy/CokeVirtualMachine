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

int main(int argc, char **argv){
	if(argc <= 1){
		fprintf(stderr, "Error: at least one file is required.\n");
		return 1;
	}

	RunTimeEnvironment RTE;

	for(int i = 1; i < argc; i++){
		auto current_class = new ClassFile(std::string(argv[i]));
		current_class->print();
		RTE.add_class(current_class);
	}

	RTE.link();

	// ProgramCode pc;
	// CPU().run(&pc);

	// for(int i = 0; i < program.size(); i++){
	// 	std::cout << "[" << std::setfill ('0') << std::setw(4) << std::dec << i << "]: " 
	// 	<< std::setfill('0') << std::setw(2) << std::hex << instruction_tt[program[i]] << std::endl;
	// }

	return 0;
}
