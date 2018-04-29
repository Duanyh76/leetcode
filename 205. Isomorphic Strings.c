bool isIsomorphic(char* s, char* t) 
{
	int length = strlen(s);
	int *map = malloc(sizeof(int) * 128);
	for (int i = 0; i < 128; i++)
	{
		map[i] = -1;
	}
	for (int i = 0; i < length; i++)
	{
		if (map[s[i]] == -1)
			map[s[i]] = t[i];
		else if (map[s[i]] != t[i])
			return false;
	}
	for (int i = 0; i < 128; i++)
	{
		map[i] = -1;
	}
	for (int i = 0; i < length; i++)
	{
		if (map[t[i]] == -1)
			map[t[i]] = s[i];
		else if (map[t[i]] != s[i])
			return false;
	}
	return true;
}

bool isIsomorphic(char* s, char* t) 
{
	int length = strlen(s);
	int *mapS = malloc(sizeof(int) * 128);
	int *mapT = malloc(sizeof(int) * 128);
	for (int i = 0; i < 128; i++)
	{
		mapS[i] = -1;
		mapT[i] = -1;
	}
	for (int i = 0; i < length; i++)
	{
		if (mapS[s[i]] != mapT[t[i]])
			return false;
		mapS[s[i]] = i;
		mapT[t[i]] = i;
	}
	return true;
}