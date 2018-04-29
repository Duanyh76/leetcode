class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		return convertBSTWithBias(root, 0);
	}
	int sum(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		return root->val + sum(root->right) + sum(root->left);
	}
	TreeNode* convertBSTWithBias(TreeNode *root, int bias)
	{
		if (root == NULL)
			return NULL;
		int rightSum = sum(root->right);
		root->val += rightSum;
		root->val += bias;
		root->left=convertBSTWithBias(root->left, root->val);
		root->right=convertBSTWithBias(root->right, bias);
		return root;
	}
};

class Solution {
public:
	int sum = 0;
	TreeNode* convertBST(TreeNode* root) {
		if (root == NULL)
			return NULL;
		root->right = convertBST(root->right);
		root->val += sum;
		sum = root->val;
		root->left = convertBST(root->left);
		return root;
	}
};