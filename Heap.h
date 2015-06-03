#ifndef _VM_HEAP_H_
#define _VM_HEAP_H_

#include <vector>
#include "ObjectRef.h"

/**
 * \brief The Heap class contains a chunk of memory on which object can be stored.
 *
 * Currently, it is just a wrapper for a vector of ObjectRef.
 */
class Heap{
	std::vector<ObjectRef *> memory;
public:
	Heap():memory(std::vector<ObjectRef *>()){};

	/**
	 * Allocates memory for the object, and return address to access it later.
	 */
	unsigned int push(ObjectRef * obj){
		memory.push_back(obj);
		return memory.size()-1;
	}

	/**
	 * Returns object at the specified address.
	 */
	ObjectRef * get(const unsigned int & i){
		return memory[i];
	}

};

#endif
