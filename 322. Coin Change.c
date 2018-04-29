int min(int a, int b)
{
	return a < b ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) 
{
	int *amountArray = malloc(sizeof(int) * (amount + 1));
	amountArray[0] = 0;
	int coin;
	for (int count = 1; count <= amount; count++)
	{
		amountArray[count] = INT_MAX;
		for (int index = 0; index < coinsSize; index++)
		{
			coin = coins[index];
			if (count < coin)
			{
				continue;
			}
			if (count == coin)
			{
				amountArray[count] = 1;
				break;
			}
			else if(amountArray[count - coin] != -1)
			{
				amountArray[count] = min(amountArray[count], amountArray[count - coin] + 1);
			}
		}
		if (amountArray[count] == INT_MAX)
			amountArray[count] = -1;
	}
	return amountArray[amount];
}