#ifndef _VM_PROGRAM_CODE_H_
#define _VM_PROGRAM_CODE_H_

#include <vector>
#include "DefConstTrans.h"

/**
 * \brief This class contains code and provides functionality to operate on that code.
 */
class ProgramCode{
    friend class ac_Code;

    unsigned int pc;
    std::vector<unsigned int> code;

public:
    /**
     * Initialize a ProgramCode.
     */
    ProgramCode():pc(0), code(std::vector<unsigned int>()){}

    /**
     * Returns next instruction and sets the program counter to point to next instruction.
     */
    byte next_inst(){
        return code[pc++];
    }

    /**
     * Returns true when there are more instructions.
     */
    bool has_next(){
        return (pc != code.size());
    }

    /**
     * Returns one byte from the code and sets the counter accordingly.
     */
    unsigned int get_u1() {
        return code[pc++];
    }

    /**
     * Returns two bytes from the code and sets the counter accordingly.
     */
    unsigned int get_u2() {
        unsigned int res = 0;
        for(int i = 0; i < 2; i++){
            res = res << 8 | get_u1();
        }
        return res;
    }

    /**
     * Returns four bytes from the code and sets the counter accordingly.
     */
    unsigned int get_u4() {
        unsigned int res = 0;
        for(int i = 0; i < 4; i++){
            res = res << 8 | get_u1();
        }
        return res;
    }

    /**
     * Returns eight bytes from the code and sets the counter accordingly.
     */
    unsigned long long int get_u8() {
        unsigned long long int res = 0;
        for(int i = 0; i < 8; i++){
            res = res << 8 | get_u1();
        }
        return res;
    }

    /**
     * Returns the program counter (e.g. the position of the next instruction).
     */
    const unsigned int & get_pc(){
        return pc;
    }

    /**
     * Moves the program counter by the specified offset.
     */
    void jump(int offset) {
        pc += offset;
    }

    /**
     * Moves the program counter to the end of the code,
     * handy in case of early termination (hence the name).
     */
    void terminate(){
    	pc = code.size();
    }
};

#endif 
