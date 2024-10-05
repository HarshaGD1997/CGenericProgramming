#include <iostream>
#include <cassert>
#include "stack.hpp"

void StackNew(stack *s){
	s->logicalLen = 0;
	s->allocatedLen = 4;
	s->elems = (int*)malloc(4*sizeof(int));
	assert(s->elems != NULL);
}

void StackDispose(stack *s){
	free(s->elems);
	
}

void StackPush(stack *s, int value){
	
	if(s->logicalLen == s->allocatedLen){
		s->allocatedLen *= 2;
		s->elems = (int*)realloc(s->elems, s->allocatedLen*sizeof(int));
		assert(s->elems != NULL);	
	}

	s->elems[s->logicalLen] = value;
	s->logicalLen++;

}

int StackPop(stack *s){
	
	assert(s->logicalLen > 0);
	s->logicalLen--;
	return s->elems[s->logicalLen];
	
	
}

int main(int argc, char **argv){
	
	stack s;
	StackNew(&s);
	StackPush(&s, 10);
	StackPush(&s, 20);
	int popRes = StackPop(&s);
	std::cout << "Element : " << popRes <<std::endl;
	StackDispose(&s);	
	return 0;
}
