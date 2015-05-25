#ifndef _VM_FRAMED_STACK_H_
#define _VM_FRAMED_STACK_H_

#include <deque>

class FramedStack : protected std::deque<unsigned int> {
#define super std::deque<unsigned int>
    unsigned int sp, fp, fc, cfo;

public:
    FramedStack():std::deque<unsigned int>(), sp(0), fp(0), fc(0), cfo(0){}

    void push(const unsigned int & word) {
        if(fc == 0) fprintf(stderr, "Error: Push to stack with no frames\n");
        else ++sp;
		
        super::push_back(word);
    }

    unsigned int pop() {
        if(sp == (fp+cfo)) fprintf(stderr, "Error: Pop from empty stack\n");
        else --sp;
		
        unsigned int elem = super::back();
        super::pop_back();
		
        return elem;
    }

    void push_frame(unsigned int offset) {
        push_back(sp);
        push_back(fp);
        push_back(cfo);

        fp = size();
        cfo = offset;
        while(offset--) {
            push_back(0);
        }

        sp = size();
        ++fc;
    }

    void pop_frame() {
        if(sp != (fp+cfo)) fprintf(stderr, "Error: Pop frame: non empty stack...\n");
        if(fc == 0) fprintf(stderr, "Error: Pop frame, but me no have one...\n");
        for(int i = cfo ; i-- ;) {
            pop_back();
        }

        cfo = back(); pop_back();
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
