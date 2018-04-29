int maxProfit(int* prices, int pricesSize) 
{
	int count = 0;
	int buyPrice = prices[0];
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] > buyPrice)
			count += prices[i] - buyPrice;
		buyPrice = prices[i];
	}
	return count;
}