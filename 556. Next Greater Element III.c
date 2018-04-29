int min(int a, int b)
{
	return a<b ? a : b;
}
int getLength(int n)
{
	int length = 0;
	while (n)
	{
		length++;
		n /= 10;
	}
	return length;
}

void myitoa(int n, char *s, int length)
{
	for (int i = length - 1; i >= 0; i--)
	{
		s[i] = n % 10 + '0';
		n /= 10;
	}
	return s;
}

void sort(char *s)
{
	int length = strlen(s);
	char temp;
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (s[i] > s[j])
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}

int nextGreaterElement(int n)
{
	int nLength = getLength(n);
	char *s = malloc(sizeof(char)*(nLength + 1));
	s[nLength] = '\0';
	myitoa(n, s, nLength);
	int length = strlen(s);
	int keyPos = 0;
	for (int i = length - 1; i > 0; i--)
	{
		if (s[i] <= s[i - 1])
		{
			continue;
		}
		else
		{
			keyPos = i;
			break;
		}
	}
	if (keyPos == 0)
	{
		return -1;
	}
	char minNum = '9';
	for (int i = keyPos; i < length; i++)
	{
		if (s[i]>s[keyPos - 1])
			minNum = min(minNum, s[i]);
	}
	int swapPos;
	for (int i = keyPos; i < length; i++)
	{
		if (minNum == s[i])
		{
			swapPos = i;
			break;
		}
	}
	char temp;
	temp = s[keyPos - 1];
	s[keyPos - 1] = s[swapPos];
	s[swapPos] = temp;
	sort(s + keyPos);
	long long a = atol(s);
	if (a >= INT_MAX)
		return -1;
	return (int)a;
}