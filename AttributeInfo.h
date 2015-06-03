#ifndef _VM_ATTRIBUTE_INFO_H_
#define _VM_ATTRIBUTE_INFO_H_

#include <string>
#include <functional>
#include <map>
#include "AttributeContainer.h"

class ConstantPool; //forward-reference

/**
 * \brief The AttributeInfo class contains the info related to an attribute in a classfile,
 * the format is according to the JVM specification.
 */
class AttributeInfo{
	unsigned int u2_attribute_name_index;

	AttributeContainer * attr_data;
	ConstantPool * cp;

public:
	AttributeInfo(){}
	AttributeInfo(std::function<unsigned int(ClassUnit)> fh_fetch, ConstantPool * _cp):cp(_cp){
		u2_attribute_name_index = fh_fetch(U2);

		std::string attribute_type = cp->lookup(u2_attribute_name_index);
			 if("ConstantValue"							 == attribute_type){ attr_data = new ac_ConstantValue(fh_fetch); }
		else if("Code"									 == attribute_type){ attr_data = new ac_Code(fh_fetch); }
		else if("StackMapTable"							 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_StackMapTable); }
		else if("Exceptions"							 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_Exceptions); }
		else if("InnerClasses"							 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_InnerClasses); }
		else if("EnclosingMethod"						 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_EnclosingMethod); }
		else if("Synthetic"								 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_Synthetic); }
		else if("Signature"								 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_Signature); }
		else if("SourceFile"							 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_SourceFile); }
		else if("SourceDebugExtension"					 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_SourceDebugExtension); }
		else if("LineNumberTable"						 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_LineNumberTable); }
		else if("LocalVariableTable"					 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_LocalVariableTable); }
		else if("LocalVariableTypeTable"				 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_LocalVariableTypeTable); }
		else if("Deprecated"							 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_Deprecated); }
		else if("RuntimeVisibleAnnotations"				 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_RuntimeVisibleAnnotations); }
		else if("RuntimeInvisibleAnnotations"			 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_RuntimeInvisibleAnnotations); }
		else if("RuntimeVisibleParameterAnnotations"	 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_RuntimeVisibleParameterAnnotations); }
		else if("RuntimeInvisibleParameterAnnotations"	 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_RuntimeInvisibleParameterAnnotations); }
		else if("AnnotationDefault"						 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_AnnotationDefault); }
		else if("BootstrapMethods"						 == attribute_type){ attr_data = new ac_UnImplemented(fh_fetch, ATTRIBUTE_BootstrapMethods); }
		else 															   { attr_data = new ac_UnRecognized(fh_fetch, attribute_type); }
	}

	std::string get_attribute_name() {
		return cp->lookup(u2_attribute_name_index);
	}

	AttributeTypes get_type(){
		return attr_data->get_type();
	}

	AttributeContainer * get_container(){
		return attr_data;
	}

	void print() {
		 attr_data->print();
	}
};


#endif
//_VM_ATTRIBUTE_INFO_H_
