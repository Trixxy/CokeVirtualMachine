#ifndef _VM_FRAMED_STACK_H_
#define _VM_FRAMED_STACK_H_

#include <deque>

class FramedStack : protected std::deque<unsigned int> {
	#define super std::deque<unsigned int>
	unsigned int sp, fp, fc;

public:
	FramedStack():std::deque<unsigned int>(), sp(0), fp(0), fc(0){}

	void push(const unsigned int & word) {
		if(fc == 0) fprintf(stderr, "Error: Push to stack with no frames\n");
		else ++sp;
		
		super::push_back(word);
	}

	unsigned int pop() {
		if(sp == size()) fprintf(stderr, "Error: Pop from empty stack\n");
		else --sp;
		
		unsigned int elem = super::back();
		super::pop_back();
		
		return elem;
	}

	void push_frame(unsigned int offset) {
		push(sp);
		push(fp);

		fp = size();
		while(offset--) {
			push(0);
		}

		sp = size();
		++fc;
	}

	void pop_frame() {
		if(sp != size()) fprintf(stderr, "Error: Pop frame: non empty stack...\n");
		if(fc == 0) fprintf(stderr, "Error: Pop frame, but me no have one...\n");
		for(int i = (sp-fp) ; i-- ;) {
			pop_back();
		}

		fp = back(); pop_back();
		sp = back(); pop_back();
		--fc;
	}

	unsigned int & operator[](const unsigned int & i) {
		return super::operator[](i+fp);
	}

	#undef super
};

#endif 