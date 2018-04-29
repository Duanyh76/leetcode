class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < col; i++)
		{
			int key = matrix[0][i];
			for (int j = 1; j < row && i + j < col; j++)
			{
				if (matrix[j][i + j] != key)
					return false;
			}
		}
		for (int i = 1; i < row; i++)
		{
			int key = matrix[i][0];
			for (int j = 1; j < col && i + j < row; j++)
				if (matrix[i + j][j] != key)
					return false;
		}
		return true;
	}
};

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 1; i < row; i++)
		{
			for (int j = 1; j < col; j++)
			{
				if (matrix[i][j] != matrix[i - 1][j - 1])
					return false;
			}
		}
		return true;
	}
};