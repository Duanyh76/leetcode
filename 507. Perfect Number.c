bool checkPerfectNumber(int num)
{
    if (num <= 1)
		return false;
	int size = sqrt(num);
	int *numArray = malloc(sizeof(int)*(size+1));
	for (int i = 0; i <= size; i++)
	{
		numArray[i] = 0;
	}
	int index = 1;
	int divisor;
	while (numArray[index] == 0 && index <= size)
	{
		divisor = num / index;
		if (index*divisor == num)
		{
			numArray[index] = 1;
		}
		index++;
	}
	int count = 1;
	for (int i = 2; i <= size; i++)
	{
		if (numArray[i] == 1)
		{
			count += i;
			count += (num / i);
		}
	}
	return count == num;
}