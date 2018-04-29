int count(struct TreeNode *node, int pre, int sum)
{
	if (!node)
		return 0;
	int current = pre + node->val;
	return (current == sum)
		+ count(node->left, current, sum)
		+ count(node->right, current, sum);
}

int pathSum(struct TreeNode* root, int sum) {
	if (!root)
		return 0;
	return count(root, 0, sum)
		+ pathSum(root->left, sum)
		+ pathSum(root->right, sum);
}