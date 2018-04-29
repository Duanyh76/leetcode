class Solution {
public:
	map<string, vector<TreeNode*>> log;
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		serialize(root);
		vector<TreeNode*> duplicateNode;
		for (auto it = log.begin(); it != log.end(); it++)
		{
			if (it->second.size() > 1)
				duplicateNode.push_back(it->second[0]);
		}
		return duplicateNode;
	}
	string serialize(TreeNode *node)
	{
		if (node == NULL)
			return "";
		string s = "(" + serialize(node->left) + "," + to_string(node->val) + "," + serialize(node->right) + ")";
		log[s].push_back(node);
		return s;
	}
};