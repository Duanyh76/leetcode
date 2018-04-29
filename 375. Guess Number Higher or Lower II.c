int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int getMoneyAmount(int n)
{
	if (n <= 3)
		return n - 1;
		
	int **amountMatrix = malloc(sizeof(int *)*(n + 1));
	for (int i = 0; i <= n; i++)
	{
		amountMatrix[i] = malloc(sizeof(int)*(n + 1));
		for (int j = 0; j <= n; j++)
		{
			amountMatrix[i][j] = INT_MAX;
		}
		amountMatrix[i][i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		amountMatrix[i][i + 1] = i;
	}

	int startPos;
	int endPos;
	int midPos;
	int length;
	int endOfStartPos;
	int tempAmount;

	for (length = 3; length <= n; length++)
	{
		endOfStartPos = n - length + 1;
		for (startPos = 1; startPos <= endOfStartPos; startPos++)
		{
			endPos = startPos + length - 1;
			for (midPos = startPos + 1; midPos < endPos; midPos++)
			{
				tempAmount = midPos + max(amountMatrix[startPos][midPos - 1],
					amountMatrix[midPos + 1][endPos]);
				amountMatrix[startPos][endPos] = min(tempAmount, amountMatrix[startPos][endPos]);
			}
		}
	}
	return amountMatrix[1][n];
}