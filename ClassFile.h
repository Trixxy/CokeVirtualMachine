#ifndef _VM_CLASS_FILE_H_
#define _VM_CLASS_FILE_H_

#include <cstdio>
#include "CodeHandler.h"
#include <string>
#include "DefConstTrans.h"
#include "ConstantPool.h"
#include "FieldInfo.h"
#include "MethodInfo.h"
#include "AttributeInfo.h"

/*
u4             magic;
u2             minor_version;
u2             major_version;
u2             constant_pool_count;
cp_info        constant_pool[constant_pool_count-1];
u2             access_flags;
u2             this_class;
u2             super_class;
u2             interfaces_count;
u2             interfaces[interfaces_count];
u2             fields_count;
field_info     fields[fields_count];
u2             methods_count;
method_info    methods[methods_count];

u2             attributes_count;
attribute_info attributes[attributes_count];
*/

class ClassFile{
	CodeHandler cch; //class code handler
	unsigned int u4_magic;
	unsigned int u2_minor_version;
	unsigned int u2_major_version;
	ConstantPool const_pool;
	unsigned int u2_access_flags;
	unsigned int u2_this_class;
	unsigned int u2_super_class;
	std::vector<unsigned int> u2_interfaces_array; //interfaces[interfaces_count];
	std::vector<FieldInfo> field_info_array; //fields[fields_count];
	std::vector<MethodInfo> method_info_array; //methods[methods_count];
	std::vector<AttributeInfo> attribute_info_array; //attributes[attributes_count];
public:
	ClassFile(){}
	ClassFile(const std::string & file_path):cch(CodeHandler(file_path)), const_pool(ConstantPool(&cch)), u2_interfaces_array(std::vector<unsigned int>()), field_info_array(std::vector<FieldInfo>()), method_info_array(std::vector<MethodInfo>()), attribute_info_array(std::vector<AttributeInfo>()){
		u4_magic = cch.fetch(U4);
		u2_minor_version = cch.fetch(U2);
		u2_major_version = cch.fetch(U2);

		unsigned int constant_pool_count = cch.fetch(U2);
		for(int i = 1; i < constant_pool_count; i++) const_pool.push_back(cch.fetch(U1));
		
		u2_access_flags = cch.fetch(U2);
		u2_this_class = cch.fetch(U2);
		u2_super_class = cch.fetch(U2);
		
		unsigned int interfaces_count = cch.fetch(U2);
		for(int i = 0; i < interfaces_count; i++) u2_interfaces_array.push_back(cch.fetch(U2));

		unsigned int fields_count = cch.fetch(U2);
		for(int i = 0; i < fields_count; i++) field_info_array.push_back(FieldInfo(cch));

		unsigned int methods_count = cch.fetch(U2);
		for(int i = 0; i < methods_count; i++) method_info_array.push_back(MethodInfo(cch));

		unsigned int attributes_count = cch.fetch(U2);
		for(int i = 0; i < attributes_count; i++) attribute_info_array.push_back(AttributeInfo(cch));
	}

	void print(){
		using namespace class_namespace;

	 	printf("Magic: 0x%08x\n", u4_magic);
		printf("Minor version: %u\n", u2_minor_version);
	 	printf("Major version: %u\n", u2_major_version);

		//constant pool
		const_pool.print();

// 	//accesscflags
// 	process_access_flags(coke);

	 	printf("This class: %u\n", u2_this_class);
		printf("Super class: %u\n", u2_super_class);
		printf("interfaces count: %lu\n", u2_interfaces_array.size());
		for(int j = 0; j < u2_interfaces_array.size(); j++) {
			printf("%u\n", u2_interfaces_array[j]);
		}

		printf("fields count: %lu\n", field_info_array.size());
		for(int j = 0; j < field_info_array.size(); j++){
			field_info_array[j].print();
		}
		printf("methods count: %lu\n", method_info_array.size());
		for(int j = 0; j < method_info_array.size(); j++){
			method_info_array[j].print();
		}
		printf("attributes count: %lu\n", attribute_info_array.size());
		for(int j = 0; j < attribute_info_array.size(); j++){
			attribute_info_array[j].print();
		}
	}

	void tmp_unused_for_now(){
		using namespace class_namespace;
		
		printf("Access flags: 0x%04x\n", u2_access_flags);
		if(u2_access_flags) printf("\t");
		for(int i = 0; i < 16; i++){
			if(u2_access_flags & 1<<i){
				printf("%s, ", class_access_flags_tt[i].c_str());
			}
		}
		printf("\n");
	}


	const unsigned int & get_magic() const {
		return u4_magic;
	}

	const unsigned int & get_minor_version() const {
		return u2_minor_version;
	}

	const unsigned int & get_major_version() const {
		return u2_major_version;
	}

	const unsigned int & get_access_flags() const {
		return u2_access_flags;
	}

	const unsigned int & get_this_class() const {
		return u2_this_class;
	}

	const unsigned int & get_super_class() const {
		return u2_super_class;
	}

	CodeHandler & get_code_handler(){
		return cch;
	}
};

#endif
//_VM_CLASS_FILE_H_
