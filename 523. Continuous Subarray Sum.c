bool checkSubarraySum(int* nums, int numsSize, int k)
{
	if (k != 0)
	{
		int count;
		for (int i = 0; i < numsSize - 1; i++)
		{
			count = nums[i];
			for (int j = i + 1; j < numsSize; j++)
			{
				count += nums[j];
				if (count % k == 0)
					return true;
			}
		}
	}
	else
	{
		bool halfFalg = false;
		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] == 0 && halfFalg == true)
				return true;
			if (nums[i] == 0 && halfFalg == false)
				halfFalg = true;
			else
				halfFalg = false;

		}
	}
	return false;
}