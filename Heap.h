#ifndef _VM_HEAP_H_
#define _VM_HEAP_H_

#include <vector>
#include "ObjectRef.h"

class Heap{
	std::vector<ObjectRef *> memory;
public:
	Heap():memory(std::vector<ObjectRef *>()){};
	unsigned int push(ObjectRef * obj){
		memory.push_back(obj);
		return memory.size()-1;
	}

	ObjectRef * get(const unsigned int & i){
		return memory[i];
	}

};

#endif
