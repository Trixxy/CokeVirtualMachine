#ifndef _VM_DEF_CONST_TRANS_H_
#define _VM_DEF_CONST_TRANS_H_

#define byte unsigned char
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


enum ClassAttributes{
	ConstantValue = 0,
	Code = 1,
	StackMapTable = 2,
	Exceptions = 3,
	InnerClasses = 4,
	EnclosingMethod = 5,
	Synthetic = 6,
	Signature = 7,
	SourceFile = 8,
	SourceDebugExtension = 9,
	LineNumberTable = 10,
	LocalVariableTable = 11,
	LocalVariableTypeTable = 12,
	Deprecated = 13,
	RuntimeVisibleAnnotations = 14,
	RuntimeInvisibleAnnotations = 15,
	RuntimeVisibleParameterAnnotations = 16,
	RuntimeInvisibleParameterAnnotations = 17,
	AnnotationDefault = 18,
	BootstrapMethods = 19
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
