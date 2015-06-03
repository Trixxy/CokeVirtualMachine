#ifndef _VM_RUN_TIME_ENVIRONMENT_H_
#define _VM_RUN_TIME_ENVIRONMENT_H_

#include <cstdio>
#include <map>
#include <string>
#include "ClassFile.h"
#include "Heap.h"

/***************************************************************//**
 * \brief The RunTimeEnvironment class keeps track of all loaded classes,
 * it works by loading each ClassFile via add_class(), but
 * NOTE that it can not be used until all classes are loaded.
 *
 * The RunTimeEnvironment do also have a Heap on which it allocates
 * objects (and class variables).
 ******************************************************************/
class RunTimeEnvironment {
    std::map<std::string, ClassFile *> class_pool;
    Heap object_heap;
    std::function<ClassFile*(std::string)> rte_lookup;
    std::function<unsigned int(ObjectRef*)> heap_push;

public:
    RunTimeEnvironment():class_pool(std::map<std::string, ClassFile *>()), object_heap(Heap()),
        rte_lookup([&](std::string cn){ return get_class(cn); }),
        heap_push([&](ObjectRef * obj){ return object_heap.push(obj); }){}

    /**
     * Adds class to RunTimeEnvironment.
     */
    void add_class(ClassFile * cf){
        cf->set_heap(heap_push);
        if(class_pool.find(cf->get_class_name()) == class_pool.end()){
            class_pool[cf->get_class_name()] = cf;
        }else{
            fprintf(stderr, "Error: Class name already in pool: %s\n", cf->get_class_name().c_str());
        }
    }

    void link(){
        for(auto c : class_pool){
            c.second->link(rte_lookup);
        }
    }

    ClassFile * get_class(std::string cn){
        return class_pool[cn];
    }

    ObjectRef * get_object(const unsigned int & i){
    	return object_heap.get(i);
    }

    void print_all_classes(){
        for(auto c : class_pool){
            c.second->print();
        }
    }
};

#endif 
