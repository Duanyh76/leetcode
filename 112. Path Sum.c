bool hasPathSum(struct TreeNode* root, int sum)
{
	if (root == NULL)
		return false;
	sum -= root->val;
	if (sum == 0 && root->left == NULL && root->right == NULL)
		return true;
	return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}