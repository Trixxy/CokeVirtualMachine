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

	// for(int i = 0; i < program.size(); i++){
	// 	std::cout << "[" << std::setfill ('0') << std::setw(4) << std::dec << i << "]: " 
	// 	<< std::setfill('0') << std::setw(2) << std::hex << instruction_tt[program[i]] << std::endl;
	// }

	return 0;
}


// void (*exec_map[256])(void);
// void link_exec_map();


//inline void vm_nop(){/* TO BE IMPLEMENTED */}
//inline void vm_aconst_null(){/* TO BE IMPLEMENTED */}
//inline void vm_iconst_m1(){/* TO BE IMPLEMENTED */}
//inline void vm_iconst_0(){/* TO BE IMPLEMENTED */}
//inline void vm_iconst_1(){/* TO BE IMPLEMENTED */}
//inline void vm_iconst_2(){/* TO BE IMPLEMENTED */}
//inline void vm_iconst_3(){/* TO BE IMPLEMENTED */}
//inline void vm_iconst_4(){/* TO BE IMPLEMENTED */}
//inline void vm_iconst_5(){/* TO BE IMPLEMENTED */}
//inline void vm_lconst_0(){/* TO BE IMPLEMENTED */}
//inline void vm_lconst_1(){/* TO BE IMPLEMENTED */}
//inline void vm_fconst_0(){/* TO BE IMPLEMENTED */}
//inline void vm_fconst_1(){/* TO BE IMPLEMENTED */}
//inline void vm_fconst_2(){/* TO BE IMPLEMENTED */}
//inline void vm_dconst_0(){/* TO BE IMPLEMENTED */}
//inline void vm_dconst_1(){/* TO BE IMPLEMENTED */}
//inline void vm_bipush(){/* TO BE IMPLEMENTED */}
//inline void vm_sipush(){/* TO BE IMPLEMENTED */}
//inline void vm_ldc(){/* TO BE IMPLEMENTED */}
//inline void vm_ldc_w(){/* TO BE IMPLEMENTED */}
//inline void vm_ldc2_w(){/* TO BE IMPLEMENTED */}
//inline void vm_iload(){/* TO BE IMPLEMENTED */}
//inline void vm_lload(){/* TO BE IMPLEMENTED */}
//inline void vm_fload(){/* TO BE IMPLEMENTED */}
//inline void vm_dload(){/* TO BE IMPLEMENTED */}
//inline void vm_aload(){/* TO BE IMPLEMENTED */}
//inline void vm_iload_0(){/* TO BE IMPLEMENTED */}
//inline void vm_iload_1(){/* TO BE IMPLEMENTED */}
//inline void vm_iload_2(){/* TO BE IMPLEMENTED */}
//inline void vm_iload_3(){/* TO BE IMPLEMENTED */}
//inline void vm_lload_0(){/* TO BE IMPLEMENTED */}
//inline void vm_lload_1(){/* TO BE IMPLEMENTED */}
//inline void vm_lload_2(){/* TO BE IMPLEMENTED */}
//inline void vm_lload_3(){/* TO BE IMPLEMENTED */}
//inline void vm_fload_0(){/* TO BE IMPLEMENTED */}
//inline void vm_fload_1(){/* TO BE IMPLEMENTED */}
//inline void vm_fload_2(){/* TO BE IMPLEMENTED */}
//inline void vm_fload_3(){/* TO BE IMPLEMENTED */}
//inline void vm_dload_0(){/* TO BE IMPLEMENTED */}
//inline void vm_dload_1(){/* TO BE IMPLEMENTED */}
//inline void vm_dload_2(){/* TO BE IMPLEMENTED */}
//inline void vm_dload_3(){/* TO BE IMPLEMENTED */}
//inline void vm_aload_0(){/* TO BE IMPLEMENTED */}
//inline void vm_aload_1(){/* TO BE IMPLEMENTED */}
//inline void vm_aload_2(){/* TO BE IMPLEMENTED */}
//inline void vm_aload_3(){/* TO BE IMPLEMENTED */}
//inline void vm_iaload(){/* TO BE IMPLEMENTED */}
//inline void vm_laload(){/* TO BE IMPLEMENTED */}
//inline void vm_faload(){/* TO BE IMPLEMENTED */}
//inline void vm_daload(){/* TO BE IMPLEMENTED */}
//inline void vm_aaload(){/* TO BE IMPLEMENTED */}
//inline void vm_baload(){/* TO BE IMPLEMENTED */}
//inline void vm_caload(){/* TO BE IMPLEMENTED */}
//inline void vm_saload(){/* TO BE IMPLEMENTED */}
//inline void vm_istore(){/* TO BE IMPLEMENTED */}
//inline void vm_lstore(){/* TO BE IMPLEMENTED */}
//inline void vm_fstore(){/* TO BE IMPLEMENTED */}
//inline void vm_dstore(){/* TO BE IMPLEMENTED */}
//inline void vm_astore(){/* TO BE IMPLEMENTED */}
//inline void vm_istore_0(){/* TO BE IMPLEMENTED */}
//inline void vm_istore_1(){/* TO BE IMPLEMENTED */}
//inline void vm_istore_2(){/* TO BE IMPLEMENTED */}
//inline void vm_istore_3(){/* TO BE IMPLEMENTED */}
//inline void vm_lstore_0(){/* TO BE IMPLEMENTED */}
//inline void vm_lstore_1(){/* TO BE IMPLEMENTED */}
//inline void vm_lstore_2(){/* TO BE IMPLEMENTED */}
//inline void vm_lstore_3(){/* TO BE IMPLEMENTED */}
//inline void vm_fstore_0(){/* TO BE IMPLEMENTED */}
//inline void vm_fstore_1(){/* TO BE IMPLEMENTED */}
//inline void vm_fstore_2(){/* TO BE IMPLEMENTED */}
//inline void vm_fstore_3(){/* TO BE IMPLEMENTED */}
//inline void vm_dstore_0(){/* TO BE IMPLEMENTED */}
//inline void vm_dstore_1(){/* TO BE IMPLEMENTED */}
//inline void vm_dstore_2(){/* TO BE IMPLEMENTED */}
//inline void vm_dstore_3(){/* TO BE IMPLEMENTED */}
//inline void vm_astore_0(){/* TO BE IMPLEMENTED */}
//inline void vm_astore_1(){/* TO BE IMPLEMENTED */}
//inline void vm_astore_2(){/* TO BE IMPLEMENTED */}
//inline void vm_astore_3(){/* TO BE IMPLEMENTED */}
//inline void vm_iastore(){/* TO BE IMPLEMENTED */}
//inline void vm_lastore(){/* TO BE IMPLEMENTED */}
//inline void vm_fastore(){/* TO BE IMPLEMENTED */}
//inline void vm_dastore(){/* TO BE IMPLEMENTED */}
//inline void vm_aastore(){/* TO BE IMPLEMENTED */}
//inline void vm_bastore(){/* TO BE IMPLEMENTED */}
//inline void vm_castore(){/* TO BE IMPLEMENTED */}
//inline void vm_sastore(){/* TO BE IMPLEMENTED */}
//inline void vm_pop(){/* TO BE IMPLEMENTED */}
//inline void vm_pop2(){/* TO BE IMPLEMENTED */}
//inline void vm_dup(){/* TO BE IMPLEMENTED */}
//inline void vm_dup_x1(){/* TO BE IMPLEMENTED */}
//inline void vm_dup_x2(){/* TO BE IMPLEMENTED */}
//inline void vm_dup2(){/* TO BE IMPLEMENTED */}
//inline void vm_dup2_x1(){/* TO BE IMPLEMENTED */}
//inline void vm_dup2_x2(){/* TO BE IMPLEMENTED */}
//inline void vm_swap(){/* TO BE IMPLEMENTED */}
//inline void vm_iadd(){/* TO BE IMPLEMENTED */}
//inline void vm_ladd(){/* TO BE IMPLEMENTED */}
//inline void vm_fadd(){/* TO BE IMPLEMENTED */}
//inline void vm_dadd(){/* TO BE IMPLEMENTED */}
//inline void vm_isub(){/* TO BE IMPLEMENTED */}
//inline void vm_lsub(){/* TO BE IMPLEMENTED */}
//inline void vm_fsub(){/* TO BE IMPLEMENTED */}
//inline void vm_dsub(){/* TO BE IMPLEMENTED */}
//inline void vm_imul(){/* TO BE IMPLEMENTED */}
//inline void vm_lmul(){/* TO BE IMPLEMENTED */}
//inline void vm_fmul(){/* TO BE IMPLEMENTED */}
//inline void vm_dmul(){/* TO BE IMPLEMENTED */}
//inline void vm_idiv(){/* TO BE IMPLEMENTED */}
//inline void vm_ldiv(){/* TO BE IMPLEMENTED */}
//inline void vm_fdiv(){/* TO BE IMPLEMENTED */}
//inline void vm_ddiv(){/* TO BE IMPLEMENTED */}
//inline void vm_irem(){/* TO BE IMPLEMENTED */}
//inline void vm_lrem(){/* TO BE IMPLEMENTED */}
//inline void vm_frem(){/* TO BE IMPLEMENTED */}
//inline void vm_drem(){/* TO BE IMPLEMENTED */}
//inline void vm_ineg(){/* TO BE IMPLEMENTED */}
//inline void vm_lneg(){/* TO BE IMPLEMENTED */}
//inline void vm_fneg(){/* TO BE IMPLEMENTED */}
//inline void vm_dneg(){/* TO BE IMPLEMENTED */}
//inline void vm_ishl(){/* TO BE IMPLEMENTED */}
//inline void vm_lshl(){/* TO BE IMPLEMENTED */}
//inline void vm_ishr(){/* TO BE IMPLEMENTED */}
//inline void vm_lshr(){/* TO BE IMPLEMENTED */}
//inline void vm_iushr(){/* TO BE IMPLEMENTED */}
//inline void vm_lushr(){/* TO BE IMPLEMENTED */}
//inline void vm_iand(){/* TO BE IMPLEMENTED */}
//inline void vm_land(){/* TO BE IMPLEMENTED */}
//inline void vm_ior(){/* TO BE IMPLEMENTED */}
//inline void vm_lor(){/* TO BE IMPLEMENTED */}
//inline void vm_ixor(){/* TO BE IMPLEMENTED */}
//inline void vm_lxor(){/* TO BE IMPLEMENTED */}
//inline void vm_iinc(){/* TO BE IMPLEMENTED */}
//inline void vm_i2l(){/* TO BE IMPLEMENTED */}
//inline void vm_i2f(){/* TO BE IMPLEMENTED */}
//inline void vm_i2d(){/* TO BE IMPLEMENTED */}
//inline void vm_l2i(){/* TO BE IMPLEMENTED */}
//inline void vm_l2f(){/* TO BE IMPLEMENTED */}
//inline void vm_l2d(){/* TO BE IMPLEMENTED */}
//inline void vm_f2i(){/* TO BE IMPLEMENTED */}
//inline void vm_f2l(){/* TO BE IMPLEMENTED */}
//inline void vm_f2d(){/* TO BE IMPLEMENTED */}
//inline void vm_d2i(){/* TO BE IMPLEMENTED */}
//inline void vm_d2l(){/* TO BE IMPLEMENTED */}
//inline void vm_d2f(){/* TO BE IMPLEMENTED */}
//inline void vm_i2b(){/* TO BE IMPLEMENTED */}
//inline void vm_i2c(){/* TO BE IMPLEMENTED */}
//inline void vm_i2s(){/* TO BE IMPLEMENTED */}
//inline void vm_lcmp(){/* TO BE IMPLEMENTED */}
//inline void vm_fcmpl(){/* TO BE IMPLEMENTED */}
//inline void vm_fcmpg(){/* TO BE IMPLEMENTED */}
//inline void vm_dcmpl(){/* TO BE IMPLEMENTED */}
//inline void vm_dcmpg(){/* TO BE IMPLEMENTED */}
//inline void vm_ifeq(){/* TO BE IMPLEMENTED */}
//inline void vm_ifne(){/* TO BE IMPLEMENTED */}
//inline void vm_iflt(){/* TO BE IMPLEMENTED */}
//inline void vm_ifge(){/* TO BE IMPLEMENTED */}
//inline void vm_ifgt(){/* TO BE IMPLEMENTED */}
//inline void vm_ifle(){/* TO BE IMPLEMENTED */}
//inline void vm_if_icmpeq(){/* TO BE IMPLEMENTED */}
//inline void vm_if_icmpne(){/* TO BE IMPLEMENTED */}
//inline void vm_if_icmplt(){/* TO BE IMPLEMENTED */}
//inline void vm_if_icmpge(){/* TO BE IMPLEMENTED */}
//inline void vm_if_icmpgt(){/* TO BE IMPLEMENTED */}
//inline void vm_if_icmple(){/* TO BE IMPLEMENTED */}
//inline void vm_if_acmpeq(){/* TO BE IMPLEMENTED */}
//inline void vm_if_acmpne(){/* TO BE IMPLEMENTED */}
//inline void vm_goto(){/* TO BE IMPLEMENTED */}
//inline void vm_jsr(){/* TO BE IMPLEMENTED */}
//inline void vm_ret(){/* TO BE IMPLEMENTED */}
//inline void vm_tableswitch(){/* TO BE IMPLEMENTED */}
//inline void vm_lookupswitch(){/* TO BE IMPLEMENTED */}
//inline void vm_ireturn(){/* TO BE IMPLEMENTED */}
//inline void vm_lreturn(){/* TO BE IMPLEMENTED */}
//inline void vm_freturn(){/* TO BE IMPLEMENTED */}
//inline void vm_dreturn(){/* TO BE IMPLEMENTED */}
//inline void vm_areturn(){/* TO BE IMPLEMENTED */}
//inline void vm_return(){/* TO BE IMPLEMENTED */}
//inline void vm_getstatic(){/* TO BE IMPLEMENTED */}
//inline void vm_putstatic(){/* TO BE IMPLEMENTED */}
//inline void vm_getfield(){/* TO BE IMPLEMENTED */}
//inline void vm_putfield(){/* TO BE IMPLEMENTED */}
//inline void vm_invokevirtual(){/* TO BE IMPLEMENTED */}
//inline void vm_invokespecial(){/* TO BE IMPLEMENTED */}
//inline void vm_invokestatic(){/* TO BE IMPLEMENTED */}
//inline void vm_invokeinterface(){/* TO BE IMPLEMENTED */}
//inline void vm_invokedynamic(){/* TO BE IMPLEMENTED */}
//inline void vm_new(){/* TO BE IMPLEMENTED */}
//inline void vm_newarray(){/* TO BE IMPLEMENTED */}
//inline void vm_anewarray(){/* TO BE IMPLEMENTED */}
//inline void vm_arraylength(){/* TO BE IMPLEMENTED */}
//inline void vm_athrow(){/* TO BE IMPLEMENTED */}
//inline void vm_checkcast(){/* TO BE IMPLEMENTED */}
//inline void vm_instanceof(){/* TO BE IMPLEMENTED */}
//inline void vm_monitorenter(){/* TO BE IMPLEMENTED */}
//inline void vm_monitorexit(){/* TO BE IMPLEMENTED */}
//inline void vm_wide(){/* TO BE IMPLEMENTED */}
//inline void vm_multianewarray(){/* TO BE IMPLEMENTED */}
//inline void vm_ifnull(){/* TO BE IMPLEMENTED */}
//inline void vm_ifnonnull(){/* TO BE IMPLEMENTED */}
//inline void vm_goto_w(){/* TO BE IMPLEMENTED */}
//inline void vm_jsr_w(){/* TO BE IMPLEMENTED */}
//inline void vm_breakpoint(){/* TO BE IMPLEMENTED */}
//inline void vm_impdep1(){/* TO BE IMPLEMENTED */}
//inline void vm_impdep2(){/* TO BE IMPLEMENTED */}


void link_exec_map(){
	//exec_map[0] = &vm_nop;
	//exec_map[1] = &vm_aconst_null;
	//exec_map[2] = &vm_iconst_m1;
	//exec_map[3] = &vm_iconst_0;
	//exec_map[4] = &vm_iconst_1;
	//exec_map[5] = &vm_iconst_2;
	//exec_map[6] = &vm_iconst_3;
	//exec_map[7] = &vm_iconst_4;
	//exec_map[8] = &vm_iconst_5;
	//exec_map[9] = &vm_lconst_0;
	//exec_map[10] = &vm_lconst_1;
	//exec_map[11] = &vm_fconst_0;
	//exec_map[12] = &vm_fconst_1;
	//exec_map[13] = &vm_fconst_2;
	//exec_map[14] = &vm_dconst_0;
	//exec_map[15] = &vm_dconst_1;
	//exec_map[16] = &vm_bipush;
	//exec_map[17] = &vm_sipush;
	//exec_map[18] = &vm_ldc;
	//exec_map[19] = &vm_ldc_w;
	//exec_map[20] = &vm_ldc2_w;
	//exec_map[21] = &vm_iload;
	//exec_map[22] = &vm_lload;
	//exec_map[23] = &vm_fload;
	//exec_map[24] = &vm_dload;
	//exec_map[25] = &vm_aload;
	//exec_map[26] = &vm_iload_0;
	//exec_map[27] = &vm_iload_1;
	//exec_map[28] = &vm_iload_2;
	//exec_map[29] = &vm_iload_3;
	//exec_map[30] = &vm_lload_0;
	//exec_map[31] = &vm_lload_1;
	//exec_map[32] = &vm_lload_2;
	//exec_map[33] = &vm_lload_3;
	//exec_map[34] = &vm_fload_0;
	//exec_map[35] = &vm_fload_1;
	//exec_map[36] = &vm_fload_2;
	//exec_map[37] = &vm_fload_3;
	//exec_map[38] = &vm_dload_0;
	//exec_map[39] = &vm_dload_1;
	//exec_map[40] = &vm_dload_2;
	//exec_map[41] = &vm_dload_3;
	//exec_map[42] = &vm_aload_0;
	//exec_map[43] = &vm_aload_1;
	//exec_map[44] = &vm_aload_2;
	//exec_map[45] = &vm_aload_3;
	//exec_map[46] = &vm_iaload;
	//exec_map[47] = &vm_laload;
	//exec_map[48] = &vm_faload;
	//exec_map[49] = &vm_daload;
	//exec_map[50] = &vm_aaload;
	//exec_map[51] = &vm_baload;
	//exec_map[52] = &vm_caload;
	//exec_map[53] = &vm_saload;
	//exec_map[54] = &vm_istore;
	//exec_map[55] = &vm_lstore;
	//exec_map[56] = &vm_fstore;
	//exec_map[57] = &vm_dstore;
	//exec_map[58] = &vm_astore;
	//exec_map[59] = &vm_istore_0;
	//exec_map[60] = &vm_istore_1;
	//exec_map[61] = &vm_istore_2;
	//exec_map[62] = &vm_istore_3;
	//exec_map[63] = &vm_lstore_0;
	//exec_map[64] = &vm_lstore_1;
	//exec_map[65] = &vm_lstore_2;
	//exec_map[66] = &vm_lstore_3;
	//exec_map[67] = &vm_fstore_0;
	//exec_map[68] = &vm_fstore_1;
	//exec_map[69] = &vm_fstore_2;
	//exec_map[70] = &vm_fstore_3;
	//exec_map[71] = &vm_dstore_0;
	//exec_map[72] = &vm_dstore_1;
	//exec_map[73] = &vm_dstore_2;
	//exec_map[74] = &vm_dstore_3;
	//exec_map[75] = &vm_astore_0;
	//exec_map[76] = &vm_astore_1;
	//exec_map[77] = &vm_astore_2;
	//exec_map[78] = &vm_astore_3;
	//exec_map[79] = &vm_iastore;
	//exec_map[80] = &vm_lastore;
	//exec_map[81] = &vm_fastore;
	//exec_map[82] = &vm_dastore;
	//exec_map[83] = &vm_aastore;
	//exec_map[84] = &vm_bastore;
	//exec_map[85] = &vm_castore;
	//exec_map[86] = &vm_sastore;
	//exec_map[87] = &vm_pop;
	//exec_map[88] = &vm_pop2;
	//exec_map[89] = &vm_dup;
	//exec_map[90] = &vm_dup_x1;
	//exec_map[91] = &vm_dup_x2;
	//exec_map[92] = &vm_dup2;
	//exec_map[93] = &vm_dup2_x1;
	//exec_map[94] = &vm_dup2_x2;
	//exec_map[95] = &vm_swap;
	//exec_map[96] = &vm_iadd;
	//exec_map[97] = &vm_ladd;
	//exec_map[98] = &vm_fadd;
	//exec_map[99] = &vm_dadd;
	//exec_map[100] = &vm_isub;
	//exec_map[101] = &vm_lsub;
	//exec_map[102] = &vm_fsub;
	//exec_map[103] = &vm_dsub;
	//exec_map[104] = &vm_imul;
	//exec_map[105] = &vm_lmul;
	//exec_map[106] = &vm_fmul;
	//exec_map[107] = &vm_dmul;
	//exec_map[108] = &vm_idiv;
	//exec_map[109] = &vm_ldiv;
	//exec_map[110] = &vm_fdiv;
	//exec_map[111] = &vm_ddiv;
	//exec_map[112] = &vm_irem;
	//exec_map[113] = &vm_lrem;
	//exec_map[114] = &vm_frem;
	//exec_map[115] = &vm_drem;
	//exec_map[116] = &vm_ineg;
	//exec_map[117] = &vm_lneg;
	//exec_map[118] = &vm_fneg;
	//exec_map[119] = &vm_dneg;
	//exec_map[120] = &vm_ishl;
	//exec_map[121] = &vm_lshl;
	//exec_map[122] = &vm_ishr;
	//exec_map[123] = &vm_lshr;
	//exec_map[124] = &vm_iushr;
	//exec_map[125] = &vm_lushr;
	//exec_map[126] = &vm_iand;
	//exec_map[127] = &vm_land;
	//exec_map[128] = &vm_ior;
	//exec_map[129] = &vm_lor;
	//exec_map[130] = &vm_ixor;
	//exec_map[131] = &vm_lxor;
	//exec_map[132] = &vm_iinc;
	//exec_map[133] = &vm_i2l;
	//exec_map[134] = &vm_i2f;
	//exec_map[135] = &vm_i2d;
	//exec_map[136] = &vm_l2i;
	//exec_map[137] = &vm_l2f;
	//exec_map[138] = &vm_l2d;
	//exec_map[139] = &vm_f2i;
	//exec_map[140] = &vm_f2l;
	//exec_map[141] = &vm_f2d;
	//exec_map[142] = &vm_d2i;
	//exec_map[143] = &vm_d2l;
	//exec_map[144] = &vm_d2f;
	//exec_map[145] = &vm_i2b;
	//exec_map[146] = &vm_i2c;
	//exec_map[147] = &vm_i2s;
	//exec_map[148] = &vm_lcmp;
	//exec_map[149] = &vm_fcmpl;
	//exec_map[150] = &vm_fcmpg;
	//exec_map[151] = &vm_dcmpl;
	//exec_map[152] = &vm_dcmpg;
	//exec_map[153] = &vm_ifeq;
	//exec_map[154] = &vm_ifne;
	//exec_map[155] = &vm_iflt;
	//exec_map[156] = &vm_ifge;
	//exec_map[157] = &vm_ifgt;
	//exec_map[158] = &vm_ifle;
	//exec_map[159] = &vm_if_icmpeq;
	//exec_map[160] = &vm_if_icmpne;
	//exec_map[161] = &vm_if_icmplt;
	//exec_map[162] = &vm_if_icmpge;
	//exec_map[163] = &vm_if_icmpgt;
	//exec_map[164] = &vm_if_icmple;
	//exec_map[165] = &vm_if_acmpeq;
	//exec_map[166] = &vm_if_acmpne;
	//exec_map[167] = &vm_goto;
	//exec_map[168] = &vm_jsr;
	//exec_map[169] = &vm_ret;
	//exec_map[170] = &vm_tableswitch;
	//exec_map[171] = &vm_lookupswitch;
	//exec_map[172] = &vm_ireturn;
	//exec_map[173] = &vm_lreturn;
	//exec_map[174] = &vm_freturn;
	//exec_map[175] = &vm_dreturn;
	//exec_map[176] = &vm_areturn;
	//exec_map[177] = &vm_return;
	//exec_map[178] = &vm_getstatic;
	//exec_map[179] = &vm_putstatic;
	//exec_map[180] = &vm_getfield;
	//exec_map[181] = &vm_putfield;
	//exec_map[182] = &vm_invokevirtual;
	//exec_map[183] = &vm_invokespecial;
	//exec_map[184] = &vm_invokestatic;
	//exec_map[185] = &vm_invokeinterface;
	//exec_map[186] = &vm_invokedynamic;
	//exec_map[187] = &vm_new;
	//exec_map[188] = &vm_newarray;
	//exec_map[189] = &vm_anewarray;
	//exec_map[190] = &vm_arraylength;
	//exec_map[191] = &vm_athrow;
	//exec_map[192] = &vm_checkcast;
	//exec_map[193] = &vm_instanceof;
	//exec_map[194] = &vm_monitorenter;
	//exec_map[195] = &vm_monitorexit;
	//exec_map[196] = &vm_wide;
	//exec_map[197] = &vm_multianewarray;
	//exec_map[198] = &vm_ifnull;
	//exec_map[199] = &vm_ifnonnull;
	//exec_map[200] = &vm_goto_w;
	//exec_map[201] = &vm_jsr_w;
	//exec_map[202] = &vm_breakpoint;
	//exec_map[254] = &vm_impdep1;
	//exec_map[255] = &vm_impdep2;
}