class Solution {
public:
	bool isPossible(vector<int>& nums) {
		int size = nums.size();
		if (size < 3)
			return false;
		vector<pair<int,int>> tailNum;
		tailNum.push_back(make_pair(nums[0], 1));
		for (int i = 1; i < size; i++)
		{
			auto it = tailNum.begin();
			for (; it != tailNum.end(); it++)
			{
				if (it->first == nums[i] - 1)
				{
					it->second++;
					it->first++;
					break;
				}
			}
			if (it == tailNum.end())
				tailNum.push_back(make_pair(nums[i], 1));
		}
		auto it = tailNum.begin();
		bool check = true;

		for (; it != tailNum.end()&&check; it++)
		{
			if (it->second < 3)
			{
				int theNum = it->first - it->second + 1;
				auto pre = tailNum.begin();
				
				for (; pre != it; pre++)
				{
					if (pre->second == 3)
						continue;
					int endNum = pre->first;
					int beginNum = pre->first - pre->second + 1;
					if (theNum >= endNum||endNum<=it->first
						||endNum-theNum+1<3||theNum-beginNum+1<3)
						continue;
					pre->second = theNum - beginNum + 1;
					pre->first = theNum;
					it->first = endNum;
					it->second = endNum - theNum + 1;
					break;
				}

				if (pre == it)
					check = false;
			}
		}
		return check;
	}
};

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		if (nums.size() < 3)
			return false;
		vector<pair<int, int>> log;
		auto it = make_pair(nums[0], 1);
		log.push_back(it);
		for (int i = 1; i < nums.size(); i++)
		{
			int pos = -1;
			int minLength = INT_MAX;
			for (int j = 0; j < log.size(); j++)
			{
				if (log[j].first == nums[i] - 1 && log[j].second < minLength)
				{
					minLength = log[j].second;
					pos = j;
				}
			}
			if (pos == -1)
			{
				it = make_pair(nums[i], 1);
				log.push_back(it);
			}
			else
			{
				log[pos].first = nums[i];
				log[pos].second++;
			}
		}
		for (int i = 0; i < log.size(); i++)
		{
			if (log[i].second < 3)
				return false;
		}
		return true;
	}
};

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		map<int, priority_queue<int, vector<int>, greater<int>>> log;
		int needMore = 0;
		for (int num : nums)
		{
			if (!log[num - 1].empty())
			{
				int size = log[num - 1].top() + 1;
				log[num - 1].pop();
				log[num].push(size);
				if (size == 3)
					needMore--;
			}
			else
			{
				log[num].push(1);
				needMore++;
			}
		}
		return needMore == 0;
    }
};
    