int min(int a, int b)
{
	return a < b ? a : b;
}

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes)
{
	for (int row = 1; row < triangleRowSize; row++)
	{
		triangle[row][0] += triangle[row - 1][0];
		for (int col = 1; col < row; col++)
		{
			triangle[row][col] += min(triangle[row - 1][col], triangle[row - 1][col - 1]);
		}
		triangle[row][row] += triangle[row - 1][row - 1];
	}
	int minTotal = triangle[triangleRowSize - 1][0];
	for (int i = 1; i < triangleRowSize; i++)
	{
		minTotal = min(minTotal, triangle[triangleRowSize - 1][i]);
	}
	return minTotal;
}