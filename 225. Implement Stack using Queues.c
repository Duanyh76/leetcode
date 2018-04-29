typedef struct Stack MyStack;
typedef struct Stack queue;

struct Stack{
	int val;
	MyStack *next;
};

void enqueue(queue *myQueue, int x)
{
	queue *addNode = malloc(sizeof(queue));
	addNode->val = x;
	addNode->next = NULL;
	queue *node = myQueue;
	while (node->next != NULL)
		node = node->next;
	node->next = addNode;
}
int dequeue(queue *myQueue)
{
	queue *node = myQueue->next;
	myQueue->next = node->next;
	int key = node->val;
	free(node);
	return key;
}

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	MyStack *stack = malloc(sizeof(MyStack));
	stack->next = NULL;
	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	enqueue(obj, x);
	MyStack *node = obj->next;
	int count = -1;
	while (node != NULL)
	{
		node = node->next;
		count++;
	}
	int key;
	for (int i = 0; i < count; i++)
	{
		key = dequeue(obj);
		enqueue(obj, key);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	return dequeue(obj);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return obj->next == NULL;
}

void myStackFree(MyStack* obj) {
	MyStack *node = obj->next;
	int key;
	while (node != NULL)
	{
		node = node->next;
		key = dequeue(obj);
	}
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* struct MyStack* obj = myStackCreate(maxSize);
* myStackPush(obj, x);
* int param_2 = myStackPop(obj);
* int param_3 = myStackTop(obj);
* bool param_4 = myStackEmpty(obj);
* myStackFree(obj);
*/