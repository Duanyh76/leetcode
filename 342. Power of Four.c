bool isPowerOfFour(int num)
{
    if (num == 1)
		return true;
    if (num % 4 != 0 || num <= 0)
		return false;
	return isPowerOfFour(num / 4);
}