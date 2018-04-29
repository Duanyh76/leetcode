int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

// dynamic programming AC 3ms
int wiggleMaxLength(int* nums, int numsSize)
{
	int *posStart = malloc(sizeof(int)*numsSize);
	int *negStart = malloc(sizeof(int)*numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		posStart[i] = negStart[i] = 1;
	}
	for (int i = 1; i < numsSize; i++)
	{
		/* O(n^2)
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				posStart[i] = max(posStart[i], negStart[j] + 1);
			}
			else if (nums[i] < nums[j])
			{
				negStart[i] = max(negStart[i], posStart[j] + 1);
			}
		}*/
		// O(n)
		if (nums[i] > nums[i - 1])
		{
			posStart[i] = negStart[i - 1] + 1;
			negStart[i] = negStart[i - 1];
		}
		else if (nums[i] < nums[i - 1])
		{
			negStart[i] = posStart[i - 1] + 1;
			posStart[i] = posStart[i - 1];
		}
		else
		{
			posStart[i] = posStart[i - 1];
			negStart[i] = negStart[i - 1];
		}
	}
	return max(posStart[numsSize - 1], negStart[numsSize - 1]);
}

// greedy AC 3ms 
int wiggleMaxLength(int* nums, int numsSize)
{
	int posStart = 1;
	int negStart = 1;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] > nums[i - 1])
		{
			posStart = negStart + 1;
		}
		else if (nums[i] < nums[i - 1])
		{
			negStart = posStart + 1;
		}
	}
	return min(numsSize, max(posStart, negStart));
}

