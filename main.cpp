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


// #include "DefConstTrans.h"
// #include "ConstantPool.h"

// inline int exec(const byte & code){
// 	if(NULL == exec_map[code]){
// 		std::cerr << "Error: byte code [" << instruction_tt[code] << "] is not supported, yet...\n";
// 		return -1;
// 	}else{
// 		exec_map[code]();
// 		return 0;
// 	}
// }

int main(int argc, char **argv){
	if(argc <= 1){
		fprintf(stderr, "Error: at least one file is required.\n");
		return 1;
	}

	ClassFile cf = ClassFile(std::string(argv[1]));

	cf.print();

	// println(cf.get_code_handler());
	assert(cf.get_fh().size() == cf.get_fh().get_cc());

	ProgramCode pc;
	CPU().run(&pc);

	// for(int i = 0; i < program.size(); i++){
	// 	std::cout << "[" << std::setfill ('0') << std::setw(4) << std::dec << i << "]: " 
	// 	<< std::setfill('0') << std::setw(2) << std::hex << instruction_tt[program[i]] << std::endl;
	// }

	return 0;
}
