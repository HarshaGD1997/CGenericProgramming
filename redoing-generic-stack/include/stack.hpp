
typedef struct{
	void *elem;
	int elemSize;
	int allocatedLen;
	int logicalLen;
	void (*freefn)(void*);

}stack;

void StackNew(stack *s, int elemSize, void (*freefn)(void*)); 
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);
void StackDispose(stack *s);
