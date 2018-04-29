int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
	int count = 0;
	qsort(g, gSize, sizeof(int), cmp);
	qsort(s, sSize, sizeof(int), cmp);
	int i = 0;
	int j = 0;
	while (i < gSize && j < sSize)
	{
		if (g[i] <= s[j])
		{
			count++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	return count;
}