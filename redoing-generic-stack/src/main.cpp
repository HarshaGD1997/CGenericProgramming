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
	s->freefn = freefn;

}


void StackDispose(stack *s){

	if(s->freefn != NULL){
		for(int i=0; i<s->logicalLen; i++){
			s->freefn((char*) s->elems + i*s->elemSize);
		}
	}


	free(s->elems);
	s->elems = NULL;
}

void StringFree(void * elem){
	if(*(char**)elem != NULL){
		free(*(char**) elem);
	
		*(char**)elem = NULL;
	}
}


void StackPush(stack *s, void *elemAddr){
	if(s->logicalLen == s->allocatedLen){
		s->allocatedLen *= 2;
		s->elems = realloc(s->elems, s->allocatedLen * s->elemSize);
		assert(s->elems != NULL);
	}

	void *target = (char*)s->elems + s->logicalLen * s->elemSize;
	memcpy(target, elemAddr, s->elemSize);
	s->logicalLen++;
}

void StackPop(stack *s, void *elemAddr){
	assert(s->logicalLen > 0);

	s->logicalLen--;
	void *source = (char*)s->elems + s->logicalLen * s->elemSize;
	memcpy(elemAddr, source, s->elemSize);


	/*if(s->freefn != NULL){
		s->freefn(source);
	}*/

}

int main(int argc, char **argv){
	
	stack stringStack;
	StackNew(&stringStack, sizeof(char*), StringFree);

	const char *names[] = {"alice", "bob", "charlie"};
	for(int i=0; i<3; i++){
		char *copy = strdup(names[i]);
		StackPush(&stringStack, &copy);
	}

	for(int i=0; i<3; i++){
		char *name;
		StackPop(&stringStack, &name);
		std::cout << "name :" << name <<std::endl;
		free(name);
	}

	StackDispose(&stringStack);

	return 0;
}
