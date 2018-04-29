int numDecodings(char* s)
{
	int length = strlen(s);
	if (length == 0 || s[0] == '0')
		return 0;

	int *countArray = malloc(sizeof(int) * (length + 1));
	countArray[0] = countArray[1] = 1;

	for (int i = 1; i < length; i++)
	{
		if (s[i] == '0')
		{
			if (s[i - 1] == '1' || s[i - 1] == '2')
				countArray[i + 1] = countArray[i - 1];
			else
				return 0;
		}
		else if (s[i - 1] == '1' || s[i - 1] == '2')
		{
			if (s[i] <= '6')
			{
				countArray[i + 1] = countArray[i - 1] + countArray[i];
			}
			else if (s[i - 1] == '1')
			{
				countArray[i + 1] = countArray[i - 1] + countArray[i];
			}
			else
			{
				countArray[i + 1] = countArray[i];
			}
		}
		else
		{
			countArray[i + 1] = countArray[i];
		}
	}

	/*for (int i = 1; i < length; i++)
	{
		if (s[i] == '0' && (s[i - 1] >= '3' || s[i - 1] == '0'))
			return 0;
		if (s[i] == '0')
			countArray[i + 1] = countArray[i - 1];
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
			countArray[i + 1] = countArray[i - 1] + countArray[i];
		else
			countArray[i + 1] = countArray[i];
	}*/

	return countArray[length];
}