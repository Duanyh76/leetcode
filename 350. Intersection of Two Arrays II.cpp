class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> interArray;
		map<int, int> numMap;
		for (int num : nums1)
		{
			numMap[num]++;
		}
		for (int num : nums2)
		{
			if (numMap[num] != 0)
			{
				interArray.push_back(num);
				numMap[num]--;
			}
		}
		return interArray;
	}
};