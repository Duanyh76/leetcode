class Solution {
public:
	int findSecondMinimumValue(TreeNode* root) {
		if (root == NULL)
			return -1;
		queue<TreeNode*> log;
		int secondNum = INT_MAX;
		int key = root->val;
		log.push(root);
		while (!log.empty())
		{
			TreeNode *node = log.front();
			log.pop();
			if (node->left&&node->right)
			{
				log.push(node->left);
				log.push(node->right);
			}
			if (node->val != key&&node->val < secondNum)
				secondNum = node->val;
		}
		if (secondNum == INT_MAX)
			return -1;
		return secondNum;
	}
};