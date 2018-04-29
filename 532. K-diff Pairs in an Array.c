int findPairs(int* nums, int numsSize, int k)
{
	int temp;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] > nums[j])
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (i != 0)
			if (nums[i] == nums[i - 1])
				continue;
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + k > nums[j])
				continue;
			else if (nums[i] + k == nums[j])
			{
				count++;
				break;
			}
			else
				break;
		}
	}
	return count;
}