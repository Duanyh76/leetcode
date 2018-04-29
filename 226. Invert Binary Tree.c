struct TreeNode* invertTree(struct TreeNode* root) 
{
	if (root == NULL)
		return NULL;
	root->left = invertTree(root->left);
	root->right = invertTree(root->right);
	struct TreeNode *tempNode = root->left;
	root->left = root->right;
	root->right = tempNode;
	return root;
}