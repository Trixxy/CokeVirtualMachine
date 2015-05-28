#ifndef _VM_DEF_CONST_TRANS_H_
#define _VM_DEF_CONST_TRANS_H_

#define byte unsigned char

enum Instruction{
	vm_nop              = 0x0000,
	vm_aconst_null      = 0x0001,
	vm_iconst_m1        = 0x0002,
	vm_iconst_0         = 0x0003,
	vm_iconst_1         = 0x0004,
	vm_iconst_2         = 0x0005,
	vm_iconst_3         = 0x0006,
	vm_iconst_4         = 0x0007,
	vm_iconst_5         = 0x0008,
	vm_lconst_0         = 0x0009,
	vm_lconst_1         = 0x000a,
	vm_fconst_0         = 0x000b,
	vm_fconst_1         = 0x000c,
	vm_fconst_2         = 0x000d,
	vm_dconst_0         = 0x000e,
	vm_dconst_1         = 0x000f,
	vm_bipush           = 0x0010,
	vm_sipush           = 0x0011,
	vm_ldc              = 0x0012,
	vm_ldc_w            = 0x0013,
	vm_ldc2_w           = 0x0014,
	vm_iload            = 0x0015,
	vm_lload            = 0x0016,
	vm_fload            = 0x0017,
	vm_dload            = 0x0018,
	vm_aload            = 0x0019,
	vm_iload_0          = 0x001a,
	vm_iload_1          = 0x001b,
	vm_iload_2          = 0x001c,
	vm_iload_3          = 0x001d,
	vm_lload_0          = 0x001e,
	vm_lload_1          = 0x001f,
	vm_lload_2          = 0x0020,
	vm_lload_3          = 0x0021,
	vm_fload_0          = 0x0022,
	vm_fload_1          = 0x0023,
	vm_fload_2          = 0x0024,
	vm_fload_3          = 0x0025,
	vm_dload_0          = 0x0026,
	vm_dload_1          = 0x0027,
	vm_dload_2          = 0x0028,
	vm_dload_3          = 0x0029,
	vm_aload_0          = 0x002a,
	vm_aload_1          = 0x002b,
	vm_aload_2          = 0x002c,
	vm_aload_3          = 0x002d,
	vm_iaload           = 0x002e,
	vm_laload           = 0x002f,
	vm_faload           = 0x0030,
	vm_daload           = 0x0031,
	vm_aaload           = 0x0032,
	vm_baload           = 0x0033,
	vm_caload           = 0x0034,
	vm_saload           = 0x0035,
	vm_istore           = 0x0036,
	vm_lstore           = 0x0037,
	vm_fstore           = 0x0038,
	vm_dstore           = 0x0039,
	vm_astore           = 0x003a,
	vm_istore_0         = 0x003b,
	vm_istore_1         = 0x003c,
	vm_istore_2         = 0x003d,
	vm_istore_3         = 0x003e,
	vm_lstore_0         = 0x003f,
	vm_lstore_1         = 0x0040,
	vm_lstore_2         = 0x0041,
	vm_lstore_3         = 0x0042,
	vm_fstore_0         = 0x0043,
	vm_fstore_1         = 0x0044,
	vm_fstore_2         = 0x0045,
	vm_fstore_3         = 0x0046,
	vm_dstore_0         = 0x0047,
	vm_dstore_1         = 0x0048,
	vm_dstore_2         = 0x0049,
	vm_dstore_3         = 0x004a,
	vm_astore_0         = 0x004b,
	vm_astore_1         = 0x004c,
	vm_astore_2         = 0x004d,
	vm_astore_3         = 0x004e,
	vm_iastore          = 0x004f,
	vm_lastore          = 0x0050,
	vm_fastore          = 0x0051,
	vm_dastore          = 0x0052,
	vm_aastore          = 0x0053,
	vm_bastore          = 0x0054,
	vm_castore          = 0x0055,
	vm_sastore          = 0x0056,
	vm_pop              = 0x0057,
	vm_pop2             = 0x0058,
	vm_dup              = 0x0059,
	vm_dup_x1           = 0x005a,
	vm_dup_x2           = 0x005b,
	vm_dup2             = 0x005c,
	vm_dup2_x1          = 0x005d,
	vm_dup2_x2          = 0x005e,
	vm_swap             = 0x005f,
	vm_iadd             = 0x0060,
	vm_ladd             = 0x0061,
	vm_fadd             = 0x0062,
	vm_dadd             = 0x0063,
	vm_isub             = 0x0064,
	vm_lsub             = 0x0065,
	vm_fsub             = 0x0066,
	vm_dsub             = 0x0067,
	vm_imul             = 0x0068,
	vm_lmul             = 0x0069,
	vm_fmul             = 0x006a,
	vm_dmul             = 0x006b,
	vm_idiv             = 0x006c,
	vm_ldiv             = 0x006d,
	vm_fdiv             = 0x006e,
	vm_ddiv             = 0x006f,
	vm_irem             = 0x0070,
	vm_lrem             = 0x0071,
	vm_frem             = 0x0072,
	vm_drem             = 0x0073,
	vm_ineg             = 0x0074,
	vm_lneg             = 0x0075,
	vm_fneg             = 0x0076,
	vm_dneg             = 0x0077,
	vm_ishl             = 0x0078,
	vm_lshl             = 0x0079,
	vm_ishr             = 0x007a,
	vm_lshr             = 0x007b,
	vm_iushr            = 0x007c,
	vm_lushr            = 0x007d,
	vm_iand             = 0x007e,
	vm_land             = 0x007f,
	vm_ior              = 0x0080,
	vm_lor              = 0x0081,
	vm_ixor             = 0x0082,
	vm_lxor             = 0x0083,
	vm_iinc             = 0x0084,
	vm_i2l              = 0x0085,
	vm_i2f              = 0x0086,
	vm_i2d              = 0x0087,
	vm_l2i              = 0x0088,
	vm_l2f              = 0x0089,
	vm_l2d              = 0x008a,
	vm_f2i              = 0x008b,
	vm_f2l              = 0x008c,
	vm_f2d              = 0x008d,
	vm_d2i              = 0x008e,
	vm_d2l              = 0x008f,
	vm_d2f              = 0x0090,
	vm_i2b              = 0x0091,
	vm_i2c              = 0x0092,
	vm_i2s              = 0x0093,
	vm_lcmp             = 0x0094,
	vm_fcmpl            = 0x0095,
	vm_fcmpg            = 0x0096,
	vm_dcmpl            = 0x0097,
	vm_dcmpg            = 0x0098,
	vm_ifeq             = 0x0099,
	vm_ifne             = 0x009a,
	vm_iflt             = 0x009b,
	vm_ifge             = 0x009c,
	vm_ifgt             = 0x009d,
	vm_ifle             = 0x009e,
	vm_if_icmpeq        = 0x009f,
	vm_if_icmpne        = 0x00a0,
	vm_if_icmplt        = 0x00a1,
	vm_if_icmpge        = 0x00a2,
	vm_if_icmpgt        = 0x00a3,
	vm_if_icmple        = 0x00a4,
	vm_if_acmpeq        = 0x00a5,
	vm_if_acmpne        = 0x00a6,
	vm_goto             = 0x00a7,
	vm_jsr              = 0x00a8,
	vm_ret              = 0x00a9,
	vm_tableswitch      = 0x00aa,
	vm_lookupswitch     = 0x00ab,
	vm_ireturn          = 0x00ac,
	vm_lreturn          = 0x00ad,
	vm_freturn          = 0x00ae,
	vm_dreturn          = 0x00af,
	vm_areturn          = 0x00b0,
	vm_return           = 0x00b1,
	vm_getstatic        = 0x00b2,
	vm_putstatic        = 0x00b3,
	vm_getfield         = 0x00b4,
	vm_putfield         = 0x00b5,
	vm_invokevirtual    = 0x00b6,
	vm_invokespecial    = 0x00b7,
	vm_invokestatic     = 0x00b8,
	vm_invokeinterface  = 0x00b9,
	vm_invokedynamic    = 0x00ba,
	vm_new              = 0x00bb,
	vm_newarray         = 0x00bc,
	vm_anewarray        = 0x00bd,
	vm_arraylength      = 0x00be,
	vm_athrow           = 0x00bf,
	vm_checkcast        = 0x00c0,
	vm_instanceof       = 0x00c1,
	vm_monitorenter     = 0x00c2,
	vm_monitorexit      = 0x00c3,
	vm_wide             = 0x00c4,
	vm_multianewarray   = 0x00c5,
	vm_ifnull           = 0x00c6,
	vm_ifnonnull        = 0x00c7,
	vm_goto_w           = 0x00c8,
	vm_jsr_w            = 0x00c9,
	vm_breakpoint       = 0x00ca,
	vm_impdep1          = 0x00fe,
	vm_impdep2          = 0x00ff
};


// enum 
std::string instruction_tt[256] = {
	"nop","aconst_null","iconst_m1","iconst_0","iconst_1","iconst_2","iconst_3","iconst_4","iconst_5",
	"lconst_0","lconst_1","fconst_0","fconst_1","fconst_2","dconst_0","dconst_1","bipush", "sipush",
	"ldc","ldc_w","ldc2_w","iload","lload","fload","dload", "aload","iload_0","iload_1","iload_2",
	"iload_3","lload_0","lload_1","lload_2", "lload_3","fload_0","fload_1","fload_2","fload_3",
	"dload_0","dload_1","dload_2","dload_3","aload_0","aload_1","aload_2","aload_3","iaload","laload",
	"faload","daload","aaload","baload","caload","saload","istore","lstore","fstore","dstore","astore",
	"istore_0","istore_1","istore_2","istore_3","lstore_0","lstore_1","lstore_2","lstore_3","fstore_0",
	"fstore_1","fstore_2","fstore_3","dstore_0","dstore_1","dstore_2","dstore_3","astore_0","astore_1",
	"astore_2","astore_3","iastore","lastore","fastore","dastore","aastore","bastore","castore",
	"sastore","pop","pop2","dup","dup_x1","dup_x2","dup2","dup2_x1","dup2_x2","swap","iadd","ladd",
	"fadd","dadd","isub","lsub","fsub","dsub","imul","lmul","fmul","dmul","idiv","ldiv","fdiv","ddiv",
	"irem","lrem","frem","drem","ineg","lneg","fneg","dneg","ishl","lshl","ishr","lshr","iushr","lushr",
	"iand","land","ior","lor","ixor","lxor","iinc","i2l","i2f","i2d","l2i","l2f","l2d","f2i","f2l","f2d",
	"d2i","d2l","d2f","i2b","i2c","i2s","lcmp","fcmpl","fcmpg","dcmpl","dcmpg","ifeq","ifne","iflt",
	"ifge","ifgt","ifle","if_icmpeq","if_icmpne","if_icmplt","if_icmpge","if_icmpgt","if_icmple",
	"if_acmpeq","if_acmpne","goto","jsr","ret","tableswitch","lookupswitch","ireturn","lreturn","freturn",
	"dreturn","areturn","return","getstatic","putstatic","getfield","putfield","invokevirtual","invokespecial",
	"invokestatic","invokeinterface","invokedynamic","new","newarray","anewarray","arraylength","athrow",
	"checkcast","instanceof","monitorenter","monitorexit","wide","multianewarray","ifnull","ifnonnull",
	"goto_w","jsr_w","breakpoint","","","","","","","","","","","","","","","","","","","","","","","",
	"","","","","","","","","","","","","","","","","","","","","","","","","","","","","impdep1","impdep2"
};
enum ClassUnit{
	U1 = 1,
	U2 = 2, 
	U4 = 4
};

enum AttributeTypes{
	ATTRIBUTE_Unrecognized = 0,
	ATTRIBUTE_ConstantValue = 1,
	ATTRIBUTE_Code = 2,
	ATTRIBUTE_StackMapTable = 3,
	ATTRIBUTE_Exceptions = 4,
	ATTRIBUTE_InnerClasses = 5,
	ATTRIBUTE_EnclosingMethod = 6,
	ATTRIBUTE_Synthetic = 7,
	ATTRIBUTE_Signature = 8,
	ATTRIBUTE_SourceFile = 9,
	ATTRIBUTE_SourceDebugExtension = 10,
	ATTRIBUTE_LineNumberTable = 11,
	ATTRIBUTE_LocalVariableTable = 12,
	ATTRIBUTE_LocalVariableTypeTable = 13,
	ATTRIBUTE_Deprecated = 14,
	ATTRIBUTE_RuntimeVisibleAnnotations = 15,
	ATTRIBUTE_RuntimeInvisibleAnnotations = 16,
	ATTRIBUTE_RuntimeVisibleParameterAnnotations = 17,
	ATTRIBUTE_RuntimeInvisibleParameterAnnotations = 18,
	ATTRIBUTE_AnnotationDefault = 19,
	ATTRIBUTE_BootstrapMethods = 20
};

std::string attribute_types_tt[] = {
	"",
	"ConstantValue",
	"Code",
	"StackMapTable",
	"Exceptions",
	"InnerClasses",
	"EnclosingMethod",
	"Synthetic",
	"Signature",
	"SourceFile",
	"SourceDebugExtension",
	"LineNumberTable",
	"LocalVariableTable",
	"LocalVariableTypeTable",
	"Deprecated",
	"RuntimeVisibleAnnotations",
	"RuntimeInvisibleAnnotations",
	"RuntimeVisibleParameterAnnotations",
	"RuntimeInvisibleParameterAnnotations",
	"AnnotationDefault",
	"BootstrapMethods"
};

enum KoolTypes{
	KOOL_Int,
	KOOL_IntArray,
	KOOL_Bool,
	KOOL_String,
	KOOL_Object
};

enum ConstantPoolTags{
	CONSTANT_Class = 7,
	CONSTANT_Fieldref = 9,
	CONSTANT_Methodref = 10,
	CONSTANT_InterfaceMethodref = 11,
	CONSTANT_String = 8,
	CONSTANT_Integer = 3,
	CONSTANT_Float = 4,
	CONSTANT_Long = 5,
	CONSTANT_Double = 6,
	CONSTANT_NameAndType = 12,
	CONSTANT_Utf8 = 1,
	CONSTANT_MethodHandle = 15,
	CONSTANT_MethodType = 16,
	CONSTANT_InvokeDynamic = 18
};


std::string constant_types_tt[] = {
	"",
	"Utf8","",
	"Integer",
	"Float",
	"Long",
	"Double",
	"Class",
	"String",
	"Fieldref",
	"Methodref",
	"InterfaceMethodref",
	"NameAndType","","",
	"MethodHandle",
	"MethodType","=",
	"InvokeDynamic"
};

namespace ClassAccess {
	enum Flags{
		ACC_PUBLIC		= 0x0001,	//Declared public; may be accessed from outside its package.
		ACC_FINAL		= 0x0010,	//Declared final; no subclasses allowed.
		ACC_SUPER		= 0x0020,	//Treat superclass methods specially when invoked by the invokespecial instruction.
		ACC_INTERFACE	= 0x0200,	//Is an interface, not a class.
		ACC_ABSTRACT	= 0x0400,	//Declared abstract; must not be instantiated.
		ACC_SYNTHETIC	= 0x1000,	//Declared synthetic; not present in the source code.
		ACC_ANNOTATION	= 0x2000,	//Declared as an annotation type.
		ACC_ENUM		= 0x4000	//Declared as an enum type.
	};

	std::string flags_tt[] = {
		"ACC_PUBLIC","","","",
		"ACC_FINAL","ACC_SUPER","","",
		"","ACC_INTERFACE","ACC_ABSTRACT","",
		"ACC_SYNTHETIC","ACC_ANNOTATION","ACC_ENUM",""
	};
}

namespace FieldAccess {
	enum Flags{
		ACC_PUBLIC		= 0x0001,	//Declared public; may be accessed from outside its package.
		ACC_PRIVATE		= 0x0002,	//Declared private; usable only within the defining class.
		ACC_PROTECTED	= 0x0004,	//Declared protected; may be accessed within subclasses.
		ACC_STATIC		= 0x0008,	//Declared static.
		ACC_FINAL		= 0x0010,	//Declared final; never directly assigned to after object construction (JLS §17.5).
		ACC_VOLATILE	= 0x0040,	//Declared volatile; cannot be cached.
		ACC_TRANSIENT	= 0x0080,	//Declared transient; not written or read by a persistent object manager.
		ACC_SYNTHETIC	= 0x1000,	//Declared synthetic; not present in the source code.
		ACC_ENUM		= 0x4000	//Declared as an element of an enum.
	};

	std::string flags_tt[] = {
		"ACC_PUBLIC","ACC_PRIVATE","ACC_PROTECTED","ACC_STATIC",
		"ACC_FINAL","","ACC_VOLATILE","ACC_TRANSIENT",
		"","","","",
		"ACC_SYNTHETIC","","ACC_ENUM",""
	};
}

namespace MethodAccess {
	enum Flags{
		ACC_PUBLIC			= 0x0001,	//Declared public; may be accessed from outside its package.
		ACC_PRIVATE			= 0x0002,	//Declared private; accessible only within the defining class.
		ACC_PROTECTED		= 0x0004,	//Declared protected; may be accessed within subclasses.
		ACC_STATIC			= 0x0008,	//Declared static.
		ACC_FINAL			= 0x0010,	//Declared final; must not be overridden (§5.4.5).
		ACC_SYNCHRONIZED	= 0x0020,	//Declared synchronized; invocation is wrapped by a monitor use.
		ACC_BRIDGE			= 0x0040,	//A bridge method, generated by the compiler.
		ACC_VARARGS			= 0x0080,	//Declared with variable number of arguments.
		ACC_NATIVE			= 0x0100,	//Declared native; implemented in a language other than Java.
		ACC_ABSTRACT		= 0x0400,	//Declared abstract; no implementation is provided.
		ACC_STRICT			= 0x0800,	//Declared strictfp; floating-point mode is FP-strict.
		ACC_SYNTHETIC		= 0x1000,	//Declared synthetic; not present in the source code.
	};

	std::string flags_tt[] = {
		"ACC_PUBLIC","ACC_PRIVATE","ACC_PROTECTED","ACC_STATIC",
		"ACC_FINAL","ACC_SYNCHRONIZED","ACC_BRIDGE","ACC_VARARGS",
		"ACC_NATIVE","","ACC_ABSTRACT","ACC_STRICT",
		"ACC_SYNTHETIC","","",""
	};
}

// std::map<std::string, unsigned int> attribute_map;


// ConstantValue
// Code
// StackMapTable
// Exceptions
// InnerClasses
// EnclosingMethod
// Synthetic
// Signature
// SourceFile
// SourceDebugExtension
// LineNumberTable
// LocalVariableTable
// LocalVariableTypeTable
// Deprecated
// RuntimeVisibleAnnotations
// RuntimeInvisibleAnnotations
// RuntimeVisibleParameterAnnotations
// RuntimeInvisibleParameterAnnotations
// AnnotationDefault
// BootstrapMethods

void print_access_flags(const unsigned int & u2_access_flags, const std::string (&flags_tt)[16]){
	if(u2_access_flags) printf("(");
	for(int i = 0, first_set = 0; i < 16; i++){
		if(u2_access_flags & 1<<i){
			if(first_set) printf(", "); else ++first_set;
			printf("%s", flags_tt[i].c_str());
		}
	}
	if(u2_access_flags) printf(")");
	printf("\n");
}

byte getHexValue(const std::string & hex_byte){
	byte myByte = 0;
	for(int i = 0; i < 2; i++){
		myByte = myByte<<4;
		if(47 < hex_byte[i] && hex_byte[i] < 58) myByte |= hex_byte[i]-48;
		if(64 < hex_byte[i] && hex_byte[i] < 71) myByte |= hex_byte[i]-55;
		if(96 < hex_byte[i] && hex_byte[i] < 103) myByte |= hex_byte[i]-87;
	}
	return myByte;
}

//_VM_DEF_CONST_TRANS_H_
#endif
