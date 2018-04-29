class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;
		int index1 = 0;
		int index2 = 0;
		int size1 = nums1.size();
		int size2 = nums2.size();
		while (index1 < size1&&index2 < size2)
		{
			if (nums1[index1] < nums2[index2])
			{
				nums.push_back(nums1[index1++]);
			}
			else
			{
				nums.push_back(nums2[index2++]);
			}
		}
		while (index1 < size1)
			nums.push_back(nums1[index1++]);
		while (index2 < size2)
			nums.push_back(nums2[index2++]);
		int size = nums.size();
		if (size % 2 == 1)
			return nums[size / 2];
		double midNum = nums[size / 2] + nums[size / 2 - 1];
		return midNum / 2;
	}
};