int mySqrt(int x)
{
	int start = 1;
	int end = x;
	int mid = 0;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (x / mid < mid)
		{
			end = mid - 1;
		}
		else if (x / (mid + 1) < (mid + 1))
		{
			return mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return mid;
}