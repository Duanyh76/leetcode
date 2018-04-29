int max(int a, int b)
{
	return a > b ? a : b;
}

bool match(char *s, char *d)
{
	int sLength = strlen(s);
	int dLength = strlen(d);
	int sPosition = 0;
	int dPosition = 0;
	while (sPosition < sLength && dPosition < dLength)
	{
		if (s[sPosition] == d[dPosition])
			dPosition++;
		sPosition++;
	}
	return dLength == dPosition;
}


char* findLongestWord(char* s, char** d, int dSize)
{
	int *validArray = malloc(sizeof(int)*dSize);
	for (int i = 0; i < dSize; i++)
	{
		validArray[i] = 0;
		if (match(s, d[i]))
		{
			validArray[i] = strlen(d[i]);
		}
	}
	int position;
	int maxLength = 0;
	for (int i = 0; i < dSize; i++)
	{
		maxLength = max(maxLength, validArray[i]);
	}
	if (maxLength == 0)
		return "";
	for (int i = 0; i < dSize; i++)
	{
		if (validArray[i] == maxLength)
		{
			position = i;
			break;
		}
	}
	for (int i = position + 1; i < dSize; i++)
	{
		if (validArray[i] == maxLength)
		{
			if (strcmp(d[i], d[position]) == -1)
			{
				position = i;
			}
		}
	}
	return d[position];
}