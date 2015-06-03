#ifndef _VM_OBJECT_REF_H_
#define _VM_OBJECT_REF_H_

#include <vector>
#include <map>

class ConstantPool; //forward-reference

/**
 * \brief The ObjectRef class is a heap element to represent an object,
 * an object simply contains the values of fields.
 */
class ObjectRef{
	friend class ClassFile;
	std::map<std::string, unsigned int> finder;

	ConstantPool * cp;
	std::vector<void *> fields;
public:
	/**
	 * Initializes an ObjectRef with a ConstantPool pointer, currently not used,
	 * but will be in the future to support type checking, etc.
	 */
	ObjectRef(ConstantPool * _cp): finder(std::map<std::string, unsigned int>()), cp(_cp), fields(std::vector<void *>()){}
	// field[i]
	// return (cp.getFieldType(i))fields[i]

	/**
	 * Returns a field by name as void pointer, since no type checking is done a.t.m.
	 * it is up for the user to check the correctness of types, etc.
	 */
	void * ref_by_name(const std::string & name){
		return fields[finder[name]];
	}
};

#endif
