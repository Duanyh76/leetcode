class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		priority_queue<pair<int, int>> log;
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			log.push(make_pair(nums[i], i));
		}
		vector<string> logs(size, "");
		int index;
		for (int i = 0; i < size; i++)
		{
			index = log.top().second;
			logs[index] = to_string(i + 1);
			log.pop();
		}
		for (int i = 0; i < size; i++)
		{
			if (logs[i] == "1")
				logs[i] = "Gold Medal";
			else if (logs[i] == "2")
				logs[i] = "Silver Medal";
			else if(logs[i]=="3")
				logs[i] = "Bronze Medal";
		}
		return logs;
	}
};