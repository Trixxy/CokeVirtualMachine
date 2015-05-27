#ifndef _VM_PROGRAM_CODE_H_
#define _VM_PROGRAM_CODE_H_

#include <vector>
#include "DefConstTrans.h"

class ProgramCode{
    friend class ac_Code;

    unsigned int pc;
    std::vector<unsigned int> code;
    //  = {
    //     vm_iconst_0,
    //     vm_ifeq,
    //     0x00,
    //     0x02,
    //     vm_iconst_1,
    //     vm_iconst_2,
    //     vm_iadd
    // };

public:
    ProgramCode():pc(0), code(std::vector<unsigned int>()){}

    byte next_inst(){
        return code[pc++];
    }
    bool has_next(){
        return (pc != code.size());
    }

    unsigned int get_u1() {
        return code[pc++];
    }

    unsigned int get_u2() {
        unsigned int res = 0;
        for(int i = 0; i < 2; i++){
            res = res << 8 | get_u1();
        }
        return res;
    }

    unsigned int get_u4() {
        unsigned int res = 0;
        for(int i = 0; i < 4; i++){
            res = res << 8 | get_u1();
        }
        return res;
    }

    unsigned long long int get_u8() {
        unsigned long long int res = 0;
        for(int i = 0; i < 8; i++){
            res = res << 8 | get_u1();
        }
        return res;
    }

    const unsigned int & get_pc(){
        return pc;
    }

    void jump(int offset) {
        pc += offset; /* TODO: Double check */
    }
};

#endif 
