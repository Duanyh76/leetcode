int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
	int **pathMatrix = malloc(sizeof(int *) * obstacleGridRowSize);
	bool hasBlock = false;
	for (int row = 0; row < obstacleGridRowSize; row++)
	{
		pathMatrix[row] = malloc(sizeof(int) * obstacleGridColSize);
		if (obstacleGrid[row][0] == 1)
		{
			pathMatrix[row][0] = -1;
			hasBlock = true;
		}
		else if(hasBlock)
		{
			pathMatrix[row][0] = 0;
		}
		else
		{
			pathMatrix[row][0] = 1;
		}
	}
	hasBlock = false;
	for (int col = 0; col < obstacleGridColSize; col++)
	{
		if (obstacleGrid[0][col] == 1)
		{
			pathMatrix[0][col] = -1;
			hasBlock = true;
		}
		else if (hasBlock)
		{
			pathMatrix[0][col] = 0;
		}
		else
		{
			pathMatrix[0][col] = 1;
		}
	}

	for (int row = 1; row < obstacleGridRowSize; row++)
	{
		for (int col = 1; col < obstacleGridColSize; col++)
		{
			if (obstacleGrid[row][col] == 1)
			{
				pathMatrix[row][col] = -1;
			}
			else if(pathMatrix[row-1][col] == -1)
			{
				pathMatrix[row][col] = pathMatrix[row][col - 1];
			}
			else if (pathMatrix[row][col - 1] == -1)
			{
				pathMatrix[row][col] = pathMatrix[row - 1][col];
			}
			else
			{
				pathMatrix[row][col] = pathMatrix[row - 1][col] + pathMatrix[row][col - 1];
			}
		}
	}

	if (pathMatrix[obstacleGridRowSize - 1][obstacleGridColSize - 1] == -1)
		return 0;
	return pathMatrix[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) 
{
	if (obstacleGrid[0][0] == 1)
		return 0;
	for (int i = 0; i < obstacleGridRowSize; i++)
	{
		if (obstacleGrid[i][0] == 0)
			obstacleGrid[i][0] = 1;
		else
		{
			for (; i < obstacleGridRowSize; i++)
			{
				obstacleGrid[i][0] = 0;
			}
			break;
		}
	}
	for (int i = 1; i < obstacleGridColSize; i++)
	{
		if (obstacleGrid[0][i] == 0)
			obstacleGrid[0][i] = 1;
		else
		{
			for (; i < obstacleGridColSize; i++)
			{
				obstacleGrid[0][i] = 0;
			}
			break;
		}
	}

	for (int i = 1; i < obstacleGridRowSize; i++)
	{
		for (int j = 1; j < obstacleGridColSize; j++)
		{
			if (obstacleGrid[i][j] == 1)
			{
				obstacleGrid[i][j] = 0;
				continue;
			}
			obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
		}
	}
	return obstacleGrid[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}