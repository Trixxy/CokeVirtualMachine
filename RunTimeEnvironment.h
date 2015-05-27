#ifndef _VM_RUN_TIME_ENVIRONMENT_H_
#define _VM_RUN_TIME_ENVIRONMENT_H_

#include <cstdio>
#include <map>
#include <string>
#include "ClassFile.h"

class RunTimeEnvironment {
    std::map<std::string, ClassFile *> class_pool;
    std::function<ClassFile*(std::string)> rte_lookup;

public:
    RunTimeEnvironment():class_pool(std::map<std::string, ClassFile *>()), rte_lookup([&](std::string cn){ return get_class(cn); }){}
    void add_class(ClassFile * cf){
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
};

#endif 
