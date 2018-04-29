double myPow(double x, int n)
{
	if (n == INT_MIN)
		return myPow(1 / x, INT_MAX) / x;
	if (x == 1 || n == 0)
		return 1;
	if (n < 0)
		return myPow(1 / x, -n);
	double factor = myPow(x, n / 2);
	return n % 2 == 0 ? factor*factor : factor*factor*x;
}