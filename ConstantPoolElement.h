#ifndef _CONSTANT_POOL_ELEMENT_TYPES_H_
#define _CONSTANT_POOL_ELEMENT_TYPES_H_

#include <functional>
#include <sstream>
#include <string>

/**
 * \brief The ConstantPoolElement class is an abstract
 * class that represents a constant pool element.
 */
struct ConstantPoolElement {
	virtual unsigned int get_tag() = 0;
	virtual void print() = 0;
protected:
	ConstantPoolElement(){}
};

/**
 * \brief The cp_Class class represents a class element in the constant
 * pool.
 */
struct cp_Class: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Class;
	unsigned int u2_name_index; //1
	cp_Class(std::function<unsigned int(ClassUnit)> fh_fetch):u2_name_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){		
		printf("#%u", u2_name_index);
//		printf(" //u2_name_index");
	};
};

/**
 * \brief The cp_Fieldref class represents a field reference element in the 
 * constant pool.
 */
struct cp_Fieldref: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Fieldref;
	unsigned int u2_class_index; //1
	unsigned int u2_name_and_type_index; //2
	cp_Fieldref(std::function<unsigned int(ClassUnit)> fh_fetch):u2_class_index(fh_fetch(U2)), u2_name_and_type_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){		
		printf("#%u.#%u", u2_class_index, u2_name_and_type_index);
//		printf(" //class_index.name_and_type_index");
	};
};

/**
 * \brief The cp_Methodref class represents a method reference element in the 
 * constant pool.
 */
struct cp_Methodref: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Methodref;
	unsigned int u2_class_index; //1
	unsigned int u2_name_and_type_index; //2
	cp_Methodref(std::function<unsigned int(ClassUnit)> fh_fetch):u2_class_index(fh_fetch(U2)), u2_name_and_type_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){		
		printf("#%u.#%u", u2_class_index, u2_name_and_type_index);
//		printf(" //class_index.name_and_type_index");
	};
};

/**
 * \brief The cp_InterfaceMethodref class represents an interface method reference 
 * element in the constant pool.
 */
struct cp_InterfaceMethodref: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_InterfaceMethodref;
	unsigned int u2_class_index;
	unsigned int u2_name_and_type_index;
	cp_InterfaceMethodref(std::function<unsigned int(ClassUnit)> fh_fetch):u2_class_index(fh_fetch(U2)),u2_name_and_type_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){		
		printf("#%u, #%u", u2_class_index, u2_name_and_type_index);
//		printf(" //TOTO(class_index, name_and_type_index)");
	};
};

/**
 * \brief The cp_String class represents a string element in the
 * constant pool.
 */
struct cp_String: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_String;
	unsigned int u2_string_index; //1
	cp_String(std::function<unsigned int(ClassUnit)> fh_fetch):u2_string_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){		
		printf("#%u", u2_string_index);
//		printf(" //string_index");
	};
};

/**
 * \brief The cp_Integer class represents an integer element in the
 * constant pool.
 */
struct cp_Integer: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Integer;
	unsigned int u4_bytes; //1
	cp_Integer(std::function<unsigned int(ClassUnit)> fh_fetch):u4_bytes(fh_fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("%u", u4_bytes);
//		printf(" //bytes", u4_bytes);
	};
};

/**
 * \brief The cp_Float class represents a float element in the
 * constant pool.
 */
struct cp_Float: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Float;
	unsigned int u4_bytes; //1
	cp_Float(std::function<unsigned int(ClassUnit)> fh_fetch):u4_bytes(fh_fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("%u", u4_bytes);
//		printf(" //bytes");
	};
};

/**
 * \brief The cp_Long class represents a long element in the
 * constant pool.
 */
struct cp_Long: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Long;
	unsigned int u4_high_bytes; //1
	unsigned int u4_low_bytes; //2
	cp_Long(std::function<unsigned int(ClassUnit)> fh_fetch):u4_high_bytes(fh_fetch(U4)), u4_low_bytes(fh_fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("%u<<32|%u", u4_high_bytes, u4_low_bytes);
//		printf(" //high_bytes, low_bytes");
	};
};

/**
 * \brief The cp_Double class represents a double element in the
 * constant pool.
 */
struct cp_Double: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Double;
	unsigned int u4_high_bytes; //1
	unsigned int u4_low_bytes; //2
	cp_Double(std::function<unsigned int(ClassUnit)> fh_fetch):u4_high_bytes(fh_fetch(U4)), u4_low_bytes(fh_fetch(U4)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("%u<<32|%u", u4_high_bytes, u4_low_bytes);
//		printf(" //high_bytes, low_bytes");
	};
};

/**
 * \brief The cp_NameAndType class represents a name and
 * type element in the constant pool.
 */
struct cp_NameAndType: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_NameAndType;
	unsigned int u2_name_index; //1
	unsigned int u2_descriptor_index; //2
	cp_NameAndType(std::function<unsigned int(ClassUnit)> fh_fetch):u2_name_index(fh_fetch(U2)), u2_descriptor_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("#%u:#%u", u2_name_index, u2_descriptor_index);
//		printf(" //name_index, descriptor_index");
	};
};

/**
 * \brief The cp_Utf8 class represents an utf8 character in the
 * constant pool.
 */
struct cp_Utf8: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_Utf8;
	std::string u1_bytes_array; //2 u1_bytes[length]
	cp_Utf8(std::function<unsigned int(ClassUnit)> fh_fetch){
		unsigned int u2_length = fh_fetch(U2);
		std::stringstream ss;
		for(int i = 0; i < u2_length; i++)
			ss << (char)fh_fetch(U1);
		u1_bytes_array = ss.str();
	}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
//		printf("\"%s\"", u1_bytes_array.c_str());
	};
};

/**
 * \brief The cp_MethodHandle class represents an method handle
 * element in the constant pool.
 */
struct cp_MethodHandle: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_MethodHandle;
	unsigned int u1_reference_kind; //1
	unsigned int u2_reference_index; //2
	cp_MethodHandle(std::function<unsigned int(ClassUnit)> fh_fetch):u1_reference_kind(fh_fetch(U1)), u2_reference_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){
		printf("%u, #%u", u1_reference_kind, u2_reference_index);
//		printf(" //TOTO(reference_kind, reference_index)");
	};
};

/**
 * \brief The cp_MethodType class represents a method type in the
 * constant pool.
 */
struct cp_MethodType: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_MethodType;
	unsigned int u2_descriptor_index; //1
	cp_MethodType(std::function<unsigned int(ClassUnit)> fh_fetch):u2_descriptor_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){		
		printf("#%u", u2_descriptor_index);
//		printf(" //TOTO(descriptor_index)");
	};
};

/**
 * \brief The cp_InvokeDynamic class represents an invoke dynamic
 * element in the constant pool.
 */
struct cp_InvokeDynamic: public ConstantPoolElement {
	static const unsigned int tag = CONSTANT_InvokeDynamic;
	unsigned int u2_bootstrap_method_attr_index; //1
	unsigned int u2_name_and_type_index; //2
	cp_InvokeDynamic(std::function<unsigned int(ClassUnit)> fh_fetch):u2_bootstrap_method_attr_index(fh_fetch(U2)), u2_name_and_type_index(fh_fetch(U2)){}
	virtual unsigned int get_tag(){ return tag; };

	virtual void print(){		
		printf("#%u, #%u", u2_bootstrap_method_attr_index, u2_name_and_type_index);
//		printf(" //TOTO(bootstrap_method_attr_index, name_and_type_index)");
	};
};

#endif
//_CONSTANT_POOL_ELEMENT_TYPES_H_
