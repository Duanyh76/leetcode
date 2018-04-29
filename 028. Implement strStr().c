int strStr(char* haystack, char* needle) 
{
	int hayLength = strlen(haystack);
	int needleLength = strlen(needle);
	if (needleLength == 0)
		return 0;
	int endOfPosition = hayLength - needleLength + 1;
	for (int position = 0; position < endOfPosition; position++)
	{
		if (haystack[position] == needle[0])
		{
			bool match = true;
			for (int subPosition = 0; subPosition < needleLength; subPosition++)
			{
				if (haystack[position + subPosition] != needle[subPosition])
				{
					match = false;
					break;
				}
			}
			if (match)
				return position;
		}
	}
	return -1;
}