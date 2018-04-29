int min(int a, int b)
{
	return a < b ? a : b;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
	for (int row = 1; row < gridRowSize; row++)
	{
		grid[row][0] += grid[row - 1][0];
	}
	for (int col = 1; col < gridColSize; col++)
	{
		grid[0][col] += grid[0][col - 1];
	}
	for (int row = 1; row < gridRowSize; row++)
	{
		for (int col = 1; col < gridColSize; col++)
		{
			grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
		}
	}
	return grid[gridRowSize - 1][gridColSize - 1];
}