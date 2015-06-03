#ifndef _VM_CLASS_FILE_H_
#define _VM_CLASS_FILE_H_

#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <cassert>
#include "DefConstTrans.h"
#include "FileHandler.h"
#include "ConstantPool.h"
#include "FieldInfo.h"
#include "MethodInfo.h"
#include "AttributeInfo.h"
#include "ObjectRef.h"

/* CONTENT OF FILE:

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

/**
 * \brief The ClassFile class parses a classfiles according to the format
 * specified in the JVM specification
 */
class ClassFile{
	FileHandler fh; //file handler
	unsigned int u4_magic;
	unsigned int u2_minor_version;
	unsigned int u2_major_version;
	ConstantPool const_pool;
	unsigned int u2_access_flags;
	unsigned int u2_this_class;
	unsigned int u2_super_class;
	std::vector<unsigned int> u2_interfaces_array; //interfaces[interfaces_count];
	std::map<std::string, FieldInfo *> field_info_array; //fields[fields_count];
	std::map<std::string, MethodInfo *> method_info_array; //methods[methods_count];
	std::map<std::string, AttributeInfo *> attribute_info_array; //attributes[attributes_count];
	std::function<unsigned int(ObjectRef *)> heap_push;

public:
	ClassFile(){}
	ClassFile(const std::string & file_path):
		fh(FileHandler(file_path)),
		u2_interfaces_array(std::vector<unsigned int>()),
		field_info_array(std::map<std::string, FieldInfo *>()),
		method_info_array(std::map<std::string, MethodInfo *>()),
		attribute_info_array(std::map<std::string, AttributeInfo *>()){

		auto fetch = [&](ClassUnit U){ return fh.fetch(U); };
		const_pool = ConstantPool(fetch);

		//Read meta data
		u4_magic = fh.fetch(U4);
		u2_minor_version = fh.fetch(U2);
		u2_major_version = fh.fetch(U2);

		//Read constant pool
		unsigned int constant_pool_count = fh.fetch(U2);
		for(unsigned int i = 1; i < constant_pool_count; i++) const_pool.push_back(fh.fetch(U1));
		
		u2_access_flags = fh.fetch(U2); //Read access flags 
		u2_this_class = fh.fetch(U2); //Read class name (index)
		u2_super_class = fh.fetch(U2); //Read parent class name (index)
		
		//Read interfaces
		unsigned int interfaces_count = fh.fetch(U2);
		for(unsigned int i = 0; i < interfaces_count; i++) u2_interfaces_array.push_back(fh.fetch(U2));

		//Read fields
		unsigned int fields_count = fh.fetch(U2);
		for(unsigned int i = 0; i < fields_count; i++){
			FieldInfo * fi = new FieldInfo(fetch, &const_pool);
			field_info_array[fi->get_field_name()] = fi;
		}

		//Read methods
		unsigned int methods_count = fh.fetch(U2);
		for(unsigned int i = 0; i < methods_count; i++){
			MethodInfo * mi = new MethodInfo(fetch, &const_pool);
			method_info_array[mi->get_method_name()] = mi;
		}

		//Read class attributes
		unsigned int attributes_count = fh.fetch(U2);
		for(unsigned int i = 0; i < attributes_count; i++){
			AttributeInfo * ai = new AttributeInfo(fetch, &const_pool);
			attribute_info_array[ai->get_attribute_name()] = ai;
		}

		assert(fh.size() == fh.get_cc()); //Check that we actually consumed the whole file.
	}

	void set_heap(std::function<unsigned int(ObjectRef *)> hp){
		heap_push = hp;
	}

	void print(){
	 	printf("Magic: 0x%08x\n", u4_magic);
		printf("Minor version: %u\n", u2_minor_version);
	 	printf("Major version: %u\n", u2_major_version);

		//constant pool
		const_pool.print();

		printf("\n");
		
		printf("Class access flags: 0x%04x ", u2_access_flags);
		print_access_flags(u2_access_flags, ClassAccess::flags_tt);

	 	printf("This class: #%u // %s\n", u2_this_class, get_class_name().c_str());
		printf("Super class: #%u // %s\n", u2_super_class, get_super_name().c_str());
		printf("interfaces count: %lu\n", u2_interfaces_array.size());
		for(unsigned int j = 0; j < u2_interfaces_array.size(); j++) {
			printf("%u\n", u2_interfaces_array[j]);
		}

		printf("\n");

		printf("fields count: %lu\n\n", field_info_array.size());
		for (auto it = field_info_array.begin(); it != field_info_array.end(); ++it){
			it->second->print();
			printf("\n");
		}

		printf("\n");

		printf("methods count: %lu\n\n", method_info_array.size());
		for (auto it = method_info_array.begin(); it != method_info_array.end(); ++it){
			it->second->print();
			printf("\n");
		}

		printf("\n");

		printf("attributes count: %lu\n\n", attribute_info_array.size());
		for (auto it = attribute_info_array.begin(); it != attribute_info_array.end(); ++it){
			it->second->print();
			printf("\n");
		}
	}

	unsigned int allocate_object(){
		ObjectRef * obj = new ObjectRef(&const_pool);
		for (auto it = field_info_array.begin(); it != field_info_array.end(); ++it){
			obj->finder[it->second->get_field_name()] = obj->fields.size();
			switch(it->second->get_type()){
				case KOOL_Int:
					obj->fields.push_back(new int);
					break;
				case KOOL_IntArray:
					obj->fields.push_back(new std::vector<int>());
					break;
				case KOOL_Bool:
					obj->fields.push_back(new bool);
					break;
				case KOOL_String:
					obj->fields.push_back(new std::string());
					break;
				case KOOL_Object:
					obj->fields.push_back(NULL);
					break;
			}
		}
		return heap_push(obj);
		return 0;
	}

	void link(std::function<ClassFile*(std::string)> rte_lookup){

	}

	MethodInfo * get_method(const std::string & name){
		if(method_info_array.find(name) != method_info_array.end())
			return method_info_array[name];
		else return NULL;
	}

	FieldInfo * get_field(const std::string & name){
		return field_info_array[name];
	}

	const unsigned int & get_magic() const { return u4_magic; }
	const unsigned int & get_minor_version() const { return u2_minor_version; }
	const unsigned int & get_major_version() const { return u2_major_version; }
	const unsigned int & get_access_flags() const { return u2_access_flags; }
	const unsigned int & get_this_class() const { return u2_this_class; }
	const unsigned int & get_super_class() const { return u2_super_class; }

	std::string get_class_name(){ return const_pool.lookup(get_this_class()); }
	std::string get_super_name(){ return const_pool.lookup(get_super_class()); }

	FileHandler & get_fh(){ return fh; }
};

#endif
//_VM_CLASS_FILE_H_
