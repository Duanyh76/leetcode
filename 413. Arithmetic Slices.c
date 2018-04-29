int numberOfArithmeticSlices(int* A, int ASize)
{
	int *countArray = malloc(sizeof(int)*ASize);
	countArray[0] = countArray[1] = 1;
	countArray[2] = (A[2] - A[1] == A[1] - A[0]);
	int count = countArray[2];
	for (int i = 3; i < ASize; i++)
	{
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
			countArray[i] = countArray[i - 1] + 1;
		else
			countArray[i] = 0;
		count += countArray[i];
	}
	return count;
}