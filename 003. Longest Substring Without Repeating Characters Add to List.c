int max(int a, int b)
{
	return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s)
{
	int length = strlen(s);
	int hashMap[128] = { 0 };
	int startPos = 0;
	int endPos = 0;
	int maxCount = 0;

	while (endPos != length)
	{
		if (hashMap[s[endPos]] == 1)
		{

			for (int i = startPos; i < endPos; i++)
			{
				hashMap[s[i]] = 0;
				startPos = i;
				if (s[i] == s[endPos])
					break;
			}
			hashMap[s[endPos]] = 1;
			startPos++;
		}
		else
		{
			hashMap[s[endPos]] = 1;
		}
		maxCount = max(maxCount, endPos - startPos + 1);
		endPos++;
	}
	return maxCount;
}
