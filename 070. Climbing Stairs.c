int climbStairs(int n)
{
	if (n <= 2)
		return n;
	int *climbArray = malloc(sizeof(int)*n);
	climbArray[0] = 1;
	climbArray[1] = 2;
	for (int i = 2; i < n; i++)
	{
		climbArray[i] = climbArray[i - 1] + climbArray[i - 2];
	}
	return climbArray[n - 1];
}

int climbStairs(int n)
{
	int first, second, result;
	first = second = result = 1;
	for (int i = 1; i < n; i++)
	{
		result = first + second;
		first = second;
		second = result;
	}
	return result;
}