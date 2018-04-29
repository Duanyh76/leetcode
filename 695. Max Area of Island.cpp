class Solution {
public:
	int rowSize;
	int colSize;
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		rowSize = grid.size();
		colSize = grid[0].size();
		int maxArea = 0;
		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < colSize; j++)
			{
				if (grid[i][j] != 0)
				{
					int tempArea = dfs(grid, i, j);
					maxArea = max(maxArea, tempArea);
				}
			}
		}
		return maxArea;
	}
	int dfs(vector<vector<int>> &grid, int i, int j)
	{
		if (i >= 0 && j >= 0 && i < rowSize && j < colSize && grid[i][j] != 0)
		{
			grid[i][j] = 0;
			return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
		}
		return 0;
	}
};