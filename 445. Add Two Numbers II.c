struct Stack
{
	int val;
	struct Stack *next;
};

void push(struct Stack *stack, int key)
{
	struct Stack *node = malloc(sizeof(struct Stack));
	node->val = key;
	node->next = stack->next;
	stack->next = node;
}
int pop(struct Stack *stack)
{
	struct Stack *node = stack->next;
	int key = node->val;
	stack->next = node->next;
	free(node);
	return key;
}
bool isEmpty(struct Stack *stack)
{
	return stack->next == NULL;
}
struct Stack *createStack()
{
	struct Stack *stack = malloc(sizeof(struct Stack));
	stack->next = NULL;
	return stack;
}
struct Stack *convertToStack(struct ListNode *list)
{
	struct Stack *stack = createStack();
	struct ListNode *node = list;
	while (node != NULL)
	{
		push(stack, node->val);
		node = node->next;
	}
	return stack;
}
struct Stack *addStack(struct Stack *stack1, struct Stack *stack2)
{
	struct Stack *stack = createStack();
	int key1, key2, key;
	int carry = 0;
	while (!isEmpty(stack1) || !isEmpty(stack2))
	{
		key1 = isEmpty(stack1) ? 0 : pop(stack1);
		key2 = isEmpty(stack2) ? 0 : pop(stack2);
		key = (key1 + key2 + carry) % 10;
		carry = (key1 + key2 + carry) / 10;
		push(stack, key);
	}
	if (carry == 1)
	{
		push(stack, carry);
	}
	return stack;
}
struct ListNode *convertToList(struct Stack *stack)
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
	struct ListNode *node = head;
	while (!isEmpty(stack))
	{
		node->next = malloc(sizeof(struct ListNode));
		node = node->next;
		node->val = pop(stack);
	}
	node->next = NULL;
	node = head;
	head = head->next;
	free(node);
	return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	struct Stack *stack1 = convertToStack(l1);
	struct Stack *stack2 = convertToStack(l2);
	struct Stack *assistStack = addStack(stack1, stack2);
	struct ListNode *head = convertToList(assistStack);
	return head;
}