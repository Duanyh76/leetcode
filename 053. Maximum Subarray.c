int max(int a, int b)
{
	return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize)
{
	int *subArray = malloc(sizeof(int)*numsSize);
	subArray[0] = nums[0];
	int maxNum = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		subArray[i] = max(nums[i], nums[i] + subArray[i - 1]);
		maxNum = max(maxNum, subArray[i]);
	}
	return maxNum;
}