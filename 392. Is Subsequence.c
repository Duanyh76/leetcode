bool isSubsequence(char* s, char* t) 
{
	int sLength = strlen(s);
	int tLength = strlen(t);
	int sPosition = 0;
	int tPosition = 0;
	while (sPosition != sLength && tPosition != tLength)
	{
		if (s[sPosition] == t[tPosition])
			sPosition++;
		tPosition++;
	}
	if (sPosition == sLength)
		return true;
	return false;
}