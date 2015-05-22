#ifndef _VM_CONSTANT_POOL_H_
#define _VM_CONSTANT_POOL_H_

#include <sstream>
#include "DefConstTrans.h"
#include "CodeHandler.h"
#include "ConstantPoolElement.h"

class ConstantPool{
	std::vector<ConstantPoolElement> elem;
	CodeHandler * coke;
public:
	ConstantPool(){}
	ConstantPool(CodeHandler * _coke):elem(std::vector<ConstantPoolElement>()), coke(_coke){}

	void push_back(const unsigned int & tag){
		switch(tag){
			case CONSTANT_Class: elem.push_back(cp_Class(*coke)); break;
			case CONSTANT_Fieldref: elem.push_back(cp_Fieldref(*coke)); break;
			case CONSTANT_Methodref: elem.push_back(cp_Methodref(*coke)); break;
			case CONSTANT_InterfaceMethodref: elem.push_back(cp_InterfaceMethodref(*coke)); break;
			case CONSTANT_String: elem.push_back(cp_String(*coke)); break;
			case CONSTANT_Integer: elem.push_back(cp_Integer(*coke)); break;
			case CONSTANT_Float: elem.push_back(cp_Float(*coke)); break;
			case CONSTANT_Long: elem.push_back(cp_Long(*coke)); break;
			case CONSTANT_Double: elem.push_back(cp_Double(*coke)); break;
			case CONSTANT_NameAndType: elem.push_back(cp_NameAndType(*coke)); break;
			case CONSTANT_Utf8: elem.push_back(cp_Utf8(*coke)); break;
			case CONSTANT_MethodHandle: elem.push_back(cp_MethodHandle(*coke)); break;
			case CONSTANT_MethodType: elem.push_back(cp_MethodType(*coke)); break;
			case CONSTANT_InvokeDynamic: elem.push_back(cp_InvokeDynamic(*coke)); break;	
			default: std::cerr << "Unrecognized constant pool tag.\n";
		}
	}

	void print(){
		for(int i = 0; i < elem.size(); i++){
			if(i<10) 		printf("   ");
			else if(i<100)  printf("  ");
			else if(i<1000) printf(" ");
			elem[i].print();
			printf("\n");
		}
	}
};


#endif
