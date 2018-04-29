/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Stack
{
	int val;
	struct Stack *next;
};

struct Stack *createStack()
{
	struct Stack *stack = malloc(sizeof(struct Stack));
	stack->next = NULL;
	return stack;
}
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
int sizeOfStack(struct Stack *stack)
{
	int size = 0;
	struct Stack *node = stack->next;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}
	return size;
}
bool isEmpty(struct Stack *stack)
{
	return stack->next == NULL;
}
void convertTreeToStack(struct TreeNode *root, struct Stack *stack)
{
	if (root == NULL)
		return;
	push(stack, root->val);
	convertTreeToStack(root->left, stack);
	convertTreeToStack(root->right, stack);
	return;
}
int *convertStackToArray(struct Stack *stack, int size)
{
	int *array = malloc(sizeof(int)*size);
	int index = size - 1;
	while (!isEmpty(stack))
	{
		array[index--] = pop(stack);
	}
	return array;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	struct Stack *stack = createStack();
	convertTreeToStack(root, stack);
	int size = sizeOfStack(stack);
	*returnSize = size;
	int *array = convertStackToArray(stack, size);
	return array;
}