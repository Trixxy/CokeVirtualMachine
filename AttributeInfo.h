#ifndef _VM_ATTRIBUTE_INFO_H_
#define _VM_ATTRIBUTE_INFO_H_

#include <string>
#include <functional>
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

	void print(std::function<std::string(int)> lookup) {
		printf("attribute_name_index: #%u // %s\n", u2_attribute_name_index, lookup(u2_attribute_name_index).c_str());	
	}
};


#endif
//_VM_ATTRIBUTE_INFO_H_