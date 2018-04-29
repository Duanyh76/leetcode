bool assistIsValid(struct TreeNode *root, int lowBound, int highBound)
{
	if (root == NULL)
		return true;
	if (root->val < lowBound || root->val > highBound)
		return false;
	if (root->left && root->left->val >= root->val)
		return false;
	if (root->right && root->right->val <= root->val)
		return false;
	return assistIsValid(root->left, lowBound, root->val - 1)
		&& assistIsValid(root->right, root->val + 1, highBound);
}

bool isValidBST(struct TreeNode* root)
{
	return assistIsValid(root, INT_MIN, INT_MAX);
}