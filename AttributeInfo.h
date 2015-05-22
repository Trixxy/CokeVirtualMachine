#ifndef _VM_ATTRIBUTE_INFO_H_
#define _VM_ATTRIBUTE_INFO_H_

#include "CodeHandler.h"

class AttributeInfo{
	unsigned int u2_attribute_name_index;
	std::vector<unsigned int> u1_info_array; //u1 info[attribute_length];
public:
	AttributeInfo(){}
	AttributeInfo(CodeHandler & coke):u1_info_array(std::vector<unsigned int>()){
		u2_attribute_name_index = coke.fetch(U2);
		unsigned int u4_attribute_length = coke.fetch(U4);
		for(int i = 0; i < u4_attribute_length; i++) u1_info_array.push_back(coke.fetch(U1));
	}

	void print() {
		// 	  u2 attribute_name_index;
		coke.fetch(U2);
// 	  u4 attribute_length;
		int attrlen = coke.fetch(U4);
// 	  u1 info[attribute_length];
		for(int m = 0; m < attrlen; m++) {
			coke.fetch(U1);
		}
	}
};


#endif
//_VM_ATTRIBUTE_INFO_H_