#ifndef _COKE_MACHINE_H_
#define _COKE_MACHINE_H_

#include <cstdio>
#include <string>
#include "ClassFile.h"
#include "CPU.h"
#include "RunTimeEnvironment.h"

/**
 * \brief This is the main class where everything starts.
 * It contains a RunTimeEnvironment, a CPU and pointer to
 * the main method where the CPU should start execution.
 */
class CokeMachine{
	CPU * cpu;
	RunTimeEnvironment * RTE;
	MethodInfo * main;

public:
	CokeMachine():cpu(new CPU()), RTE(new RunTimeEnvironment()), main(NULL){}
	~CokeMachine(){
		delete cpu;
		delete RTE;
	}

	/**
	 * Starts execution, prints out an error message if no main is set.
	 */
	void start(){
		if(main == NULL){
			fprintf(stderr, "Main is not set.\n");
			return;
		}
		cpu->set_environment(RTE);
		cpu->start(main);
	}

	/**
	 * Adds class to RunTimeEnvironment by name.
	 */
	void add_class(std::string class_file_name){
		auto current_class = new ClassFile(class_file_name);
		// current_class->print();
		if(main == NULL) main = current_class->get_method("main");
		RTE->add_class(current_class);
	}

};

#endif
