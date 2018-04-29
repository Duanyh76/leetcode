typedef struct Stack MinStack;

struct Stack{
	int val;
	int minNum;
	MinStack *next;
};

int min(int a, int b)
{
    return a < b ? a : b;
}


/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
	MinStack *stack = malloc(sizeof(MinStack));
	stack->next = NULL;
	return stack;
}

void minStackPush(MinStack* obj, int x) {
	MinStack *node = malloc(sizeof(MinStack));
	node->val = x;
	//node->minNum = min(x, obj->next->minNum);
	if (obj->next != NULL)
		node->minNum = min(x, obj->next->minNum);
	else
		node->minNum = x;
	node->next = obj->next;
	obj->next = node;
}

void minStackPop(MinStack* obj) {
	MinStack *node = obj->next;
	obj->next = node->next;
	free(node);
}

int minStackTop(MinStack* obj) {
	return obj->next->val;
}

int minStackGetMin(MinStack* obj) {
	return obj->next->minNum;
}

void minStackFree(MinStack* obj) {
	if (obj == NULL)
		return;
	MinStack *node = obj;
	obj = obj->next;
	free(node);
	minStackFree(obj);
}