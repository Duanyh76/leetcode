int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
	int minVal = min(p->val, q->val);
	int maxVal = max(p->val, q->val);
	if (root->val > maxVal)
		return lowestCommonAncestor(root->left, p, q);
	if (root->val < minVal)
		return lowestCommonAncestor(root->right, p, q);
	return root;
}