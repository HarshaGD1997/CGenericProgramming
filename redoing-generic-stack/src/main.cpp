#include <iostream>
#include <cstring>
#include <cassert>
#include "stack.hpp"

void StackNew(stack *s, int elemSize, void (*freefn)(void*)){
	assert(elemSize > 0);
	s->elemSize = elemSize;
	s->logicalLen = 0;
	s->allocatedLen = 4;
	s->elems = malloc(4*elemSize);
	assert(s->elems != NULL);
	freefn = StringFree;

}


void StackDispose(stack *s){

	if(s->freefn != NULL){
		for(int i=0; i<s->logicalLen; i++){
			s->freefn((char*) s->elems + i*s->elemSize);
		}
	}


	free(s->elems);
}

void StringFree(void * elem){
	free(*(char**) elem);
}

int main(int argc, char **argv){
	
	stack stringStack;
	StackNew(&stringStack, sizeof(char*), StringFree);

	return 0;
}
