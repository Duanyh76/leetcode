int maxProfit(int* prices, int pricesSize)
{
	int profit = 0;
	int buyPrice = prices[0];
	for (int i = 1; i < pricesSize; i++)
	{
		buyPrice = buyPrice < prices[i] ? buyPrice : prices[i];
		profit = profit > prices[i] - buyPrice ? profit : prices[i] - buyPrice;
	}
	return profit;
}

int maxProfit(int *prices, int pricesSize)
{
	int *minPrice = malloc(sizeof(int)*pricesSize);
	int *profit = malloc(sizeof(int)*pricesSize);
	minPrice[0] = prices[0];
	profit[0] = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		minPrice[i] = minPrice[i - 1] < prices[i] ? minPrice[i - 1] : prices[i];
		profit[i] = prices[i] - minPrice[i];
	}
	int maxPro = profit[0];
	for (int i = 1; i < pricesSize; i++)
	{
		maxPro = maxPro > profit[i] ? maxPro : profit[i];
	}
	return maxPro;
}