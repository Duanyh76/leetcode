int* twoSum(int* nums, int numsSize, int target)
{
	int *pair = malloc(sizeof(int) * 2);
	int tempTarget;
	for (int i = 0; i < numsSize; i++)
	{
		tempTarget = target - nums[i];
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[j] == tempTarget)
			{
				pair[0] = i;
				pair[1] = j;
				return pair;
			}
		}
	}
	return NULL;
}