struct Stack
{
	char val;
	struct Stack *next;
};

char top(struct Stack *stack)
{
	return stack->val;
}

struct Stack *pop(struct Stack *stack)
{
	struct Stack *node = stack;
	stack = stack->next;
	free(node);
	return stack;
}

struct Stack *push(char key, struct Stack *stack)
{
	struct Stack *node = malloc(sizeof(struct Stack));
	node->val = key;
	node->next = stack;
	stack = node;
	return stack;
}


bool isValid(char* s) 
{
	int length = strlen(s);
	if (length <= 1)
		return false;

	struct Stack *stack = malloc(sizeof(struct Stack));
	stack = NULL;
	for (int i = 0; i < length; i++)
	{
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')
		{
			stack = push(s[i], stack);
		}
		else
		{
			if (s[i] == ']')
			{
				if (stack && top(stack) == '[')
					stack = pop(stack);
				else
					return false;
			}
			else if (s[i] == '}')
			{
				if (stack && top(stack) == '{')
					stack = pop(stack);
				else
					return false;
			}
			else // s[i] == ')'
			{
				if (stack && top(stack) == '(')
					stack = pop(stack);
				else
					return false;
			}
		}
	}
	return stack == NULL;
}