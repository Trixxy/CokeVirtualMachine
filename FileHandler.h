#ifndef _VM_CODE_HANDLER_H_
#define _VM_CODE_HANDLER_H_

#include "DefConstTrans.h"
#include <string>
#include <vector>
#include <cstdio>

class FileHandler{
	std::vector<byte> code;
	unsigned int cc; //code counter

public:
	FileHandler():code(std::vector<byte>()), cc(0){}
	FileHandler(const std::string & file_path):code(std::vector<byte>()), cc(0){
		feed_from_file(file_path);
	}

	unsigned int size() const {
		return code.size();
	} 
	unsigned int get_cc() const {
		return cc;
	}

	byte & operator[](const unsigned int & i){
		if(i >= code.size()){
			fprintf(stderr, "Error: Accessing byte out of bound.\n");
		}

		return code[i];
	}

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

	inline void feed(const byte & b){
		code.push_back(b);
	}

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
