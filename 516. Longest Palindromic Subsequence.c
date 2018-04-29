int max(int a, int b)
{
	return a > b ? a : b;
}

int longestPalindromeSubseq(char* s) 
{
	int length = strlen(s);
	int **palindromeArray = malloc(sizeof(int*)*(length + 1));
	for (int i = 0; i <= length; i++)
	{
		palindromeArray[i] = malloc(sizeof(int)*(length + 1));
		for (int j = 0; j <= length; j++)
		{
			palindromeArray[i][j] = 0;
		}
		palindromeArray[i][i] = 1;
	}

	int stringLength;
	int startPos;
	int endOfStartPos;
	int endPos;
	int tempLength;
	
	for (stringLength = 2; stringLength <= length; stringLength++)
	{
		endOfStartPos = length - stringLength + 1;
		for (startPos = 1; startPos <= endOfStartPos; startPos++)
		{
			endPos = startPos + stringLength - 1;
			palindromeArray[startPos][endPos] = 1;
			if (s[endPos - 1] == s[startPos - 1])
			{
				palindromeArray[startPos][endPos] = 2 + palindromeArray[startPos + 1][endPos - 1];
			}
			else
			{
				tempLength = max(palindromeArray[startPos + 1][endPos],
					palindromeArray[startPos][endPos - 1]);
				palindromeArray[startPos][endPos] = max(palindromeArray[startPos][endPos], tempLength);
			}
		}
	}

	return palindromeArray[1][length];
}