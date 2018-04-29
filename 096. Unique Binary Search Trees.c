int numTrees(int n)
{
	int *treeArray = malloc(sizeof(int) * (n + 1));
	treeArray[0] = 1;
	treeArray[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		treeArray[i] = 0;
		for (int left = 0; left <= i - 1; left++)
		{
			treeArray[i] += treeArray[left] * treeArray[i - left - 1];
		}
	}
	return treeArray[n];
}