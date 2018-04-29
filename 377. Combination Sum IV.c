int combinationSum4(int* nums, int numsSize, int target) 
{
	int *targetArray = malloc(sizeof(int)*(target + 1));
	targetArray[0] = 1;
	for (int i = 1; i <= target; i++)
	{
		targetArray[i] = 0;
		for (int j = 0; j < numsSize; j++)
		{
			if (i >= nums[j])
			{
				targetArray[i] += targetArray[i - nums[j]];
			}
		}
	}
	return targetArray[target];
}