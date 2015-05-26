#ifndef _VM_CPU_H_
#define _VM_CPU_H_

#include <deque>
#include "ProgramCode.h"
#include "FramedStack.h"

class CPU{
    FramedStack stack;
    ProgramCode * pc;
    void (CPU::*exec_map[256])(void);
public:
    //TODO take pc as parameter when done.
    CPU():stack(FramedStack()){ link_exec_map(); }
    void run(ProgramCode * _pc){
        pc = _pc;
        stack.push_frame(2);
            
        while(pc->has_next()){
            (this->*exec_map[pc->next_inst()])();
        }
        printf("Final result: %u\n", stack.pop());

        stack.pop_frame();
    }

private:
    inline void vm_nop(){/* TO BE IMPLEMENTED */}
    inline void vm_aconst_null(){/* TO BE IMPLEMENTED */}
    inline void vm_iconst_m1(){
        stack.push(-1);
    }
    inline void vm_iconst_0(){
        stack.push(0);
    }
    inline void vm_iconst_1(){
        stack.push(1);
    }
    inline void vm_iconst_2(){
        stack.push(2);
    }
    inline void vm_iconst_3(){
        stack.push(3);
    }
    inline void vm_iconst_4(){
        stack.push(4);
    }
    inline void vm_iconst_5(){
        stack.push(5);
    }
    inline void vm_lconst_0(){/* TO BE IMPLEMENTED */}
    inline void vm_lconst_1(){/* TO BE IMPLEMENTED */}
    inline void vm_fconst_0(){/* TO BE IMPLEMENTED */}
    inline void vm_fconst_1(){/* TO BE IMPLEMENTED */}
    inline void vm_fconst_2(){/* TO BE IMPLEMENTED */}
    inline void vm_dconst_0(){/* TO BE IMPLEMENTED */}
    inline void vm_dconst_1(){/* TO BE IMPLEMENTED */}
    inline void vm_bipush(){
        unsigned int byte = pc->get_u1();
        stack.push(byte);        
    }
    inline void vm_sipush(){/* TO BE IMPLEMENTED */}
    inline void vm_ldc(){
        unsigned int val = pc->get_u4();
        stack.push(val);
    }
    inline void vm_ldc_w(){/* TO BE IMPLEMENTED */}
    inline void vm_ldc2_w(){/* TO BE IMPLEMENTED */}
    inline void vm_iload(){
        unsigned int index = stack.pop();
        stack.push(stack[index]);
    }
    inline void vm_lload(){/* TO BE IMPLEMENTED */}
    inline void vm_fload(){/* TO BE IMPLEMENTED */}
    inline void vm_dload(){/* TO BE IMPLEMENTED */}
    inline void vm_aload(){/* TO BE IMPLEMENTED */}
    inline void vm_iload_0(){
        stack.push(stack[0]);
    }
    inline void vm_iload_1(){
        stack.push(stack[1]);
    }
    inline void vm_iload_2(){
        stack.push(stack[2]);
    }
    inline void vm_iload_3(){
        stack.push(stack[3]);
    }
    inline void vm_lload_0(){/* TO BE IMPLEMENTED */}
    inline void vm_lload_1(){/* TO BE IMPLEMENTED */}
    inline void vm_lload_2(){/* TO BE IMPLEMENTED */}
    inline void vm_lload_3(){/* TO BE IMPLEMENTED */}
    inline void vm_fload_0(){/* TO BE IMPLEMENTED */}
    inline void vm_fload_1(){/* TO BE IMPLEMENTED */}
    inline void vm_fload_2(){/* TO BE IMPLEMENTED */}
    inline void vm_fload_3(){/* TO BE IMPLEMENTED */}
    inline void vm_dload_0(){/* TO BE IMPLEMENTED */}
    inline void vm_dload_1(){/* TO BE IMPLEMENTED */}
    inline void vm_dload_2(){/* TO BE IMPLEMENTED */}
    inline void vm_dload_3(){/* TO BE IMPLEMENTED */}
    inline void vm_aload_0(){/* TO BE IMPLEMENTED */}
    inline void vm_aload_1(){/* TO BE IMPLEMENTED */}
    inline void vm_aload_2(){/* TO BE IMPLEMENTED */}
    inline void vm_aload_3(){/* TO BE IMPLEMENTED */}
    inline void vm_iaload(){/* TO BE IMPLEMENTED */}
    inline void vm_laload(){/* TO BE IMPLEMENTED */}
    inline void vm_faload(){/* TO BE IMPLEMENTED */}
    inline void vm_daload(){/* TO BE IMPLEMENTED */}
    inline void vm_aaload(){/* TO BE IMPLEMENTED */}
    inline void vm_baload(){/* TO BE IMPLEMENTED */}
    inline void vm_caload(){/* TO BE IMPLEMENTED */}
    inline void vm_saload(){/* TO BE IMPLEMENTED */}
    inline void vm_istore(){
        unsigned int index = stack.pop();
        unsigned int val = stack.pop();
        stack[index] = val;
    }
    inline void vm_lstore(){/* TO BE IMPLEMENTED */}
    inline void vm_fstore(){/* TO BE IMPLEMENTED */}
    inline void vm_dstore(){/* TO BE IMPLEMENTED */}
    inline void vm_astore(){/* TO BE IMPLEMENTED */}
    inline void vm_istore_0(){
        unsigned int val = stack.pop();
        stack[0] = val;
    }
    inline void vm_istore_1(){
        unsigned int val = stack.pop();
        stack[1] = val;
    }
    inline void vm_istore_2(){
        unsigned int val = stack.pop();
        stack[2] = val;
    }
    inline void vm_istore_3(){
        unsigned int val = stack.pop();
        stack[3] = val;
    }
    inline void vm_lstore_0(){/* TO BE IMPLEMENTED */}
    inline void vm_lstore_1(){/* TO BE IMPLEMENTED */}
    inline void vm_lstore_2(){/* TO BE IMPLEMENTED */}
    inline void vm_lstore_3(){/* TO BE IMPLEMENTED */}
    inline void vm_fstore_0(){/* TO BE IMPLEMENTED */}
    inline void vm_fstore_1(){/* TO BE IMPLEMENTED */}
    inline void vm_fstore_2(){/* TO BE IMPLEMENTED */}
    inline void vm_fstore_3(){/* TO BE IMPLEMENTED */}
    inline void vm_dstore_0(){/* TO BE IMPLEMENTED */}
    inline void vm_dstore_1(){/* TO BE IMPLEMENTED */}
    inline void vm_dstore_2(){/* TO BE IMPLEMENTED */}
    inline void vm_dstore_3(){/* TO BE IMPLEMENTED */}
    inline void vm_astore_0(){/* TO BE IMPLEMENTED */}
    inline void vm_astore_1(){/* TO BE IMPLEMENTED */}
    inline void vm_astore_2(){/* TO BE IMPLEMENTED */}
    inline void vm_astore_3(){/* TO BE IMPLEMENTED */}
    inline void vm_iastore(){/* TO BE IMPLEMENTED */}
    inline void vm_lastore(){/* TO BE IMPLEMENTED */}
    inline void vm_fastore(){/* TO BE IMPLEMENTED */}
    inline void vm_dastore(){/* TO BE IMPLEMENTED */}
    inline void vm_aastore(){/* TO BE IMPLEMENTED */}
    inline void vm_bastore(){/* TO BE IMPLEMENTED */}
    inline void vm_castore(){/* TO BE IMPLEMENTED */}
    inline void vm_sastore(){/* TO BE IMPLEMENTED */}
    inline void vm_pop(){
        stack.pop();
    }
    inline void vm_pop2(){/* TO BE IMPLEMENTED */}
    inline void vm_dup(){/* TO BE IMPLEMENTED */}
    inline void vm_dup_x1(){/* TO BE IMPLEMENTED */}
    inline void vm_dup_x2(){/* TO BE IMPLEMENTED */}
    inline void vm_dup2(){/* TO BE IMPLEMENTED */}
    inline void vm_dup2_x1(){/* TO BE IMPLEMENTED */}
    inline void vm_dup2_x2(){/* TO BE IMPLEMENTED */}
    inline void vm_swap(){/* TO BE IMPLEMENTED */}
    inline void vm_iadd(){
        int val1 = (int) stack.pop();
        int val2 = (int) stack.pop();
        int res = val1 + val2;
        stack.push(res);
    }
    inline void vm_ladd(){/* TO BE IMPLEMENTED */}
    inline void vm_fadd(){/* TO BE IMPLEMENTED */}
    inline void vm_dadd(){/* TO BE IMPLEMENTED */}
    inline void vm_isub(){
        int val1 = (int) stack.pop();
        int val2 = (int) stack.pop();
        int res = val1 - val2;
        stack.push(res);
    }
    inline void vm_lsub(){/* TO BE IMPLEMENTED */}
    inline void vm_fsub(){/* TO BE IMPLEMENTED */}
    inline void vm_dsub(){/* TO BE IMPLEMENTED */}
    inline void vm_imul(){
        int val1 = (int) stack.pop();
        int val2 = (int) stack.pop();
        int res = val1 * val2;
        stack.push(res);
    }
    inline void vm_lmul(){/* TO BE IMPLEMENTED */}
    inline void vm_fmul(){/* TO BE IMPLEMENTED */}
    inline void vm_dmul(){/* TO BE IMPLEMENTED */}
    inline void vm_idiv(){
        int val1 = (int) stack.pop();
        int val2 = (int) stack.pop();
        int res = val1 / val2;
        stack.push(res);
    }
    inline void vm_ldiv(){/* TO BE IMPLEMENTED */}
    inline void vm_fdiv(){/* TO BE IMPLEMENTED */}
    inline void vm_ddiv(){/* TO BE IMPLEMENTED */}
    inline void vm_irem(){/* TO BE IMPLEMENTED */}
    inline void vm_lrem(){/* TO BE IMPLEMENTED */}
    inline void vm_frem(){/* TO BE IMPLEMENTED */}
    inline void vm_drem(){/* TO BE IMPLEMENTED */}
    inline void vm_ineg(){/* TO BE IMPLEMENTED */}
    inline void vm_lneg(){/* TO BE IMPLEMENTED */}
    inline void vm_fneg(){/* TO BE IMPLEMENTED */}
    inline void vm_dneg(){/* TO BE IMPLEMENTED */}
    inline void vm_ishl(){/* TO BE IMPLEMENTED */}
    inline void vm_lshl(){/* TO BE IMPLEMENTED */}
    inline void vm_ishr(){/* TO BE IMPLEMENTED */}
    inline void vm_lshr(){/* TO BE IMPLEMENTED */}
    inline void vm_iushr(){/* TO BE IMPLEMENTED */}
    inline void vm_lushr(){/* TO BE IMPLEMENTED */}
    inline void vm_iand(){/* TO BE IMPLEMENTED */}
    inline void vm_land(){/* TO BE IMPLEMENTED */}
    inline void vm_ior(){/* TO BE IMPLEMENTED */}
    inline void vm_lor(){/* TO BE IMPLEMENTED */}
    inline void vm_ixor(){/* TO BE IMPLEMENTED */}
    inline void vm_lxor(){/* TO BE IMPLEMENTED */}
    inline void vm_iinc(){/* TO BE IMPLEMENTED */}
    inline void vm_i2l(){/* TO BE IMPLEMENTED */}
    inline void vm_i2f(){/* TO BE IMPLEMENTED */}
    inline void vm_i2d(){/* TO BE IMPLEMENTED */}
    inline void vm_l2i(){/* TO BE IMPLEMENTED */}
    inline void vm_l2f(){/* TO BE IMPLEMENTED */}
    inline void vm_l2d(){/* TO BE IMPLEMENTED */}
    inline void vm_f2i(){/* TO BE IMPLEMENTED */}
    inline void vm_f2l(){/* TO BE IMPLEMENTED */}
    inline void vm_f2d(){/* TO BE IMPLEMENTED */}
    inline void vm_d2i(){/* TO BE IMPLEMENTED */}
    inline void vm_d2l(){/* TO BE IMPLEMENTED */}
    inline void vm_d2f(){/* TO BE IMPLEMENTED */}
    inline void vm_i2b(){/* TO BE IMPLEMENTED */}
    inline void vm_i2c(){/* TO BE IMPLEMENTED */}
    inline void vm_i2s(){/* TO BE IMPLEMENTED */}
    inline void vm_lcmp(){/* TO BE IMPLEMENTED */}
    inline void vm_fcmpl(){/* TO BE IMPLEMENTED */}
    inline void vm_fcmpg(){/* TO BE IMPLEMENTED */}
    inline void vm_dcmpl(){/* TO BE IMPLEMENTED */}
    inline void vm_dcmpg(){/* TO BE IMPLEMENTED */}
    inline void vm_ifeq(){/* TO BE IMPLEMENTED */}
    inline void vm_ifne(){/* TO BE IMPLEMENTED */}
    inline void vm_iflt(){/* TO BE IMPLEMENTED */}
    inline void vm_ifge(){/* TO BE IMPLEMENTED */}
    inline void vm_ifgt(){/* TO BE IMPLEMENTED */}
    inline void vm_ifle(){/* TO BE IMPLEMENTED */}
    inline void vm_if_icmpeq(){/* TO BE IMPLEMENTED */}
    inline void vm_if_icmpne(){/* TO BE IMPLEMENTED */}
    inline void vm_if_icmplt(){/* TO BE IMPLEMENTED */}
    inline void vm_if_icmpge(){/* TO BE IMPLEMENTED */}
    inline void vm_if_icmpgt(){/* TO BE IMPLEMENTED */}
    inline void vm_if_icmple(){/* TO BE IMPLEMENTED */}
    inline void vm_if_acmpeq(){/* TO BE IMPLEMENTED */}
    inline void vm_if_acmpne(){/* TO BE IMPLEMENTED */}
    inline void vm_goto(){/* TO BE IMPLEMENTED */}
    inline void vm_jsr(){/* TO BE IMPLEMENTED */}
    inline void vm_ret(){/* TO BE IMPLEMENTED */}
    inline void vm_tableswitch(){/* TO BE IMPLEMENTED */}
    inline void vm_lookupswitch(){/* TO BE IMPLEMENTED */}
    inline void vm_ireturn(){/* TO BE IMPLEMENTED */}
    inline void vm_lreturn(){/* TO BE IMPLEMENTED */}
    inline void vm_freturn(){/* TO BE IMPLEMENTED */}
    inline void vm_dreturn(){/* TO BE IMPLEMENTED */}
    inline void vm_areturn(){/* TO BE IMPLEMENTED */}
    inline void vm_return(){/* TO BE IMPLEMENTED */}
    inline void vm_getstatic(){/* TO BE IMPLEMENTED */}
    inline void vm_putstatic(){/* TO BE IMPLEMENTED */}
    inline void vm_getfield(){/* TO BE IMPLEMENTED */}
    inline void vm_putfield(){/* TO BE IMPLEMENTED */}
    inline void vm_invokevirtual(){/* TO BE IMPLEMENTED */}
    inline void vm_invokespecial(){/* TO BE IMPLEMENTED */}
    inline void vm_invokestatic(){/* TO BE IMPLEMENTED */}
    inline void vm_invokeinterface(){/* TO BE IMPLEMENTED */}
    inline void vm_invokedynamic(){/* TO BE IMPLEMENTED */}
    inline void vm_new(){/* TO BE IMPLEMENTED */}
    inline void vm_newarray(){/* TO BE IMPLEMENTED */}
    inline void vm_anewarray(){/* TO BE IMPLEMENTED */}
    inline void vm_arraylength(){/* TO BE IMPLEMENTED */}
    inline void vm_athrow(){/* TO BE IMPLEMENTED */}
    inline void vm_checkcast(){/* TO BE IMPLEMENTED */}
    inline void vm_instanceof(){/* TO BE IMPLEMENTED */}
    inline void vm_monitorenter(){/* TO BE IMPLEMENTED */}
    inline void vm_monitorexit(){/* TO BE IMPLEMENTED */}
    inline void vm_wide(){/* TO BE IMPLEMENTED */}
    inline void vm_multianewarray(){/* TO BE IMPLEMENTED */}
    inline void vm_ifnull(){/* TO BE IMPLEMENTED */}
    inline void vm_ifnonnull(){/* TO BE IMPLEMENTED */}
    inline void vm_goto_w(){/* TO BE IMPLEMENTED */}
    inline void vm_jsr_w(){/* TO BE IMPLEMENTED */}
    inline void vm_breakpoint(){/* TO BE IMPLEMENTED */}
    inline void vm_impdep1(){/* TO BE IMPLEMENTED */}
    inline void vm_impdep2(){/* TO BE IMPLEMENTED */}


    void link_exec_map(){
        exec_map[0] = &CPU::vm_nop;
        exec_map[1] = &CPU::vm_aconst_null;
        exec_map[2] = &CPU::vm_iconst_m1;
        exec_map[3] = &CPU::vm_iconst_0;
        exec_map[4] = &CPU::vm_iconst_1;
        exec_map[5] = &CPU::vm_iconst_2;
        exec_map[6] = &CPU::vm_iconst_3;
        exec_map[7] = &CPU::vm_iconst_4;
        exec_map[8] = &CPU::vm_iconst_5;
        exec_map[9] = &CPU::vm_lconst_0;
        exec_map[10] = &CPU::vm_lconst_1;
        exec_map[11] = &CPU::vm_fconst_0;
        exec_map[12] = &CPU::vm_fconst_1;
        exec_map[13] = &CPU::vm_fconst_2;
        exec_map[14] = &CPU::vm_dconst_0;
        exec_map[15] = &CPU::vm_dconst_1;
        exec_map[16] = &CPU::vm_bipush;
        exec_map[17] = &CPU::vm_sipush;
        exec_map[18] = &CPU::vm_ldc;
        exec_map[19] = &CPU::vm_ldc_w;
        exec_map[20] = &CPU::vm_ldc2_w;
        exec_map[21] = &CPU::vm_iload;
        exec_map[22] = &CPU::vm_lload;
        exec_map[23] = &CPU::vm_fload;
        exec_map[24] = &CPU::vm_dload;
        exec_map[25] = &CPU::vm_aload;
        exec_map[26] = &CPU::vm_iload_0;
        exec_map[27] = &CPU::vm_iload_1;
        exec_map[28] = &CPU::vm_iload_2;
        exec_map[29] = &CPU::vm_iload_3;
        exec_map[30] = &CPU::vm_lload_0;
        exec_map[31] = &CPU::vm_lload_1;
        exec_map[32] = &CPU::vm_lload_2;
        exec_map[33] = &CPU::vm_lload_3;
        exec_map[34] = &CPU::vm_fload_0;
        exec_map[35] = &CPU::vm_fload_1;
        exec_map[36] = &CPU::vm_fload_2;
        exec_map[37] = &CPU::vm_fload_3;
        exec_map[38] = &CPU::vm_dload_0;
        exec_map[39] = &CPU::vm_dload_1;
        exec_map[40] = &CPU::vm_dload_2;
        exec_map[41] = &CPU::vm_dload_3;
        exec_map[42] = &CPU::vm_aload_0;
        exec_map[43] = &CPU::vm_aload_1;
        exec_map[44] = &CPU::vm_aload_2;
        exec_map[45] = &CPU::vm_aload_3;
        exec_map[46] = &CPU::vm_iaload;
        exec_map[47] = &CPU::vm_laload;
        exec_map[48] = &CPU::vm_faload;
        exec_map[49] = &CPU::vm_daload;
        exec_map[50] = &CPU::vm_aaload;
        exec_map[51] = &CPU::vm_baload;
        exec_map[52] = &CPU::vm_caload;
        exec_map[53] = &CPU::vm_saload;
        exec_map[54] = &CPU::vm_istore;
        exec_map[55] = &CPU::vm_lstore;
        exec_map[56] = &CPU::vm_fstore;
        exec_map[57] = &CPU::vm_dstore;
        exec_map[58] = &CPU::vm_astore;
        exec_map[59] = &CPU::vm_istore_0;
        exec_map[60] = &CPU::vm_istore_1;
        exec_map[61] = &CPU::vm_istore_2;
        exec_map[62] = &CPU::vm_istore_3;
        exec_map[63] = &CPU::vm_lstore_0;
        exec_map[64] = &CPU::vm_lstore_1;
        exec_map[65] = &CPU::vm_lstore_2;
        exec_map[66] = &CPU::vm_lstore_3;
        exec_map[67] = &CPU::vm_fstore_0;
        exec_map[68] = &CPU::vm_fstore_1;
        exec_map[69] = &CPU::vm_fstore_2;
        exec_map[70] = &CPU::vm_fstore_3;
        exec_map[71] = &CPU::vm_dstore_0;
        exec_map[72] = &CPU::vm_dstore_1;
        exec_map[73] = &CPU::vm_dstore_2;
        exec_map[74] = &CPU::vm_dstore_3;
        exec_map[75] = &CPU::vm_astore_0;
        exec_map[76] = &CPU::vm_astore_1;
        exec_map[77] = &CPU::vm_astore_2;
        exec_map[78] = &CPU::vm_astore_3;
        exec_map[79] = &CPU::vm_iastore;
        exec_map[80] = &CPU::vm_lastore;
        exec_map[81] = &CPU::vm_fastore;
        exec_map[82] = &CPU::vm_dastore;
        exec_map[83] = &CPU::vm_aastore;
        exec_map[84] = &CPU::vm_bastore;
        exec_map[85] = &CPU::vm_castore;
        exec_map[86] = &CPU::vm_sastore;
        exec_map[87] = &CPU::vm_pop;
        exec_map[88] = &CPU::vm_pop2;
        exec_map[89] = &CPU::vm_dup;
        exec_map[90] = &CPU::vm_dup_x1;
        exec_map[91] = &CPU::vm_dup_x2;
        exec_map[92] = &CPU::vm_dup2;
        exec_map[93] = &CPU::vm_dup2_x1;
        exec_map[94] = &CPU::vm_dup2_x2;
        exec_map[95] = &CPU::vm_swap;
        exec_map[96] = &CPU::vm_iadd;
        exec_map[97] = &CPU::vm_ladd;
        exec_map[98] = &CPU::vm_fadd;
        exec_map[99] = &CPU::vm_dadd;
        exec_map[100] = &CPU::vm_isub;
        exec_map[101] = &CPU::vm_lsub;
        exec_map[102] = &CPU::vm_fsub;
        exec_map[103] = &CPU::vm_dsub;
        exec_map[104] = &CPU::vm_imul;
        exec_map[105] = &CPU::vm_lmul;
        exec_map[106] = &CPU::vm_fmul;
        exec_map[107] = &CPU::vm_dmul;
        exec_map[108] = &CPU::vm_idiv;
        exec_map[109] = &CPU::vm_ldiv;
        exec_map[110] = &CPU::vm_fdiv;
        exec_map[111] = &CPU::vm_ddiv;
        exec_map[112] = &CPU::vm_irem;
        exec_map[113] = &CPU::vm_lrem;
        exec_map[114] = &CPU::vm_frem;
        exec_map[115] = &CPU::vm_drem;
        exec_map[116] = &CPU::vm_ineg;
        exec_map[117] = &CPU::vm_lneg;
        exec_map[118] = &CPU::vm_fneg;
        exec_map[119] = &CPU::vm_dneg;
        exec_map[120] = &CPU::vm_ishl;
        exec_map[121] = &CPU::vm_lshl;
        exec_map[122] = &CPU::vm_ishr;
        exec_map[123] = &CPU::vm_lshr;
        exec_map[124] = &CPU::vm_iushr;
        exec_map[125] = &CPU::vm_lushr;
        exec_map[126] = &CPU::vm_iand;
        exec_map[127] = &CPU::vm_land;
        exec_map[128] = &CPU::vm_ior;
        exec_map[129] = &CPU::vm_lor;
        exec_map[130] = &CPU::vm_ixor;
        exec_map[131] = &CPU::vm_lxor;
        exec_map[132] = &CPU::vm_iinc;
        exec_map[133] = &CPU::vm_i2l;
        exec_map[134] = &CPU::vm_i2f;
        exec_map[135] = &CPU::vm_i2d;
        exec_map[136] = &CPU::vm_l2i;
        exec_map[137] = &CPU::vm_l2f;
        exec_map[138] = &CPU::vm_l2d;
        exec_map[139] = &CPU::vm_f2i;
        exec_map[140] = &CPU::vm_f2l;
        exec_map[141] = &CPU::vm_f2d;
        exec_map[142] = &CPU::vm_d2i;
        exec_map[143] = &CPU::vm_d2l;
        exec_map[144] = &CPU::vm_d2f;
        exec_map[145] = &CPU::vm_i2b;
        exec_map[146] = &CPU::vm_i2c;
        exec_map[147] = &CPU::vm_i2s;
        exec_map[148] = &CPU::vm_lcmp;
        exec_map[149] = &CPU::vm_fcmpl;
        exec_map[150] = &CPU::vm_fcmpg;
        exec_map[151] = &CPU::vm_dcmpl;
        exec_map[152] = &CPU::vm_dcmpg;
        exec_map[153] = &CPU::vm_ifeq;
        exec_map[154] = &CPU::vm_ifne;
        exec_map[155] = &CPU::vm_iflt;
        exec_map[156] = &CPU::vm_ifge;
        exec_map[157] = &CPU::vm_ifgt;
        exec_map[158] = &CPU::vm_ifle;
        exec_map[159] = &CPU::vm_if_icmpeq;
        exec_map[160] = &CPU::vm_if_icmpne;
        exec_map[161] = &CPU::vm_if_icmplt;
        exec_map[162] = &CPU::vm_if_icmpge;
        exec_map[163] = &CPU::vm_if_icmpgt;
        exec_map[164] = &CPU::vm_if_icmple;
        exec_map[165] = &CPU::vm_if_acmpeq;
        exec_map[166] = &CPU::vm_if_acmpne;
        exec_map[167] = &CPU::vm_goto;
        exec_map[168] = &CPU::vm_jsr;
        exec_map[169] = &CPU::vm_ret;
        exec_map[170] = &CPU::vm_tableswitch;
        exec_map[171] = &CPU::vm_lookupswitch;
        exec_map[172] = &CPU::vm_ireturn;
        exec_map[173] = &CPU::vm_lreturn;
        exec_map[174] = &CPU::vm_freturn;
        exec_map[175] = &CPU::vm_dreturn;
        exec_map[176] = &CPU::vm_areturn;
        exec_map[177] = &CPU::vm_return;
        exec_map[178] = &CPU::vm_getstatic;
        exec_map[179] = &CPU::vm_putstatic;
        exec_map[180] = &CPU::vm_getfield;
        exec_map[181] = &CPU::vm_putfield;
        exec_map[182] = &CPU::vm_invokevirtual;
        exec_map[183] = &CPU::vm_invokespecial;
        exec_map[184] = &CPU::vm_invokestatic;
        exec_map[185] = &CPU::vm_invokeinterface;
        exec_map[186] = &CPU::vm_invokedynamic;
        exec_map[187] = &CPU::vm_new;
        exec_map[188] = &CPU::vm_newarray;
        exec_map[189] = &CPU::vm_anewarray;
        exec_map[190] = &CPU::vm_arraylength;
        exec_map[191] = &CPU::vm_athrow;
        exec_map[192] = &CPU::vm_checkcast;
        exec_map[193] = &CPU::vm_instanceof;
        exec_map[194] = &CPU::vm_monitorenter;
        exec_map[195] = &CPU::vm_monitorexit;
        exec_map[196] = &CPU::vm_wide;
        exec_map[197] = &CPU::vm_multianewarray;
        exec_map[198] = &CPU::vm_ifnull;
        exec_map[199] = &CPU::vm_ifnonnull;
        exec_map[200] = &CPU::vm_goto_w;
        exec_map[201] = &CPU::vm_jsr_w;
        exec_map[202] = &CPU::vm_breakpoint;
        exec_map[254] = &CPU::vm_impdep1;
        exec_map[255] = &CPU::vm_impdep2;
    }
};
#endif 
