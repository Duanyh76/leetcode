int countNumbersWithUniqueDigits(int n)
{
	if (n >= 10)
		n = 10;
	int *countArray = malloc(sizeof(int)*(n + 1));
	countArray[0] = 1;
	int tempCount = 1;
	int factor;
	for (int i = 1; i <= n && i <= 10; i++)
	{
		factor = i != 1 ? i - 1 : i;
		tempCount *= 10 - factor;
		countArray[i] = countArray[i - 1] + tempCount;
	}
	return countArray[n];
}