int getRealNum(char *s)
{
	int num = 0;
	int symPos = 0;
	int numPos;
	bool negFlag;
	if (s[0] == '-')
	{
		negFlag = true;
		numPos = 1;
		symPos++;
	}
	else
	{
		negFlag = false;
		numPos = 0;
	}
	while (s[symPos] != '+')
		symPos++;

	for (; numPos < symPos; numPos++)
	{
		num *= 10;
		num += s[numPos] - '0';
	}
	if (negFlag)
		num = -num;
	return num;
}

int getCompNum(char *s)
{
	int length = strlen(s);
	int symPos = 1;
	while (s[symPos] != '+')
		symPos++;
	bool negFlag;
	if (s[symPos + 1] == '-')
	{
		negFlag = true;
		symPos++;
	}	
	else
		negFlag = false;
	int numPos = symPos + 1;
	int count = 0;
	for (; numPos < length - 1; numPos++)
	{
		count *= 10;
		count += s[numPos] - '0';
	}
	if (negFlag)
		count = -count;
	return count;
}

int calReal(int a, int b, int c, int d)
{
	return a*c - b*d;
}

int calComp(int a, int b, int c, int d)
{
	return a*d + b*c;
}

int getLength(int a)
{
	if (a == 0)
		return 1;
	a = abs(a);
	int length = 0;
	while (a != 0)
	{
		length++;
		a /= 10;
	}
	return length;
}

char *convertToString(int a, int length)
{
	if (a == 0)
		return "0";
	char *num = malloc(sizeof(int)*(length + 1));
	num[length] = '\0';
	int position = length - 1;
	while (a != 0)
	{
		num[position--] = a % 10 + '0';
		a /= 10;
	}
	return num;
}
char *convertToComplex(int a, int b)
{
	int length = 2;
	if (a < 0)
		length++;
	if (b < 0)
		length++;
	int lengthA = getLength(a);
	int lengthB = getLength(b);
	char *stringA = convertToString(abs(a), lengthA);
	char *stringB = convertToString(abs(b), lengthB);
	length += lengthA + lengthB;
	char *complex = malloc(sizeof(char)*(length + 1));
	complex[length] = '\0';
	complex[length - 1] = 'i';
	int numPos = 0;
	if (a < 0)
	{
		numPos++;
		complex[0] = '-';
	}
	int symPos = numPos + lengthA;
	complex[symPos] = '+';
	if (b < 0)
	{
		complex[++symPos] = '-';
	}
	for (int i = 0; i < lengthA; i++)
	{
		complex[numPos + i] = stringA[i];
	}
	numPos = symPos + 1;
	for (int i = 0; i < lengthB; i++)
	{
		complex[numPos + i] = stringB[i];
	}
	return complex;
}

char* complexNumberMultiply(char* a, char* b)
{
	int aReal, bReal, aComp, bComp;
	aReal = getRealNum(a);
	bReal = getRealNum(b);
	aComp = getCompNum(a);
	bComp = getCompNum(b);
	int answerReal, answerComp;
	answerReal = calReal(aReal, aComp, bReal, bComp);
	answerComp = calComp(aReal, aComp, bReal, bComp);
	char *answer = convertToComplex(answerReal, answerComp);
	return answer;
}