int removeElement(int* nums, int numsSize, int val) 
{
	int numsPosition = 0;
	int checkPosition = 0;
	int newSize = numsSize;
	while (checkPosition < numsSize)
	{
		if (nums[checkPosition] != val)
		{
			nums[numsPosition++] = nums[checkPosition];
		}
		else
		{
			newSize--;
		}
		checkPosition++;
	}
	return newSize;
}