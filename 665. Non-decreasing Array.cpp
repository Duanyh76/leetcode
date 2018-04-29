class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int count = 0;
		int size = nums.size();
		for (int i = 1; i < size; i++)
		{
			if (nums[i - 1] > nums[i])
			{
				count++;
				if (count == 2)
					return false;
				if (i == 1 || nums[i - 2] <= nums[i])
					nums[i - 1] = nums[i];
				else
					nums[i] = nums[i - 1];
			}
		}
		return true;
	}
};