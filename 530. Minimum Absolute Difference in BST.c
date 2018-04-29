struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int min_(int a, int b)
{
	return a < b ? a : b;
}

int minOfFour(int a, int b, int c, int d)
{
	return min(min(a, b), min(c, d));
}

int getMaxInLeft(struct TreeNode *root)
{
	struct TreeNode *node = root;
	while (node->right)
		node = node->right;
	return node->val;
}

int getMinInRight(struct TreeNode *root)
{
	struct TreeNode *node = root;
	while (node->left)
		node = node->left;
	return node->val;
}

int getMinimumDifference(struct TreeNode* root)
{
	if (!root)
		return INT_MAX;
	int minLeft = INT_MAX;
	if (root->left)
	{
		int maxInLeft = getMaxInLeft(root->left);
		minLeft = root->val - maxInLeft;
	}

	int minRight = INT_MAX;
	if (root->right)
	{
		int minInRight = getMinInRight(root->right);
		minRight = minInRight - root->val;
	}

	int leftDiff = getMinimumDifference(root->left);
	int rightDiff = getMinimumDifference(root->right);
	return minOfFour(minLeft, minRight, leftDiff, rightDiff);
}