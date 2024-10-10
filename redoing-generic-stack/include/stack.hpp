
typedef struct{
	void *elems;
	int elemSize;
	int allocatedLen;
	int logicalLen;
	void (*freefn)(void*);

}stack;

void StringFree(void *elem);
void StackNew(stack *s, int elemSize, void (*freefn)(void*)); 
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);
void StackDispose(stack *s);
