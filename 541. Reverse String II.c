int min(int a, int b)
{
	return a < b ? a : b;
}

void reverse(char *s, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

char* reverseStr(char* s, int k) 
{
	int length = strlen(s);
	double groups = length / (2.0 * k);
	int times = groups - (int)groups > 0 ? 1 : 0;
	times += (int)groups;
	int start = 0;
	int end;
	for (int i = 0; i < times; i++)
	{
		end = min(start + k - 1, length - 1);
		reverse(s, start, end);
		start += 2 * k;
	}
	return s;
}

char* reverseStr(char* s, int k) 
{
	int length = strlen(s);
	/*double groups = length / (2.0 * k);
	int times = groups - (int)groups > 0 ? 1 : 0;
	times += (int)groups;*/
	int start;
	int end;
	for (start = 0; start < length; start += 2 * k)
	{
		end = min(start + k - 1, length - 1);
		reverse(s, start, end);
	}
	return s;
}