// 99ms
int min(int a, int b)
{
	return a < b ? a : b;
}

int numSquares(int n) 
{
	int *numSquaresArray = malloc(sizeof(int)*(n + 1));
	int factor;
	int tempCount;
	for (int i = 0; i <= n; i++)
	{
		factor = sqrt(i);
		if (factor*factor == i)
		{
			numSquaresArray[i] = 1;
		}
		else
		{
			numSquaresArray[i] = i;
			for (int j = factor; j > 1; j--)
			{
				tempCount = numSquaresArray[j*j] + numSquaresArray[i - j*j];
				numSquaresArray[i] = min(tempCount, numSquaresArray[i]);
			}
		}
	}
	return numSquaresArray[n];
}

// 3ms
int numSquares(int n) 
{
	while (n % 4 == 0) 
		n /= 4;
	if (n % 8 == 7) 
		return 4;
	for (int a = 0; a * a <= n; a++)
	{
		int b = sqrt(n - a * a);
		if (a * a + b * b == n) 
		{
			return !!a + !!b;
		}
	}
	return 3;
}
