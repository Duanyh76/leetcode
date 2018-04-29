int max(int a, int b)
{
	return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) 
{
	int *withStock = malloc(sizeof(int)*pricesSize);
	int *withoutStock = malloc(sizeof(int)*pricesSize);
	withStock[0] = -prices[0];
	withoutStock[0] = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		withStock[i] = max(withStock[i - 1], (i == 1 ? 0 : withoutStock[i - 2]) - prices[i]);
		withoutStock[i] = max(withoutStock[i - 1], withStock[i - 1] + prices[i]);
	}
	return withoutStock[pricesSize - 1];
}