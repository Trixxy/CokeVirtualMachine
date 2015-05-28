#ifndef _VM_OBJECT_REF_H_
#define _VM_OBJECT_REF_H_

#include <vector>
#include <map>

class ConstantPool; //forward-reference

class ObjectRef{
	friend class ClassFile;
	std::map<std::string, unsigned int> finder;

	ConstantPool * cp;
	std::vector<void *> fields;
public:
	ObjectRef(ConstantPool * _cp): finder(std::map<std::string, unsigned int>()), cp(_cp), fields(std::vector<void *>()){}
	// field[i]
	// return (cp.getFieldType(i))fields[i]

	void * ref_by_name(const std::string & name){
		return fields[finder[name]];
	}
};

#endif
