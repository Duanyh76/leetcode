class Solution {
public:
	int oldColor;
	int color;
	int rowSize;
	int colSize;
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		oldColor = image[sr][sc];
		color = newColor;
		rowSize = image.size();
		colSize = image[0].size();

		vector<vector<int>> accessImage(rowSize, vector<int>(colSize,0));
		flood(image, accessImage, sr, sc);
		return image;
	}
	void flood(vector<vector<int>> &image, vector<vector<int>> &accessImage, int sr, int sc)
	{
		if (sr < 0 || sc < 0 || sr == rowSize || sc == colSize)
			return;
		if (image[sr][sc] != oldColor || accessImage[sr][sc] == 1)
			return;
		image[sr][sc] = color;
		accessImage[sr][sc] = 1;
		flood(image, accessImage, sr - 1, sc);
		flood(image, accessImage, sr, sc - 1);
		flood(image, accessImage, sr + 1, sc);
		flood(image, accessImage, sr, sc + 1);			
	}
};