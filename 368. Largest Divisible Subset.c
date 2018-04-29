int max(int a, int b)
{
	return a > b ? a : b;
}

int *sort(int *nums, int numsSize)
{
	int tempNum;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] > nums[j])
			{
				tempNum = nums[i];
				nums[i] = nums[j];
				nums[j] = tempNum;
			}
		}
	}
	return nums;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize)
{
    if(numsSize == 0)
        return NULL;
	nums = sort(nums, numsSize);
	int *divisibleArray = malloc(sizeof(int)*numsSize);
	int *positionArray = malloc(sizeof(int)*numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		divisibleArray[i] = 1;
		positionArray[i] = i;
	}
	int maxLength = 1;
	int position;
	for (int i = 1; i < numsSize; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0)
			{
				if (divisibleArray[i] < divisibleArray[j] + 1)
				{
					divisibleArray[i] = divisibleArray[j] + 1;
					positionArray[i] = j;
				}
			}
		}
		if (maxLength < divisibleArray[i])
		{
			maxLength = divisibleArray[i];
			position = i;
		}
	}
	*returnSize = maxLength;
	int *subset = malloc(sizeof(int)*maxLength);
	for (int i = maxLength - 1; i >= 0; i--)
	{
		subset[i] = nums[position];
		position = positionArray[position];
	}
	return subset;
}