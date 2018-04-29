int countPrimes(int n) 
{
	bool *map = malloc(sizeof(bool)*(n + 1));
	for (int i = 0; i <= n; i++)
	{
		map[i] = false;
	}
	int count = 0;
	int factor = sqrt(n);
	int j;
	for (int i = 2; i <= factor; i++)
	{
		j = 2;
		while (i*j <= n)
		{
			map[i*j] = true;
			j++;
		}
	}
	for (int i = 2; i < n; i++)
	{
		if (map[i] == false)
			count++;
	}
	return count;
}