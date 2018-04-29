int max(int a, int b)
{
	return a > b ? a : b;
}

int rob(int* nums, int numsSize)
{
	if (numsSize == 1)
		return nums[0];
	int *profitArray = malloc(sizeof(int) * numsSize);
	profitArray[0] = nums[0];
	profitArray[1] = max(nums[0], nums[1]);
	for (int i = 2; i < numsSize; i++)
	{
		profitArray[i] = max(profitArray[i - 1], nums[i] + profitArray[i - 2]);
	}
	return profitArray[numsSize - 1];
}