bool detectCapitalUse(char* word)
{
	int length = strlen(word);
	int flag = 'Z';
	int small = 0;
	int big = 0;
	int key = word[0] - flag <= 0 ? 0 : 1;
	for (int i = 1; i < length; i++)
	{
		if (word[i] - flag <= 0)
			big++;
		else
			small++;
		if (big && small)
			return false;
	}
	if (key&&big)
		return false;
	return true;
}