int uniquePaths(int m, int n) 
{
	if (m == 1 || n == 1)
		return 1;
	int **pathMatrix = malloc(sizeof(int *) * m);
	for (int i = 0; i < m; i++)
	{
		pathMatrix[i] = malloc(sizeof(int) * n);
		pathMatrix[i][0] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		pathMatrix[0][i] = 1;
	}

	for (int row = 1; row < m; row++)
	{
		for (int col = 1; col < n; col++)
		{
			pathMatrix[row][col] = pathMatrix[row - 1][col] + pathMatrix[row][col - 1];
		}
	}
	return pathMatrix[m - 1][n - 1];
}