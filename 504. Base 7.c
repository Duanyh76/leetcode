char* convertToBase7(int num)
{
	if (num == 0)
		return "0";
	int isPositive = num > 0 ? 1 : 0;
	num = abs(num);
	int length = 0;
	int base = 1;
	while (base <= num)
	{
		base *= 7;
		length++;
	}
	base /= 7;
	char *sevenBits = malloc(sizeof(char)*(length + 2));
	sevenBits[length + 1] = '\0';
	sevenBits[0] = '-';
	for (int i = 0; i < length; i++)
	{
		sevenBits[i + 1] = num / base + '0';
		num %= base;
		base /= 7;
	}
	if (isPositive)
	{
		sevenBits++;
	}
	return sevenBits;
}