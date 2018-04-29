class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		map<int, vector<int>> log;
		for (int i = 0; i < nums.size(); i++)
		{
			log[nums[i]].push_back(i);
		}
		int minLength = INT_MAX;
		int maxTimes = 0;
		for (auto it = log.begin(); it != log.end(); it++)
		{
			if (it->second.size() >= maxTimes)
			{
				if (maxTimes == it->second.size())
				{
					int temp = it->second[it->second.size() - 1] - it->second[0] + 1;
					minLength = min(minLength, temp);
				}
				else
				{
					minLength = it->second[it->second.size() - 1] - it->second[0] + 1;
				}
				maxTimes = it->second.size();
			}
		}
		return minLength;
	}
};