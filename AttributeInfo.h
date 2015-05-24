#ifndef _VM_ATTRIBUTE_INFO_H_
#define _VM_ATTRIBUTE_INFO_H_

#include <string>
#include <functional>

class AttributeInfo{
	unsigned int u2_attribute_name_index;
	std::vector<unsigned int> u1_info_array; //u1 info[attribute_length];
	std::function<std::string(int)> lookup;

public:
	AttributeInfo(){}
	AttributeInfo(std::function<unsigned int(ClassUnit)> fh_fetch, std::function<std::string(int)> lu):u1_info_array(std::vector<unsigned int>()), lookup(lu){
		u2_attribute_name_index = fh_fetch(U2);
		unsigned int u4_attribute_length = fh_fetch(U4);
		for(int i = 0; i < u4_attribute_length; i++) u1_info_array.push_back(fh_fetch(U1));
	}

	void print() {
		printf("attribute_name_index: #%u // %s\n", u2_attribute_name_index, lookup(u2_attribute_name_index).c_str());

		if(lookup(u2_attribute_name_index) == "Code"){
			int i = 0;
			printf("attribute_length: %lu\n", u1_info_array.size());
				
				unsigned int u2_max_stack;
				unsigned int u2_max_locals;
				unsigned int u4_code_length;

				for(int j = i+2; i < j; ++i) u2_max_stack = u2_max_stack<<8 | u1_info_array[i];
				for(int j = i+2; i < j; ++i) u2_max_locals = u2_max_locals<<8 | u1_info_array[i];
				for(int j = i+4; i < j; ++i) u4_code_length = u4_code_length<<8 | u1_info_array[i];
				
				printf("max stack: %u \t max locals: %u\n", u2_max_stack, u2_max_locals);
				for(int j = i+u4_code_length, index = 0; i < j; ++i, ++index)
					printf("[%4u]:\t%s\n", index, instruction_tt[u1_info_array[i]].c_str());
				
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
	}
};


#endif
//_VM_ATTRIBUTE_INFO_H_