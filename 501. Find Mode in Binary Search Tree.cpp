class Solution {
public:
	map<int, int> log;
	vector<int> findMode(TreeNode* root) {
		findModeWithLog(root);
		vector<int> mode;
		int maxNum = 0;
		for (auto index = log.begin(); index != log.end(); index++)
		{
			if (index->second > maxNum)
				maxNum = index->second;
		}
		for (auto index = log.begin(); index != log.end(); index++)
		{
			if (index->second == maxNum)
				mode.push_back(index->first);
		}
        return mode;
	}
	void findModeWithLog(TreeNode *root)
	{
		if (root == NULL)
			return;
		log[root->val]++;
		findModeWithLog(root->left);
		findModeWithLog(root->right);
	}
};