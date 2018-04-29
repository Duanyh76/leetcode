struct Stack
{
	char val;
	struct Stack *next;
};

struct Stack *push(struct Stack *numStack, char value)
{
	struct Stack *node = malloc(sizeof(struct Stack));
	node->val = value;
	node->next = numStack;
	numStack = node;
	return numStack;
}

struct Stack *pop(struct Stack *numStack)
{
	numStack = numStack->next;
	return numStack;
}

char top(struct Stack *numStack)
{
	return numStack->val;
}

char* removeKdigits(char* num, int k)
{
	int length = strlen(num);
	if (length <= k)
		return "0";
	int arrayLength = length - k;
	char *array = malloc(sizeof(char) * (arrayLength + 1));
	array[arrayLength] = '\0';
	struct Stack *numStack = malloc(sizeof(struct Stack));
	numStack->val = '0';
	numStack->next = NULL;
	for (int i = 0; i < length; i++)
	{
		while (k > 0 && num[i] < top(numStack))
		{
			numStack = pop(numStack);
			k--;
		}
		numStack = push(numStack, num[i]);
	}
	while (k != 0)
	{
		numStack = pop(numStack);
		k--;
	}
	for (int i = arrayLength - 1; i >= 0; i--)
	{
		array[i] = top(numStack);
		numStack = pop(numStack);
	}
	while (array[0] == '0')
	{
		array++;
	}
	if (array[0] == '\0')
		return "0";
	return array;
}