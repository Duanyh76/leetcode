int min(int a, int b)
{
	return a < b ? a : b;
}

int minOfThree(int a, int b, int c)
{
	return a < min(b, c) ? a : min(b, c);
}

int nthUglyNumber(int n) 
{
	int *uglyNumberArray = malloc(sizeof(int) * n);
	uglyNumberArray[0] = 1;
	int indexTwo = 0;
	int indexThree = 0;
	int indexFive = 0;
	int productTwo;
	int productThree;
	int productFive;
	for (int i = 1; i < n; i++)
	{
		productTwo = uglyNumberArray[indexTwo] * 2;
		productThree = uglyNumberArray[indexThree] * 3;
		productFive = uglyNumberArray[indexFive] * 5;
		uglyNumberArray[i] = minOfThree(productTwo, productThree, productFive);
		if (uglyNumberArray[i] == productTwo)
			indexTwo++;
		if (uglyNumberArray[i] == productThree)
			indexThree++;
		if (uglyNumberArray[i] == productFive)
			indexFive++;
	}
	return uglyNumberArray[n - 1];
}