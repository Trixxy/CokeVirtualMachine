// method_info {
//     u2             access_flags;
//     u2             name_index;
//     u2             descriptor_index;
//     u2             attributes_count;
//     attribute_info attributes[attributes_count];
// }

#ifndef _VM_METHOD_INFO_H_
#define _VM_METHOD_INFO_H_

#include <vector>
#include <string>
#include <functional>
#include "DefConstTrans.h"
#include "AttributeInfo.h"
#include "CodeHandler.h"

class MethodInfo{
	unsigned int u2_access_flags;
	unsigned int u2_name_index;
	unsigned int u2_descriptor_index;
	std::vector<AttributeInfo> attribute_info_array;

public:
	MethodInfo(){}
	MethodInfo(CodeHandler & coke):attribute_info_array(std::vector<AttributeInfo>()){
		u2_access_flags = coke.fetch(U2);
		u2_name_index = coke.fetch(U2);
		u2_descriptor_index = coke.fetch(U2);
		unsigned int u2_attributes_count = coke.fetch(U2);
		for(int i = 0; i < u2_attributes_count; i++) attribute_info_array.push_back(AttributeInfo(coke));
	}

	void print(std::function<std::string(int)> lookup) {
		printf("Method access flags: 0x%04x ", u2_access_flags);
		print_access_flags(u2_access_flags, MethodAccess::flags_tt);

		printf("name_index: #%u // %s\n", u2_name_index, lookup(u2_name_index).c_str());
		printf("descriptor_index: #%u // %s\n", u2_descriptor_index, lookup(u2_descriptor_index).c_str());

		printf("attributes count: %lu\n", attribute_info_array.size());
		for(int j = 0; j < attribute_info_array.size(); j++){
			attribute_info_array[j].print(lookup);
		}
	}
};


#endif
//_VM_METHOD_INFO_H_