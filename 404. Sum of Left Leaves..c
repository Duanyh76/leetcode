
bool isLeaf(struct TreeNode *node)
{
	return node->left == NULL && node->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode* root) 
{
	if (root == NULL)
		return 0;
	if (root->left&&isLeaf(root->left))
		return root->left->val + sumOfLeftLeaves(root->right);
	return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->rigth);
}