class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int row = M.size();
		int col = M[0].size();
		vector<vector<int>> matrix(row, vector<int>(col));
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = getSmooth(M, i, j);
			}
		}
		return matrix;
	}
	int getSmooth(vector<vector<int>> m, int x, int y)
	{
		int row = m.size();
		int col = m[0].size();
		int res = 0;
		int count = 0;
		for (int i = -1; i <=1; i++)
		{
			for (int j = -1; j <=1; j++)
			{
				if ((x + i >= 0 && x + i < row) && (y + j >= 0 && y + j < col))
				{
					res += m[x + i][y + j];
					count++;
				}
			}
		}
		res /= count;
		return res;
	}
};