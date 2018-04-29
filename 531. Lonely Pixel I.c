int findLonelyPixel(char** picture, int pictureRowSize, int pictureColSize)
{
	int sum = 0;
	for (int row = 0; row < pictureRowSize; row++)
	{
		for (int col = 0; col < pictureColSize; col++)
		{
			if (picture[row][col] == 'B')
			{
				int count = 0;
				int i;
				int j;
				for (i = 0; i < pictureColSize && count < 2; i++)
				{
					count += picture[row][i] == 'B';
				}
				if (count == 2)
					break;
				count = 0;
				for (j = 0; j < pictureRowSize && count < 2; j++)
				{
					count += picture[j][col] == 'B';
				}
				if (count == 1)
					sum++;
			}
		}
	}
	return sum;
}