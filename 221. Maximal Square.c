int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int minOfThree(int a, int b, int c)
{
	return min(a, min(b, c));
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) 
{
	int maxSide = 0;
	for (int i = 0; i < matrixRowSize; i++)
	{
		if (matrix[i][0] == '1')
		{
			maxSide = 1;
			break;
		}
	}
	if (maxSide == 0)
	{
		for (int i = 0; i < matrixColSize; i++)
		{
			if (matrix[0][i] == '1')
			{
				maxSide = 1;
				break;
			}
		}
	}

	int aroundSide;
	for (int row = 1; row < matrixRowSize; row++)
	{
		for (int col = 1; col < matrixColSize; col++)
		{
			if (matrix[row][col] == '1')
			{
				aroundSide = minOfThree(matrix[row - 1][col] - '0', matrix[row - 1][col - 1] - '0', matrix[row][col - 1] - '0');
				matrix[row][col] = max(matrix[row][col] - '0', aroundSide + 1) - '0';
				maxSide = max(maxSide, matrix[row][col] - '0');
			}
		}
	}
	return maxSide*maxSide;
}

/**************/

char max(char a, char b)
{
	return a > b ? a : b;
}

char min(char a, char b)
{
	return a < b ? a : b;
}

char minOfThree(char a, char b, char c)
{
	char tempMin = min(a, b);
	return min(tempMin, c);
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize)
{
	if (matrixRowSize == 0 || matrixColSize == 0)
		return 0;
	char maxLength = matrix[0][0];
	for (int i = 1; i < matrixRowSize; i++)
	{
		for (int j = 1; j < matrixColSize; j++)
		{
			if (matrix[i][j] == '1')
			{
				matrix[i][j] = minOfThree(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]) + 1;
			}
		}
	}
	for (int i = 0; i < matrixRowSize; i++)
	{
		for (int j = 0; j < matrixColSize; j++)
		{
			maxLength = max(maxLength, matrix[i][j]);
		}
	}
	int maxInt = maxLength - '0';
	return maxInt * maxInt;
}