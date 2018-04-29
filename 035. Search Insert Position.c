int binarySearch(int *nums, int target, int start, int end)
{
	int mid;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			start = mid + 1;
		}
		else // nums[mid]>target
		{
			end = mid - 1;
		}
	}
	return start;
}

int searchInsert(int* nums, int numsSize, int target) 
{
	int position = binarySearch(nums, target, 0, numsSize - 1);
	return position;
}