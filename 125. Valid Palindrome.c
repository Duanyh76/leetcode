bool isPalindrome(char* s) 
{
	int length = strlen(s);
	int leftPos = 0;
	int rightPos = length - 1;
	while (leftPos < rightPos)
	{
		if (!((s[leftPos] >= '0'&&s[leftPos] <= '9') || (s[leftPos] >= 'a'&&s[leftPos] <= 'z') || (s[leftPos] >= 'A'&&s[leftPos] <= 'Z')))
		{
			leftPos++;
			continue;
		}
		if (!((s[rightPos] >= '0'&&s[rightPos] <= '9') || (s[rightPos] >= 'a'&&s[rightPos] <= 'z') || (s[rightPos] >= 'A'&&s[rightPos] <= 'Z')))
		{
			rightPos--;
			continue;
		}

		if (s[leftPos] <= 'Z')
			;
		else
			s[leftPos] -= 'a' - 'A';
		if (s[rightPos] <= 'Z')
			;
		else
			s[rightPos] -= 'a' - 'A';

		if (s[leftPos] != s[rightPos])
			return false;
		leftPos++;
		rightPos--;
	}
	return true;
}