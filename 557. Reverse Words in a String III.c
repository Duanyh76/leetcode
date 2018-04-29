void reverseSingleWord(char *s, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

int findEnd(char *s, int startPos)
{
	int length = strlen(s);
	int endPos = length - 1;
	for (int i = startPos; i < length; i++)
	{
		if (s[i + 1] == ' ')
		{
			endPos = i;
			break;
		}
	}
	return endPos;
}

char* reverseWords(char* s) 
{
	int length = strlen(s);
	int startPos = 0;
	int endPos;
	while (startPos!=length+1)
	{
		endPos = findEnd(s, startPos);
		reverseSingleWord(s, startPos, endPos);
		startPos = endPos + 2;
	}
	return s;
}
