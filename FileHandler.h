#ifndef _VM_CODE_HANDLER_H_
#define _VM_CODE_HANDLER_H_

#include "DefConstTrans.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

/**
 * \brief The FileHandler class processes a file so it can be accessed one byte at a time.
 */
class FileHandler{
	std::vector<byte> code;
	unsigned int cc; //code counter

public:
	FileHandler():code(std::vector<byte>()), cc(0){}

	/**
	 * Initialize a FileHandler to read from file specified by given path.
	 */
	FileHandler(const std::string & file_path):code(std::vector<byte>()), cc(0){
		feed_from_file(file_path);
	}

	/**
	 * Returns size of file (in bytes).
	 */
	unsigned int size() const {
		return code.size();
	} 

	/**
	 * Returns the position of the next byte.
	 */
	unsigned int get_cc() const {
		return cc;
	}

	/**
	 * Returns byte at specified position.
	 */
	byte & operator[](const unsigned int & i){
		if(i >= code.size()){
			fprintf(stderr, "Error: Accessing byte out of bound.\n");
		}

		return code[i];
	}

	/**
	 * Returns next byte(s), number of bytes is specified by user as U1, U2 or U4,
	 * as specified in the JVM specification.
	 */
	unsigned int fetch(ClassUnit U = U1){
		if(cc > code.size()-U){
			std::cerr << "Error: Accessing byte out of bound." << std::endl;
		}

		unsigned int ret = 0;
		
		for(int i = 0; i < U; i++){
			ret = ret << 8;
			ret |= code[cc++];
		}

		return ret;
	}

	/**
	 * A FileHandler can be fed a stream of bytes to be interpreted
	 * as a file, one at a time.
	 */
	inline void feed(const byte & b){
		code.push_back(b);
	}

	/**
	 * A FileHandler can be initialized from file specified by path.
	 */
	void feed_from_file(const std::string & file_path){
		byte b;
		FILE * source_file = fopen(file_path.c_str(), "r");

		if(NULL == source_file){
			std::string err = "Error while loading '"+file_path+"'";
			perror(err.c_str());
		}

		while(fread(&b, sizeof(byte), 1, source_file)){
			feed(b);
		}
	}
};

#endif
//_VM_CODE_HANDLER_H_
