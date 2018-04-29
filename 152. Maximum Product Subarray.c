int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int maxProduct(int* nums, int numsSize)
{
	int *posProduct = malloc(sizeof(int) * numsSize);
	int *negProduct = malloc(sizeof(int) * numsSize);
	int maxProduct = nums[0];
	posProduct[0] = nums[0] > 0 ? nums[0] : 0;
	negProduct[0] = nums[0] < 0 ? nums[0] : 0;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] >= 0)
		{
			posProduct[i] = max(nums[i], nums[i] * posProduct[i - 1]);
			negProduct[i] = nums[i] * negProduct[i - 1];
		}
		else
		{
			negProduct[i] = min(nums[i], nums[i] * posProduct[i - 1]);
			posProduct[i] = nums[i] * negProduct[i - 1];
		}
		maxProduct = max(maxProduct, posProduct[i]);
	}
	return maxProduct;
}