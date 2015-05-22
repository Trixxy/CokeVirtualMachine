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
			
			printf("#%u = %-20s", i, constant_types_tt[current_const].c_str());
			switch(current_const){
case CONSTANT_Class:
	// u2 name_index;
	printf("#%u", coke.fetch(U2));
	
	printf(" //name_index");
	break;
case CONSTANT_Fieldref:
	// u2 class_index;
	printf("#%u", coke.fetch(U2));
	// u2 name_and_type_index;
	printf(".#%u", coke.fetch(U2));
	
	printf(" //class_index.name_and_type_index");
	break;
case CONSTANT_Methodref:
	// u2 class_index;
	printf("#%u", coke.fetch(U2));
	// u2 name_and_type_index;
	printf(".#%u", coke.fetch(U2));

	printf(" //class_index.name_and_type_index");
	break;
case CONSTANT_InterfaceMethodref:
	// u2 class_index;
	printf("#%u", coke.fetch(U2));
	// u2 name_and_type_index;
	printf(", #%u", coke.fetch(U2));

	printf(" //TOTO(class_index, name_and_type_index)");
	break;
case CONSTANT_String:
	// u2 string_index;
	printf("#%u", coke.fetch(U2));

	printf(" //string_index");
	break;
case CONSTANT_Integer:
	// u4 bytes;
	printf("%u", coke.fetch(U4));
	
	printf(" //bytes");
	break;
case CONSTANT_Float:
	// u4 bytes;
	printf("%u", coke.fetch(U4));

	printf(" //bytes");
	break;
case CONSTANT_Long:
	// u4 high_bytes;
	printf("%u", coke.fetch(U4));
	// u4 low_bytes;
	printf("<<32|%u", coke.fetch(U4));

	printf(" //high_bytes, low_bytes");
	break;
case CONSTANT_Double:
	// u4 high_bytes;
	printf("%u", coke.fetch(U4));
	// u4 low_bytes;
	printf("<<32|%u", coke.fetch(U4));
	
	printf(" //high_bytes, low_bytes");
	break;
case CONSTANT_NameAndType:
	// u2 name_index;
	printf("#%u", coke.fetch(U2));
	// u2 descriptor_index;
	printf(":#%u", coke.fetch(U2));

	printf(" //name_index, descriptor_index");
	break;
case CONSTANT_Utf8:
	// u2 length;
	// u1 bytes[length];
	printf("\"");
	for(int utf8_len = coke.fetch(U2); utf8_len > 0; utf8_len--)
		printf("%c", coke.fetch(U1));
	
	printf("\" //Utf8()");
	break;
case CONSTANT_MethodHandle:
	// u1 reference_kind;
	printf("%u", coke.fetch(U1));
	// u2 reference_index;
	printf(", #%u", coke.fetch(U2));

	printf(" //TOTO(reference_kind, reference_index)");
	break;
case CONSTANT_MethodType:
	// u2 descriptor_index;
	printf("#%u", coke.fetch(U2));

	printf(" //TOTO(descriptor_index)");
	break;
case CONSTANT_InvokeDynamic:
	// u2 bootstrap_method_attr_index;
	printf("#%u", coke.fetch(U2));
	// u2 name_and_type_index;
	printf(", #%u", coke.fetch(U2));

	printf(" //TOTO(bootstrap_method_attr_index, name_and_type_index)");
	break;	
				default:
					std::cerr << "Unrecognized constant pool tag.\n";
			}
			printf("\n");
		}
	}
};


#endif
