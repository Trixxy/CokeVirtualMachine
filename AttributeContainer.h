#ifndef _ATTRIBUTE_CONTAINER_H_
#define _ATTRIBUTE_CONTAINER_H_

#include <functional>
#include <vector>
#include <string>
#include "ProgramCode.h"

struct AttributeContainer {
	std::vector<unsigned int> u1_info_array; //u1 info[attribute_length];
	virtual AttributeTypes get_type() = 0;
	virtual void print() = 0;
protected:
	AttributeContainer():u1_info_array(std::vector<unsigned int>()){}
};
struct ac_ConstantValue: public AttributeContainer {
	static const AttributeTypes type = ATTRIBUTE_ConstantValue;

	ac_ConstantValue(std::function<unsigned int(ClassUnit)> fh_fetch):AttributeContainer(){
		unsigned int u4_attribute_length = fh_fetch(U4);
		for(int i = 0; i < u4_attribute_length; i++) u1_info_array.push_back(fh_fetch(U1));
	}

	virtual AttributeTypes get_type(){ return type; }
	virtual void print(){
		printf("Unimplemented Attribute: %s", attribute_types_tt[type].c_str());
	}
};
struct ac_Code: public AttributeContainer {
	static const AttributeTypes type = ATTRIBUTE_Code;
	unsigned int u2_max_stack;
	unsigned int u2_max_locals;
	unsigned int u4_code_length;

private: ProgramCode coke; public:

	ac_Code(std::function<unsigned int(ClassUnit)> fh_fetch):AttributeContainer(), coke(ProgramCode()){
		unsigned int u4_attribute_length = fh_fetch(U4);
		// for(int i = 0; i < u4_attribute_length; i++) u1_info_array.push_back(fh_fetch(U1));

		int i = 0;

		u2_max_stack = fh_fetch(U2); i+=2;
		u2_max_locals = fh_fetch(U2); i+=2;
		u4_code_length = fh_fetch(U4); i+=4;
		
		for(int j = i+u4_code_length; i < j; ++i)
			coke.code.push_back(fh_fetch(U1));
			
		//IGNORE THE REST
		for(; i < u4_attribute_length; i++) u1_info_array.push_back(fh_fetch(U1));

		// unsigned int u2_exception_table_length;
		// for(int j = i+2; i < j; ++i) u2_exception_table_length = u2_exception_table_length<<8 | u1_info_array[i];

		//    {   unsigned int u2_start_pc;
		//        unsigned int u2_end_pc;
		//        unsigned int u2_handler_pc;
		//        unsigned int u2_catch_type;
		//    } exception_table[exception_table_length];
		//    unsigned int u2_attributes_count;
		//    attribute_info attributes[attributes_count];
	}

	ProgramCode get_coke(){
		return coke;
	}

	virtual AttributeTypes get_type(){ return type; }
	virtual void print(){
		printf("Attribute type: %s\n", attribute_types_tt[type].c_str());
		printf("max stack: %u \t max locals: %u\n", u2_max_stack, u2_max_locals);
		auto coke = get_coke();
		while(coke.has_next()){
			printf("[%4u]:\t%s\n", coke.get_pc(), instruction_tt[coke.next_inst()].c_str());
		}
	}
};
struct ac_UnImplemented: public AttributeContainer {
	AttributeTypes type;
	ac_UnImplemented(std::function<unsigned int(ClassUnit)> fh_fetch, AttributeTypes t):AttributeContainer(), type(t){
		unsigned int u4_attribute_length = fh_fetch(U4);
		for(int i = 0; i < u4_attribute_length; i++) u1_info_array.push_back(fh_fetch(U1));
	}
	virtual AttributeTypes get_type(){ return type; }
	virtual void print(){
		printf("Unimplemented Attribute: %s", attribute_types_tt[type].c_str());
	}
};
struct ac_UnRecognized: public AttributeContainer {
	std::string type;
	ac_UnRecognized(std::function<unsigned int(ClassUnit)> fh_fetch, std::string t):AttributeContainer(), type(t){
		unsigned int u4_attribute_length = fh_fetch(U4);
		for(int i = 0; i < u4_attribute_length; i++) u1_info_array.push_back(fh_fetch(U1));
	}
	virtual AttributeTypes get_type(){ return ATTRIBUTE_Unrecognized; }
	virtual void print(){
		printf("Unrecognized Attribute: %s", type.c_str());
	}
};




#endif
//_ATTRIBUTE_CONTAINER_H_