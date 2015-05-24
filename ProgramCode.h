#ifndef _VM_PROGRAM_CODE_H_
#define _VM_PROGRAM_CODE_H_

#include <vector>
#include "DefConstTrans.h"

class ProgramCode{
	std::vector<unsigned int> code = {
		vm_iconst_1,
		vm_iconst_2,
		vm_iadd,
		vm_ldc,
		100
	};

public:
	unsigned int pc;
	ProgramCode():pc(0){}

	byte next_inst(){
		return code[pc++];
	}
	bool has_next(){
		return !(pc == code.size());
	}
};

#endif 