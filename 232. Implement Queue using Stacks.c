typedef struct Queue stack;
typedef struct Queue MyQueue;

struct Queue
{
	int val;
	MyQueue *next;
};

int pop(stack *myStack)
{
	stack *node = myStack->next;
	myStack->next = node->next;
	int key = node->val;
	free(node);
	return key;
}
void push(stack *myStack, int key)
{
	stack *node = malloc(sizeof(stack));
	node->val = key;
	node->next = myStack->next;
	myStack->next = node;
}

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
	MyQueue *queue = malloc(sizeof(MyQueue));
	queue->next = NULL;
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stack *assist = malloc(sizeof(stack));
	assist->next = NULL;
	int key;
	MyQueue *node = obj->next;
	while (node != NULL)
	{
		node = node->next;
		key = pop(obj);
		push(assist, key);
	}
	push(obj, x);
	node = assist->next;
	while (node != NULL)
	{
		node = node->next;
		key = pop(assist);
		push(obj, key);
	}
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	return pop(obj);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	return obj->next->val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return obj->next == NULL;
}

void myQueueFree(MyQueue* obj) {
	int key;
	MyQueue *node = obj->next;
	while (node != NULL)
	{
		node = node->next;
		key = pop(obj);
	}
	free(obj);
}