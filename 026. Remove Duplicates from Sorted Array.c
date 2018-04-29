int removeDuplicates(int* nums, int numsSize)
{
	int newSize = numsSize;
	int numsPosition = 0;
	int checkPosition = 1;
	while (checkPosition < numsSize)
	{
		if (nums[checkPosition] == nums[numsPosition])
		{
			newSize--;
		}
		else
		{
			nums[++numsPosition] = nums[checkPosition];
		}
		checkPosition++;
	}
	return newSize;
}