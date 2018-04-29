int findPosition(int key, int *array)
{
	int position = 0;
	while (array[position] != key)
	{
		position++;
	}
	return position;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
	if (postorderSize == 0 || inorderSize == 0)
		return NULL;
	int key = postorder[postorderSize - 1];
	int index = findPosition(key, inorder);
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->val = key;
	int leftLength = index;
	int rightLength = postorderSize - index - 1;
	root->left = buildTree(inorder, leftLength, postorder, leftLength);
	root->right = buildTree(inorder + index + 1, rightLength, postorder + index, rightLength);
	return root;
}