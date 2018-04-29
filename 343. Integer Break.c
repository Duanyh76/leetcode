int max(int a, int b)
{
	return a > b ? a : b;
}

int integerBreak(int n)
{
	int *product = malloc(sizeof(int) * (n + 1));
	product[0] = product[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		product[i] = 0;
		for (int sub = 1; sub < i; sub++)
		{
			product[i] = max(product[i], 
				max(sub, product[sub]) * max(i - sub, product[i - sub]));
		}
	}
	return product[n];
}