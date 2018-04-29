int singleNumber(int* nums, int numsSize)
{
	int count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		count ^= nums[i];
	}
	return count;
}