// dfs
class Solution {
public:
	vector<int> leftLog;
	int widthOfBinaryTree(TreeNode* root) {
		return dfs(root, 1, 0);
	}
	int dfs(TreeNode *node, int index, int level)
	{
		if (node == NULL)
			return 0;
		if (level >= leftLog.size())
			leftLog.push_back(index);
		return max({ index + 1 - leftLog[level],
		dfs(node->left,index * 2,level + 1),
		dfs(node->right,index * 2 + 1,level + 1) });
	}
};

// bfs
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		queue<pair<TreeNode*, int>> log;
		log.push(make_pair(root, 1));
		int maxWidth = 1;
		while (!log.empty())
		{
			int left = log.front().second;
			int index;
			int size = log.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode *node = log.front().first;
				index = log.front().second;
				log.pop();
				if (node->left)
					log.push(make_pair(node->left, index * 2));
				if (node->right)
					log.push(make_pair(node->right, index * 2 + 1));
			}
			maxWidth = max(maxWidth, index - left + 1);
		}
		return maxWidth;
	}
};