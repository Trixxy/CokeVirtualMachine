#ifndef _VM_CONSTANT_POOL_H_
#define _VM_CONSTANT_POOL_H_

#include <iostream>
#include <sstream>
#include <functional>
#include "DefConstTrans.h"
#include "ConstantPoolElement.h"

class ClassFile; //forward-reference

/**
 * \brief The ConstantPool class represents a run-time constant pool according
 * to the JVM specification.
 */
class ConstantPool{
	std::vector<ConstantPoolElement*> elem;
	std::function<unsigned int(ClassUnit)> fh_fetch;

	void lookup(unsigned int i, std::stringstream & str){
		--i;
		switch(elem[i]->get_tag()){
			case CONSTANT_Class: 
				lookup(((cp_Class *)elem[i])->u2_name_index, str);
				break;
			case CONSTANT_Fieldref: 
				lookup(((cp_Fieldref *)elem[i])->u2_class_index, str);
				str << ".";
				lookup(((cp_Fieldref *)elem[i])->u2_name_and_type_index, str);
				break;
			case CONSTANT_Methodref: 
				lookup(((cp_Methodref *)elem[i])->u2_class_index, str);
				str << ".";
				lookup(((cp_Methodref *)elem[i])->u2_name_and_type_index, str);
				break;
			case CONSTANT_InterfaceMethodref: 
				lookup(((cp_InterfaceMethodref *)elem[i])->u2_class_index, str);
				str << "??";
				lookup(((cp_InterfaceMethodref *)elem[i])->u2_name_and_type_index, str);
				break;
			case CONSTANT_String: 
				lookup(((cp_String *)elem[i])->u2_string_index, str);
				break;
			case CONSTANT_Integer: 
				break;
			case CONSTANT_Float: 
				break;
			case CONSTANT_Long: 
				break;
			case CONSTANT_Double: 
				break;
			case CONSTANT_NameAndType: 
				lookup(((cp_NameAndType *)elem[i])->u2_name_index, str);
				str << ":";
				lookup(((cp_NameAndType *)elem[i])->u2_descriptor_index, str);
				break;
			case CONSTANT_Utf8: 
				str << ((cp_Utf8 *)elem[i])->u1_bytes_array;
				break;
			case CONSTANT_MethodHandle: 
				break;
			case CONSTANT_MethodType: 
				break;
			case CONSTANT_InvokeDynamic: 
				break;	
			default: std::cerr << "Unrecognized constant pool tag.\n";
		}
	}

public:
	ConstantPool(){}
	ConstantPool(std::function<unsigned int(ClassUnit)> fetch):elem(std::vector<ConstantPoolElement*>()), fh_fetch(fetch){}
	~ConstantPool(){
		for(int i = 0; i < elem.size(); i++) delete elem[i];
	}

	/**
	 * Pushes an element to the constant pool that matches the tag. 
	 */
	void push_back(const unsigned int & tag){
		switch(tag){
			case CONSTANT_Class: elem.push_back(new cp_Class(fh_fetch)); break;
			case CONSTANT_Fieldref: elem.push_back(new cp_Fieldref(fh_fetch)); break;
			case CONSTANT_Methodref: elem.push_back(new cp_Methodref(fh_fetch)); break;
			case CONSTANT_InterfaceMethodref: elem.push_back(new cp_InterfaceMethodref(fh_fetch)); break;
			case CONSTANT_String: elem.push_back(new cp_String(fh_fetch)); break;
			case CONSTANT_Integer: elem.push_back(new cp_Integer(fh_fetch)); break;
			case CONSTANT_Float: elem.push_back(new cp_Float(fh_fetch)); break;
			case CONSTANT_Long: elem.push_back(new cp_Long(fh_fetch)); break;
			case CONSTANT_Double: elem.push_back(new cp_Double(fh_fetch)); break;
			case CONSTANT_NameAndType: elem.push_back(new cp_NameAndType(fh_fetch)); break;
			case CONSTANT_Utf8: elem.push_back(new cp_Utf8(fh_fetch)); break;
			case CONSTANT_MethodHandle: elem.push_back(new cp_MethodHandle(fh_fetch)); break;
			case CONSTANT_MethodType: elem.push_back(new cp_MethodType(fh_fetch)); break;
			case CONSTANT_InvokeDynamic: elem.push_back(new cp_InvokeDynamic(fh_fetch)); break;	
			default: std::cerr << "Unrecognized constant pool tag.\n"; break;
		}
	}

	std::string get_ref_class(unsigned int i){
		--i;
		switch(elem[i]->get_tag()){
			case CONSTANT_Class:
				return get_ref_class((((cp_Class *)elem[i])->u2_name_index));
				break;
			case CONSTANT_Fieldref:
				return get_ref_class(((cp_Fieldref *)elem[i])->u2_class_index);
				break;
			case CONSTANT_Methodref:
				return get_ref_class(((cp_Methodref *)elem[i])->u2_class_index);
				break;
			case CONSTANT_InterfaceMethodref:
				return get_ref_class(((cp_InterfaceMethodref *)elem[i])->u2_class_index);
				break;
			case CONSTANT_String:
				break;
			case CONSTANT_Integer:
				break;
			case CONSTANT_Float:
				break;
			case CONSTANT_Long:
				break;
			case CONSTANT_Double:
				break;
			case CONSTANT_NameAndType:
				break;
			case CONSTANT_Utf8:
				return ((cp_Utf8 *)elem[i])->u1_bytes_array;
				break;
			case CONSTANT_MethodHandle:
				break;
			case CONSTANT_MethodType:
				break;
			case CONSTANT_InvokeDynamic:
				break;
			default: std::cerr << "Unrecognized constant pool tag.\n";
				break;
		}
	}

	std::string get_ref_method(unsigned int i){
		--i;
		switch(elem[i]->get_tag()){
			case CONSTANT_Class:
				break;
			case CONSTANT_Fieldref:
				return get_ref_method(((cp_Fieldref *)elem[i])->u2_name_and_type_index);
				break;
			case CONSTANT_Methodref:
				return get_ref_method(((cp_Methodref *)elem[i])->u2_name_and_type_index);
				break;
			case CONSTANT_InterfaceMethodref:
				return get_ref_method(((cp_InterfaceMethodref *)elem[i])->u2_name_and_type_index);
				break;
			case CONSTANT_String:
				break;
			case CONSTANT_Integer:
				break;
			case CONSTANT_Float:
				break;
			case CONSTANT_Long:
				break;
			case CONSTANT_Double:
				break;
			case CONSTANT_NameAndType:
				return get_ref_method(((cp_NameAndType *)elem[i])->u2_name_index);
				break;
			case CONSTANT_Utf8:
				return ((cp_Utf8 *)elem[i])->u1_bytes_array;
				break;
			case CONSTANT_MethodHandle:
				break;
			case CONSTANT_MethodType:
				break;
			case CONSTANT_InvokeDynamic:
				break;
			default: std::cerr << "Unrecognized constant pool tag.\n";
				break;
		}
	}

	std::string lookup(const unsigned int & i){
		std::stringstream str;
		lookup(i, str);
		return str.str();
	}

	/**
	 * Get an element from the constant pool.
	 */
	ConstantPoolElement * get_cpe(const unsigned int & i){
		return elem[i-1];
	}

	void link(std::function<ClassFile*(std::string)> get_class){
		
	}

	void print(){
		for(int i = 1; i <= elem.size(); i++){
			if(i<10) 		printf("   ");
			else if(i<100)  printf("  ");
			else if(i<1000) printf(" ");
			printf("#%u = %-20s", i, constant_types_tt[elem[i-1]->get_tag()].c_str());
			
			
			get_cpe(i)->print();
			if(get_cpe(i)->get_tag() != CONSTANT_Utf8) printf(" // ");
			printf("%s", lookup(i).c_str());
			
			printf("\n");
		}
	}
};


#endif
