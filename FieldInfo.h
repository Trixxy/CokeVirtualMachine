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
		printf()
//	  u2             access_flags;
		coke.fetch(U2);
//    u2             name_index;
		coke.fetch(U2);
//    u2             descriptor_index;
		coke.fetch(U2);
//    u2             attributes_count;
		int attrc = coke.fetch(U2);
//    attribute_info attributes[attributes_count];
		for(int k = 0; k < attrc; k++) {
// 	  u2 attribute_name_index;
			coke.fetch(U2);
// 	  u4 attribute_length;
			int attrlen = coke.fetch(U4);
// 	  u1 info[attribute_length];
			for(int m = 0; m < attrlen; m++) {
				coke.fetch(U1);
			}
		}
	}
};


#endif
//_VM_FIELD_INFO_H_