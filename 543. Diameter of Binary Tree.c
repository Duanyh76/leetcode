int max(int a, int b)
{
	return a > b ? a : b;
}

int maxOfThree(int a, int b, int c)
{
	return max(max(a, b), c);
}

int depth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) 
{
	if (root == NULL)
		return 0;
	int diameterLeft = diameterOfBinaryTree(root->left);
	int diameterRight = diameterOfBinaryTree(root->right);
	int diameter = depth(root->left) + depth(root->right);
	int maxDiameter = maOfThree(diameter, diameterLeft, diameterRight);
	return maxDiameter;
}