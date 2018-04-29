int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int count = 0;
	int max = 0;
	for (int i = 0; i < numsSize; i++)
	{
		count = (count + nums[i]) * nums[i];
		if (count > max)
			max = count;
	}
	return max;
}