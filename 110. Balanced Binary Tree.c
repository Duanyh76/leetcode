int max(int a, int b)
{
	return a > b ? a : b;
}

int Height(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	return 1 + max(Height(root->left), Height(root->right));
}

bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	int rightHeight = Height(root->right);
	int leftHeight = Height(root->left);
	int diff = rightHeight > leftHeight ? rightHeight - leftHeight : leftHeight - rightHeight;
    return diff <= 1 && isBalanced(root->right) && isBalanced(root->left);  
}