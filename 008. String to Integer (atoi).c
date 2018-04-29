int myAtoi(char* str)
{
	int length = strlen(str);
	long myInteger = 0;
	bool IsNegtive = false;
	int i = 0;

	while (str[i] == ' ')
	{
		i++;
	}

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			IsNegtive = true;
		i++;
	}
	
	for (; i < length; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		if (str[i] == '0' && myInteger == 0)
			continue;
		myInteger *= 10;
		myInteger += str[i] - '0';

		if (myInteger > INT_MAX)
		{
			if (IsNegtive)
				return INT_MIN;
			else
				return INT_MAX;
		}
	}
	if (IsNegtive)
		myInteger = -myInteger;
	return myInteger;
}