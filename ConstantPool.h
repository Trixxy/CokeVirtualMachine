#ifndef _VM_CONSTANT_POOL_H_
#define _VM_CONSTANT_POOL_H_

#include <sstream>
#include "DefConstTrans.h"
#include "CodeHandler.h"
#include "ConstantPoolElement.h"

class ConstantPool{
	std::vector<ConstantPoolElement*> elem;
	CodeHandler * coke;
public:
	ConstantPool(){}
	ConstantPool(CodeHandler * _coke):elem(std::vector<ConstantPoolElement*>()), coke(_coke){}
	~ConstantPool(){
		for(int i = 0; i < elem.size(); i++) delete elem[i];
	}

	void push_back(const unsigned int & tag){
		switch(tag){
			case CONSTANT_Class: elem.push_back(new cp_Class(*coke)); break;
			case CONSTANT_Fieldref: elem.push_back(new cp_Fieldref(*coke)); break;
			case CONSTANT_Methodref: elem.push_back(new cp_Methodref(*coke)); break;
			case CONSTANT_InterfaceMethodref: elem.push_back(new cp_InterfaceMethodref(*coke)); break;
			case CONSTANT_String: elem.push_back(new cp_String(*coke)); break;
			case CONSTANT_Integer: elem.push_back(new cp_Integer(*coke)); break;
			case CONSTANT_Float: elem.push_back(new cp_Float(*coke)); break;
			case CONSTANT_Long: elem.push_back(new cp_Long(*coke)); break;
			case CONSTANT_Double: elem.push_back(new cp_Double(*coke)); break;
			case CONSTANT_NameAndType: elem.push_back(new cp_NameAndType(*coke)); break;
			case CONSTANT_Utf8: elem.push_back(new cp_Utf8(*coke)); break;
			case CONSTANT_MethodHandle: elem.push_back(new cp_MethodHandle(*coke)); break;
			case CONSTANT_MethodType: elem.push_back(new cp_MethodType(*coke)); break;
			case CONSTANT_InvokeDynamic: elem.push_back(new cp_InvokeDynamic(*coke)); break;	
			default: std::cerr << "Unrecognized constant pool tag.\n";
		}
	}

	void lookup(const unsigned int & i){
		switch(elem[i]->get_tag()){
			case CONSTANT_Class: 
				lookup(((cp_Class *)elem[i])->u2_name_index-1);
				break;
			case CONSTANT_Fieldref: 
				lookup(((cp_Fieldref *)elem[i])->u2_class_index-1);
				printf(".");
				lookup(((cp_Fieldref *)elem[i])->u2_name_and_type_index-1);
				break;
			case CONSTANT_Methodref: 
				lookup(((cp_Methodref *)elem[i])->u2_class_index-1);
				printf(".");
				lookup(((cp_Methodref *)elem[i])->u2_name_and_type_index-1);
				break;
			case CONSTANT_InterfaceMethodref: 
				lookup(((cp_InterfaceMethodref *)elem[i])->u2_class_index-1);
				printf("??");
				lookup(((cp_InterfaceMethodref *)elem[i])->u2_name_and_type_index-1);
				break;
			case CONSTANT_String: 
				lookup(((cp_String *)elem[i])->u2_string_index-1);
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
				lookup(((cp_NameAndType *)elem[i])->u2_name_index-1);
				printf(":");
				lookup(((cp_NameAndType *)elem[i])->u2_descriptor_index-1);
				break;
			case CONSTANT_Utf8: 
				printf("%s", ((cp_Utf8 *)elem[i])->u1_bytes_array.c_str());
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

	void print(){
		for(int i = 1; i <= elem.size(); i++){
			if(i<10) 		printf("   ");
			else if(i<100)  printf("  ");
			else if(i<1000) printf(" ");
			printf("#%u = %-20s", i, constant_types_tt[elem[i-1]->get_tag()].c_str());
			//elem[i-1]->print();
			lookup(i-1);
			printf("\n");
		}
	}
};


#endif
