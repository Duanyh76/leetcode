int findPosition(int key, int *array)
{
	int position = 0;
	while (array[position] != key)
	{
		position++;
	}
	return position;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
	if (preorderSize == 0 || inorderSize == 0)
		return NULL;
	int key = preorder[0];
	int index = findPosition(key, inorder);
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->val = key;
	int leftLength = index;
	int rightLength = preorderSize - index - 1;
	root->left = buildTree(preorder + 1, leftLength, inorder, leftLength);
	root->right = buildTree(preorder + index + 1, rightLength, inorder + index + 1, rightLength);
	return root;
}