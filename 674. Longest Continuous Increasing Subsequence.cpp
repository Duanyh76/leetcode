class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int maxCount = 1;
		int count = 1;
		int size = nums.size();
        if(size==0)
            return 0;
		for (int i = 1; i < size; i++)
		{
			if (nums[i] > nums[i - 1])
				count++;
			else
			{
				maxCount = max(maxCount, count);
				count = 1;
			}
		}
		return max(maxCount, count);
	}
};