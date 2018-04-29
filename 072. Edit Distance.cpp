class Solution {
public:
	int minDistance(string word1, string word2) {
		int length1 = word1.size();
		int length2 = word2.size();
		if (length1*length2 == 0)
			return length1 + length2;

		vector<vector<int>> matrix(length1 + 1, vector<int>(length2 + 1));
		for (int i = 0; i <= length1; i++)
			matrix[i][0] = i;
		for (int i = 0; i <= length2; i++)
			matrix[0][i] = i;
		for (int i = 1; i <= length1; i++)
		{
			for (int j = 1; j <= length2; j++)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					matrix[i][j] = matrix[i - 1][j - 1];
				}
				else
				{
					matrix[i][j] = min({ matrix[i - 1][j - 1],matrix[i - 1][j],matrix[i][j - 1] }) + 1;
				}
			}
		}
		return matrix[length1][length2];
	}
};