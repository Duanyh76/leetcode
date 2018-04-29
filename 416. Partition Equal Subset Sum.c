bool canPartition(int* nums, int numsSize)
{
	int count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		count += nums[i];
	}
	if (count % 2 == 1)
		return false;
	int target = count / 2;

	int *targetArray = malloc(sizeof(int)*(target + 1));
	for (int i = 0; i <= target; i++)
	{
		targetArray[i] = 0;
	}

	int num;
	int subTarget;
	int tempTarget;
	for (int i = 0; i < numsSize; i++)
	{
		num = nums[i];
		for (subTarget = 1; subTarget <= target; subTarget++)
		{
			if (targetArray[subTarget] == 1)
			{
				tempTarget = subTarget + num;
				if (tempTarget == target)
					return true;
				if (tempTarget <= target && targetArray[tempTarget] == 0)
					targetArray[tempTarget] = -1;
			}
		}
		for (subTarget = 1; subTarget <= target; subTarget++)
		{
			if (targetArray[subTarget] == -1)
				targetArray[subTarget] = 1;
		}
		targetArray[num] = 1;
	}
	return targetArray[target] == 1;
}