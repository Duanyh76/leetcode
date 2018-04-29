class Solution {
public:
	int pathSum(vector<int>& nums) {
		int size = nums.size();
		sort(nums.begin(), nums.end());
		int depth = nums[size - 1] / 100;
		int nodeCount = pow(2, depth) - 1;
		vector<int> log(nodeCount + 1,-1);
		int position;
		int value;
		for (int i = 0; i < size; i++)
		{
			value = nums[i] % 10;
			position = nums[i] % 100;
			position /= 10;
			depth = nums[i] / 100;

			int logPos = pow(2, depth - 1) + position - 1;
			log[logPos] = value;
		}
		int count = 0;
		for (int i = nodeCount; i >= 1; i--)
		{
			if (isLeaves(i,log))
			{
				for (int j = i; j >= 1; j /= 2)
				{
					count += log[j];
				}
			}
		}
		return count;
	}
	bool isLeaves(int i, vector<int> log)
	{
		if (log[i] == -1)
			return false;
		int nodeCount = log.size() - 1;
		if (2 * i > nodeCount)
			return true;
		if (log[2 * i] == -1 && log[2 * i + 1] == -1)
			return true;
		return false;
	}
};