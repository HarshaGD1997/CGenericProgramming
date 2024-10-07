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
	std::cout << "Stack Grow helper function call " << std::endl;
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

	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = 'd', c5 = 'e';
	char cTop;
	stack s1;
	StackNew(&s1, sizeof(char));
	StackPush(&s1, &c1);
	StackPush(&s1, &c2);
	StackPop(&s1, &cTop);
       	std::cout << "popped elem : "<< cTop <<std::endl;
	StackPop(&s1, &cTop);
	std::cout << "popped elem : " << cTop <<std::endl;	
	StackPush(&s1, &c3);
	StackPush(&s1, &c4);
	StackPush(&s1, &c5);
	StackPop(&s1, &cTop);
	std::cout << "popped elem : "<< cTop <<std::endl;
	StackDispose(&s1);

	return 0;
}
