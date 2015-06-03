#ifndef _VM_FIELD_INFO_H_
#define _VM_FIELD_INFO_H_

// field_info {
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

class ConstantPool;

/**
 * \brief The FieldInfo class contains the info related to a field in a classfile,
 * the format is according to the JVM specification.
 */
class FieldInfo{
	unsigned int u2_access_flags;
	unsigned int u2_name_index;
	unsigned int u2_descriptor_index;

	std::vector<AttributeInfo> attribute_info_array;
	ConstantPool * cp;

	KoolTypes type;

public:
	FieldInfo(){}
	FieldInfo(std::function<unsigned int(ClassUnit)> fh_fetch, ConstantPool * _cp):attribute_info_array(std::vector<AttributeInfo>()), cp(_cp){
		//fetch bytes from source file
		u2_access_flags = fh_fetch(U2);
		u2_name_index = fh_fetch(U2);
		u2_descriptor_index = fh_fetch(U2);

		//fetch field attributes from source file
		unsigned int u2_attributes_count = fh_fetch(U2);
		for(int i = 0; i < u2_attributes_count; i++) attribute_info_array.push_back(AttributeInfo(fh_fetch, cp));

		//Set type, this is the only thing that is hardcoded for KOOL
		if("I" == get_field_descriptor()){
			type = KOOL_Int;
		}else if("Z" == get_field_descriptor()){
			type = KOOL_IntArray;
		}else if("[I" == get_field_descriptor()){
			type = KOOL_Bool;
		}else if("Ljava/lang/String;" == get_field_descriptor()){
			type = KOOL_String;
		}else{
			type = KOOL_Object;
		}
	}

	std::string get_field_name() {
		return cp->lookup(u2_name_index);
	}

	std::string get_field_descriptor(){
		return cp->lookup(u2_descriptor_index);
	}

	KoolTypes get_type(){
		return type;
	}

	void print() {
		printf("Field access flags: 0x%04x ", u2_access_flags);
		print_access_flags(u2_access_flags, FieldAccess::flags_tt);

		printf("name_index: #%u // %s\n", u2_name_index, cp->lookup(u2_name_index).c_str());
		printf("descriptor_index: #%u // %s\n", u2_descriptor_index, cp->lookup(u2_descriptor_index).c_str());

		printf("attributes count: %lu\n", attribute_info_array.size());
		for(int j = 0; j < attribute_info_array.size(); j++){
			attribute_info_array[j].print();
		}
	}
};


#endif
//_VM_FIELD_INFO_H_
