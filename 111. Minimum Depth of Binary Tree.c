int min(int a, int b)
{
	return a < b ? a : b;
}
 
int minDepth(struct TreeNode* root) 
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	if (root->left == NULL)
		return minDepth(root->right) + 1;
	if (root->right == NULL)
		return minDepth(root->left) + 1;
	return min(minDepth(root->left), minDepth(root->right)) + 1;
}