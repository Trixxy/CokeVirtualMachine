#ifndef _VM_PROGRAM_CODE_H_
#define _VM_PROGRAM_CODE_H_

#include <vector>
#include "DefConstTrans.h"

class ProgramCode{
    std::vector<unsigned int> code = {
        vm_iconst_2,
        vm_istore_1,
        vm_ldc,
        400,
        vm_iconst_3,
        vm_istore,
        vm_iload_3,
        vm_iload_1,
        vm_iadd
    };

public:
    unsigned int pc;
    ProgramCode():pc(0){}

    byte next_inst(){
        return code[pc++];
    }
    bool has_next(){
        return (pc != code.size());
    }

    byte get_u1() {
        return code[pc++];
    }
    unsigned int get_u4() {
        return code[pc++];
    }
};

#endif 
