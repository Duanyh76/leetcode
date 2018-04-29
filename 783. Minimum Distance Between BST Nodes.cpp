class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		vector<int> log;
		getAllValue(log, root);
		sort(log.begin(), log.end());
		int minDiff = INT_MAX;
		int size = log.size();
		for (int i = 1; i < size; i++)
		{
			minDiff = min(minDiff, log[i] - log[i - 1]);
		}
		return minDiff;
	}
	void getAllValue(vector<int> &log, TreeNode *root)
	{
		if (root == NULL)
			return;
		log.push_back(root->val);
		getAllValue(log, root->left);
		getAllValue(log, root->right);
	}
};