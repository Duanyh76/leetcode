char *subWord(char *s, int begin, int end)
{
	int length = end - begin + 1;
	char *word = malloc(sizeof(char)*(length + 1));
	word[length] = '\0';
	for (int i = 0; i < length; i++)
	{
		word[i] = s[begin - 1 + i];
	}
	return word;
}

int WordInDict(char *word, char **wordDict, int wordDictSize)
{
	for (int i = 0; i < wordDictSize; i++)
	{
		if (strcmp(word, wordDict[i]) == 0)
			return 1;
	}
	return 0;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
	int wordLength = strlen(s);
	int **wordMatrix = malloc(sizeof(int *) * wordLength);
	for (int i = 0; i < wordLength; i++)
	{
		wordMatrix[i] = malloc(sizeof(int)*wordLength);
		for (int j = 0; j < wordLength; j++)
		{
			wordMatrix[i][j] = 0;
		}
	}

	int subWordLength;
	int begin;
	int end;
	int endOfbegin;
	char *tempWord;
	int mid;

	for (subWordLength = 1; subWordLength <= wordLength; subWordLength++)
	{
		endOfbegin = wordLength - subWordLength + 1;
		for (begin = 1; begin <= endOfbegin; begin++)
		{
			end = begin + subWordLength - 1;
			tempWord = subWord(s, begin, end);
			if (WordInDict(tempWord, wordDict, wordDictSize))
			{
				wordMatrix[begin - 1][end - 1] = 1;
			}
			else
			{
				for (mid = begin; mid < end; mid++)
				{
					if (wordMatrix[begin - 1][mid - 1] && wordMatrix[mid][end - 1])
					{
						wordMatrix[begin - 1][end - 1] = 1;
					}
				}
			}
		}
	}
	return wordMatrix[0][wordLength - 1];
}