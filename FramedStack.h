#ifndef _VM_FRAMED_STACK_H_
#define _VM_FRAMED_STACK_H_

#include <deque>
#include <cstdio>

class FramedStack {
	std::deque<unsigned int> * instack;
    unsigned int fp, fc, lc;

public:
    FramedStack():instack(new std::deque<unsigned int>()), fp(0), fc(0), lc(0){}

    void push(const unsigned int & word) {
        if(fc == 0) fprintf(stderr, "Error: Push to stack with no frames\n");
        instack->push_back(word);
    }

    unsigned int pop() {
        if(instack->size() == (fp+lc)) fprintf(stderr, "Error: Pop from empty stack\n");
		
        unsigned int elem = instack->back();
        instack->pop_back();
		
        return elem;
    }

    void push_frame(unsigned int offset) {
    	instack->push_back(fp);
    	instack->push_back(lc);

        fp = instack->size();
        lc = offset;
        while(offset--) {
        	instack->push_back(0);
        }

        ++fc;
    }

    void pop_frame() {
        if(instack->size() != (fp+lc)) fprintf(stderr, "Error: Pop frame: non empty stack...\n");
        if(fc == 0) fprintf(stderr, "Error: Pop frame, but me no have one...\n");
        for(int i = lc ; i-- ;) {
        	instack->pop_back();
        }

        lc = instack->back(); instack->pop_back();
        fp = instack->back(); instack->pop_back();
        --fc;
    }

    unsigned int & operator[](const unsigned int & i) {
    	return instack->at(i+fp);
    }

    void print(){
    	printf("[");
    	for(unsigned int i = 0; i < instack->size(); i++){
    		printf("%d", instack->operator[](i));
    		if(i+1 != instack->size()) printf(" | ");
    	}
    	printf("]\n");
    }

#undef super
};

#endif 
