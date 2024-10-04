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

}

int main(int argc, char **argv){
	
	stack s;
	StackNew(&s);
	StackDispose(&s);	
	return 0;
}
