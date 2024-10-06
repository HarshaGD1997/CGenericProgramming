

typedef struct{
	void *elems;
	int elemSize;
	int logicalLen;
	int allocatedLen;

}stack;

void StackNew(stack *s, int elemSize);
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAdd);
void StackPop(stack *s, void *elemAdd);
