int max(int a, int b)
{
	return a > b ? a : b;
}

bool canJump(int *nums, int numsSize)
{
	int reach = 1;
	for (int i = 0; i < reach && reach < numsSize; i++)
	{
		reach = max(reach, nums[i] + i + 1);
	}
	return reach >= numsSize;
}