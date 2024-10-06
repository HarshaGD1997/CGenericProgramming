#include <iostream>
#include <cassert>
#include <cstring>
#include "stack.hpp"

void StackNew(stack *s, int elemSize){
	assert(elemSize > 0);
	s->elemSize = elemSize;
	s->logicalLen = 0;
	s->allocatedLen = 4;
	s->elems = malloc(4*elemSize);
	assert(s->elems != NULL);

}

void StackDispose(stack *s){

	free(s->elems);
}

static void StackGrow(stack *s){
	s->allocatedLen *= 2;
	s->elems = realloc(s->elems, s->allocatedLen * s->elemSize);
}

void StackPush(stack *s, void *elemAdd){
	if(s->logicalLen == s->allocatedLen){
		StackGrow(s); 
	}

	void *target = (char*) s->elems + s->logicalLen * s->elemSize;
	memcpy(target, elemAdd, s->elemSize);
	s->logicalLen++;

}

void StackPop(stack *s, void *elemAdd){
	void *src = (char*) s->elems + (s->logicalLen - 1) * s->elemSize;
	memcpy(elemAdd, src, s->elemSize);
	s->logicalLen--;
}

int main(int argc, char **argv){
	
	int top;
	int p1 = 4, p2 = 3;
	stack s;
	StackNew(&s, sizeof(int));
	StackPush(&s, &p1);
	StackPush(&s, &p2);
	StackPop(&s, &top);
	std::cout << "popped elem : " << top << std::endl;
	StackPop(&s, &top);
	std::cout << "popped elem : " << top << std::endl;
	StackDispose(&s);

	return 0;
}
