char* longestPalindrome(char* s)
{
	if (s == NULL)
		return "";
	int length = strlen(s);
	if (length == 1)
		return s;
	bool **palindromeMatrix = malloc(sizeof(bool*)*length);
	for (int i = 0; i < length; i++)
	{
		palindromeMatrix[i] = malloc(sizeof(bool)*length);
		for (int j = 0; j <= i; j++)
		{
			palindromeMatrix[i][j] = true;
		}
		for (int j = i + 1; j < length; j++)
		{
			palindromeMatrix[i][j] = false;
		}
	}
	
	int startPos;
	int endPos;
	int endOfStartPos;
	int palindromeLength;
	int maxLength = 1;
	int palindromeStart = 0;
	int palindromeEnd = 0;

	for (palindromeLength = 2; palindromeLength <= length; palindromeLength++)
	{
		endOfStartPos = length - palindromeLength;
		for (startPos = 0; startPos <= endOfStartPos; startPos++)
		{
			endPos = startPos + palindromeLength - 1;
			if (s[startPos] == s[endPos]
				&& palindromeMatrix[startPos + 1][endPos - 1] == true)
			{
				palindromeMatrix[startPos][endPos] = true;
				if (maxLength < palindromeLength)
				{
					maxLength = palindromeLength;
					palindromeStart = startPos;
					palindromeEnd = endPos;
				}
			}
		}
	}
	s[palindromeEnd + 1] = '\0';
	s = s + palindromeStart;
	return s;
}