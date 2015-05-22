#ifndef _CONSTANT_POOL_ELEMENT_TYPES_H_
#define _CONSTANT_POOL_ELEMENT_TYPES_H_

#include "CodeHandler.h"
#include <sstream>
#include <string>

struct ConstantPoolElement {
	virtual unsigned int get_tag() = 0;
	virtual void print() = 0;
protected:
	ConstantPoolElement(){}
};
struct cp_Class: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Class;
	unsigned int u2_name_index; //1
	cp_Class(CodeHandler & coke):u2_name_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
		printf("#%u //u2_name_index", u2_name_index);
	};
};
struct cp_Fieldref: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Fieldref;
	unsigned int u2_class_index; //1
	unsigned int u2_name_and_type_index; //2
	cp_Fieldref(CodeHandler & coke):u2_class_index(coke.fetch(U2)), u2_name_and_type_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
		// u2 class_index;
	printf("#%u", coke.fetch(U2));
	// u2 name_and_type_index;
	printf(".#%u", coke.fetch(U2));
	
	printf(" //class_index.name_and_type_index");

	};
};
struct cp_Methodref: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Methodref;
	unsigned int u2_class_index; //1
	unsigned int u2_name_and_type_index; //2
	cp_Methodref(CodeHandler & coke):u2_class_index(coke.fetch(U2)), u2_name_and_type_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	// u2 class_index;
	printf("#%u", coke.fetch(U2));
	// u2 name_and_type_index;
	printf(".#%u", coke.fetch(U2));

	printf(" //class_index.name_and_type_index");

	};
};
struct cp_InterfaceMethodref: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_InterfaceMethodref;
	unsigned int u2_class_index;
	unsigned int u2_name_and_type_index;
	cp_InterfaceMethodref(CodeHandler & coke):u2_class_index(coke.fetch(U2)),u2_name_and_type_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
			// u2 class_index;
	printf("#%u", coke.fetch(U2));
	// u2 name_and_type_index;
	printf(", #%u", coke.fetch(U2));

	printf(" //TOTO(class_index, name_and_type_index)");

	};
};
struct cp_String: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_String;
	unsigned int u2_string_index; //1
	cp_String(CodeHandler & coke):u2_string_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
			// u2 string_index;
	printf("#%u", coke.fetch(U2));

	printf(" //string_index");

	};
};
struct cp_Integer: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Integer;
	unsigned int u4_bytes; //1
	cp_Integer(CodeHandler & coke):u4_bytes(coke.fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());

			// u4 bytes;
	printf("%u", coke.fetch(U4));
	
	printf(" //bytes");

	};
};
struct cp_Float: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Float;
	unsigned int u4_bytes; //1
	cp_Float(CodeHandler & coke):u4_bytes(coke.fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};
struct cp_Long: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Long;
	unsigned int u4_high_bytes; //1
	unsigned int u4_low_bytes; //2
	cp_Long(CodeHandler & coke):u4_high_bytes(coke.fetch(U4)), u4_low_bytes(coke.fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};
struct cp_Double: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Double;
	unsigned int u4_high_bytes; //1
	unsigned int u4_low_bytes; //2
	cp_Double(CodeHandler & coke):u4_high_bytes(coke.fetch(U4)), u4_low_bytes(coke.fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};
struct cp_NameAndType: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_NameAndType;
	unsigned int u2_name_index; //1
	unsigned int u2_descriptor_index; //2
	cp_NameAndType(CodeHandler & coke):u2_name_index(coke.fetch(U2)), u2_descriptor_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};
struct cp_Utf8: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Utf8;
	unsigned int u2_length; //1
	std::string u1_bytes_array; //2 u1_bytes[length]
	cp_Utf8(CodeHandler & coke):u2_length(coke.fetch(U2)){
		std::stringstream ss;
		for(int i = 0; i < u2_length; i++)
			ss << (char)coke.fetch(U1);
		u1_bytes_array = ss.str();
	}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};
struct cp_MethodHandle: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_MethodHandle;
	unsigned int u1_reference_kind; //1
	unsigned int u2_reference_index; //2
	cp_MethodHandle(CodeHandler & coke):u1_reference_kind(coke.fetch(U1)), u2_reference_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};
struct cp_MethodType: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_MethodType;
	unsigned int u2_descriptor_index; //1
	cp_MethodType(CodeHandler & coke):u2_descriptor_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};
struct cp_InvokeDynamic: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_InvokeDynamic;
	unsigned int u2_bootstrap_method_attr_index; //1
	unsigned int u2_name_and_type_index; //2
	cp_InvokeDynamic(CodeHandler & coke):u2_bootstrap_method_attr_index(coke.fetch(U2)), u2_name_and_type_index(coke.fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u = %-20s", i, constant_types_tt[tag].c_str());
		
	};
};

#endif
//_CONSTANT_POOL_ELEMENT_TYPES_H_