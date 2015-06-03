#ifndef _VM_METHOD_INFO_H_
#define _VM_METHOD_INFO_H_

// method_info {
//     u2             access_flags;
//     u2             name_index;
//     u2             descriptor_index;
//     u2             attributes_count;
//     attribute_info attributes[attributes_count];
// }

#include <vector>
#include <string>
#include <functional>
#include "DefConstTrans.h"
#include "AttributeInfo.h"

class ConstantPool; //forward-reference

/**
 * \brief The MethodInfo class contains the info related to a method in a classfile,
 * the format is according to the JVM specification.
 */
class MethodInfo{
	unsigned int u2_access_flags;
	unsigned int u2_name_index;
	unsigned int u2_descriptor_index;
	std::vector<AttributeInfo> attribute_info_array;
	ConstantPool * cp;
	unsigned int args_size;

public:
	MethodInfo(){}
	MethodInfo(std::function<unsigned int(ClassUnit)> fh_fetch, ConstantPool * _cp):attribute_info_array(std::vector<AttributeInfo>()), cp(_cp), args_size(1){
		u2_access_flags = fh_fetch(U2);
		u2_name_index = fh_fetch(U2);
		u2_descriptor_index = fh_fetch(U2);
		unsigned int u2_attributes_count = fh_fetch(U2);
		for(unsigned int i = 0; i < u2_attributes_count; i++) attribute_info_array.push_back(AttributeInfo(fh_fetch, cp));

		//a small lexer to count the num of args (including objref)
		std::string descr = cp->lookup(u2_descriptor_index);
		for(unsigned int i = 0, ignore = 0; i < descr.size(); i++){
			if(!ignore){
				switch(descr[i]){
				case 'I':
				case 'Z':
					++args_size;
					break;
				case 'L':
					++args_size;
					++ignore;
					break;
				case ')':goto ARG_LEX;
				}}else if(!(';'^descr[i]))--ignore;
		} ARG_LEX: void(0);
	}

	bool is_main(){
		return ("main" == cp->lookup(u2_name_index));
	}

	bool is_init(){
		return ("<init>" == cp->lookup(u2_name_index));
	}

	ac_Code * get_acCode(){
		for(unsigned int i = 0; i < attribute_info_array.size(); i++) if(ATTRIBUTE_Code == attribute_info_array[i].get_type()){
				return (ac_Code *)attribute_info_array[i].get_container();
		}
		fprintf(stderr, "Error: Pepsi Method found no Main Coke.");
		return NULL;
	}

	std::string get_method_name() {
		return cp->lookup(u2_name_index);
	}

	std::string get_method_descriptor(){
		return cp->lookup(u2_descriptor_index);
	}

	ConstantPool * get_cp(){
		return cp;
	}

	unsigned int get_args_size(){
		return args_size;
	}

	void print() {
		printf("Method access flags: 0x%04x ", u2_access_flags);
		print_access_flags(u2_access_flags, MethodAccess::flags_tt);

		printf("name_index: #%u // %s\n", u2_name_index, cp->lookup(u2_name_index).c_str());
		printf("descriptor_index: #%u // %s\n", u2_descriptor_index, cp->lookup(u2_descriptor_index).c_str());

		printf("attributes count: %lu\n", attribute_info_array.size());
		for(unsigned int j = 0; j < attribute_info_array.size(); j++){
			attribute_info_array[j].print();
		}
	}
};


#endif
//_VM_METHOD_INFO_H_
