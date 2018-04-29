int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	*returnSize = 2;
	int *indexArray = malloc(sizeof(int) * 2);
	int firstPos = 0;
	int secondPos = numbersSize - 1;
	int factor;
	while (secondPos > firstPos)
	{
		factor = target - numbers[firstPos];
		while (numbers[secondPos] >= factor)
		{
			if (numbers[secondPos] == factor)
			{
				indexArray[0] = firstPos + 1;
				indexArray[1] = secondPos + 1;
				return indexArray;
			}
			secondPos--;
		}
		firstPos++;
	}
	return indexArray;
}