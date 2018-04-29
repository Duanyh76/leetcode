bool isPalindrome(int x) 
{
	if (x < 0)
		return false;
	if (x < 10)
		return true;
	int copy = x;
	int length = 0;
	while (copy != 0)
	{
		length++;
		copy /= 10;
	}
	char *array = malloc(sizeof(char)*(length + 1));
	array[length] = '\0';
	for (int i = 0; i < length; i++)
	{
		array[length - i - 1] = x % 10;
		x %= 10;
	}
	int position = 0;
	while (position < length / 2)
	{
		if (array[position] != array[length - position - 1])
			return false;
		position++;
	}
	return true;
}

bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	int count = 0;
	int copy = x;
	while (copy != 0)
	{
		count = count * 10 + copy % 10;
		copy /= 10;
	}
	return count == x;
}