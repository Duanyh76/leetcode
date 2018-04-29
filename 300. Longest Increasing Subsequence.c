// AC 13ms
int max(int a, int b)
{
	return a > b ? a : b;
}

int findMax(int *nums, int *LISArray, int targetPosition)
{
	int target = nums[targetPosition];
	int targetLength = 0;
	for (int i = 0; i < targetPosition; i++)
	{
		if (nums[i] < target)
		{
			targetLength = max(targetLength, LISArray[i]);
		}
	}
	targetLength++;
	return targetLength;
}

int lengthOfLIS(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int *LISArray = malloc(sizeof(int) * numsSize);
	LISArray[0] = 1;
	int maxLength = 1;
	for (int i = 1; i < numsSize; i++)
	{
		LISArray[i] = findMax(nums, LISArray, i);
		maxLength = max(maxLength, LISArray[i]);
	}
	return maxLength;
}

// AC 3ms
int min(int a, int b)
{
	return a < b ? a : b;
}

int BinarySearch(int *array, int end, int target)
{
	int begin = 0;
	int mid;
	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array[mid])
			return mid;
		else if (target < array[mid])
			end = mid - 1;
		else
			begin = mid + 1;
	}
	return begin;
}

int lengthOfLIS(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int *minLISArray = malloc(sizeof(int)*numsSize);
	minLISArray[0] = nums[0];
	int position;
	int length = 0;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] > minLISArray[length])
		{
			minLISArray[++length] = nums[i];
			continue;
		}
		position = BinarySearch(minLISArray, length, nums[i]);
		minLISArray[position] = min(minLISArray[position], nums[i]);
	}
	return length + 1;
}