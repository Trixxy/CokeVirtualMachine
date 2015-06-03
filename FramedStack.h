#ifndef _VM_FRAMED_STACK_H_
#define _VM_FRAMED_STACK_H_

#include <deque>
#include <cstdio>

/**
 * \brief A FramedStack is simply a stack with support to push and pop frames.
 *
 * When a frame is pushed, the stacks current state is saved (on the stack)
 * and when a frame is poped, the previous state is restored (from the stack).
 *
 * This stack is hardcoded to operate on 32-bit words.
 */
class FramedStack {
	std::deque<unsigned int> * instack;
    unsigned int fp, fc, lc;

public:
    FramedStack():instack(new std::deque<unsigned int>()), fp(0), fc(0), lc(0){}

    /**
     * Pushes a (32-bit) word to the stack.
     */
    void push(const unsigned int & word) {
        if(fc == 0) fprintf(stderr, "Error: Push to stack with no frames\n");
        instack->push_back(word);
    }

    /**
     * Pops a (32-bit) word from the stack and returns it.
     */
    unsigned int pop() {
        if(instack->size() == (fp+lc)) fprintf(stderr, "Error: Pop from empty stack\n");
		
        unsigned int elem = instack->back();
        instack->pop_back();
		
        return elem;
    }

    /**
     * Pushes a frame to the stack, takes an offset in order to reserve place for the local variables.
     */
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

    /**
     * Pops a frame and restores the stack to the previous frames state.
     */
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

    /**
     * Index operator to access the current frame,
     * handy to access local variables.
     */
    unsigned int & operator[](const unsigned int & i) {
    	return instack->at(i+fp);
    }

    /**
     * Prints the whole stack.
     * Used for debugging & trace printouts.
     */
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
