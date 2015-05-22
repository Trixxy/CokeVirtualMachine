// field_info {
//     u2             access_flags;
//     u2             name_index;
//     u2             descriptor_index;
//     u2             attributes_count;
//     attribute_info attributes[attributes_count];
// }

#ifndef _VM_FIELD_INFO_H_
#define _VM_FIELD_INFO_H_

#include <vector>
#include "AttributeInfo.h"
#include "CodeHandler.h"

class FieldInfo{
	unsigned int u2_access_flags;
	unsigned int u2_name_index;
	unsigned int u2_descriptor_index;
	std::vector<AttributeInfo> attribute_info_array;
public:
	FieldInfo(){}
	FieldInfo(CodeHandler & coke):attribute_info_array(std::vector<AttributeInfo>()){
		u2_access_flags = coke.fetch(U2);
		u2_name_index = coke.fetch(U2);
		u2_descriptor_index = coke.fetch(U2);
		unsigned int u2_attributes_count = coke.fetch(U2);
		for(int i = 0; i < u2_attributes_count; i++) attribute_info_array.push_back(AttributeInfo(coke));
	}

	void print() {
		using namespace field_namespace;

		printf("Field access flags: 0x%04x\n", u2_access_flags);
		if(u2_access_flags) printf("\t");
		for(int i = 0; i < 16; i++){
			if(u2_access_flags & 1<<i){
				printf("%s, ", field_access_flags_tt[i].c_str());
			}
		}
		printf("\n");

		printf("name_index: %u\n", u2_name_index);
		printf("descriptor_index: %u\n", u2_descriptor_index);

		printf("attributes count: %lu\n", attribute_info_array.size());
		for(int j = 0; j < attribute_info_array.size(); j++){
			attribute_info_array[j].print();
		}
	}
};


#endif
//_VM_FIELD_INFO_H_