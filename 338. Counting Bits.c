// AC 26ms
int* countBits(int num, int* returnSize)
{
	*returnSize = num + 1;
	int *array = malloc(sizeof(int)*(num + 1));
	array[0] = 0;
	int flag = 1;
	for (int i = 1; i <= num; i++)
	{
		if (i == flag * 2)
		{
			array[i] = 1;
			flag = i;
		}
		else if (i % 2)
		{
			array[i] = array[i - 1] + 1;
		}
		else
		{
			array[i] = 1 + array[i - flag];
		}
	}
	return array;
}

// AC 23ms
int *countBits(int num, int *returnSize)
{
	*returnSize = num + 1;
	int *array = malloc(sizeof(int)*(num + 1));
	array[0] = 0;
	for (int i = 1; i <= num; i++)
	{
		array[i] = array[i >> 1] + (i & 1);
	}
	return array;
}