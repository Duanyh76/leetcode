class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int size = nums.size();
		if (size == 1)
			return 0;
		int firstIndex, secondIndex;
		if (nums[0] > nums[1])
		{
			firstIndex = 0;
			secondIndex = 1;
		}
		else
		{
			firstIndex = 1;
			secondIndex = 0;
		}
		for (int i = 2; i < size; i++)
		{
			if (nums[i] <= nums[secondIndex])
			{
				;
			}
			else if (nums[i] <= nums[firstIndex])
			{
				secondIndex = i;
			}
			else
			{
				secondIndex = firstIndex;
				firstIndex = i;
			}
		}
		if (nums[firstIndex] >= nums[secondIndex] * 2)
			return firstIndex;
		return -1;
	}
};

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		vector<int> temp(nums.begin(), nums.end());
		sort(temp.begin(), temp.end());
		int a = temp.size() - 1;
		int b = (temp.size() - 2 == 0 ? 0 : temp.size() - 2);
		int index;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == temp[a])
			{
				index = i;
				break;
			}
		}
		return (temp[a] >= 2 * temp[b] ? index : (a == b ? 0 : -1));
	}
};