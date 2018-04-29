char* convert(char* s, int numRows)
{
	if (numRows == 1)
		return s;

	int length = strlen(s);
	char *zigzag = malloc(sizeof(char) * (length + 1));
	zigzag[length] = '\0';

	int groupSize = 2 * numRows - 2;
	int stringPosition = 0;
	int zigzagPosition = 0;
	int midPosition;

	for (int stringStartPosition = 0; stringStartPosition < numRows; stringStartPosition++)
	{
		stringPosition = stringStartPosition;
		while (stringPosition < length)
		{
			zigzag[zigzagPosition++] = s[stringPosition];
			stringPosition += groupSize;
			midPosition = stringPosition - 2 * stringStartPosition;
			if (midPosition < length && stringStartPosition != 0 && stringStartPosition != numRows - 1)
				zigzag[zigzagPosition++] = s[midPosition];
		}
	}

	/*for (int i = 0; i < numRows; i++)
	{
		for (int j = i; j < length; j += step)
		{
			re[index++] = s[j];
			int pos = j + step - 2 * i;
			if (i != 0 && i != numRows - 1 && pos < length)
			{
				re[index++] = s[pos];
			}
		}
	}*/
	
	return zigzag;
}