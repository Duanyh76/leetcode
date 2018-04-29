class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<int> log(26, 0);
		int index;
		for (char a : licensePlate)
		{
			if (!((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z')))
				continue;
            if (a <= 'Z')
			{
				index = a - 'A';
				log[index]++;
			}
			else
			{
				index = a - 'a';
				log[index]++;
			}
		}
		int minLength = INT_MAX;
		int size = words.size();
		for (int i=0;i<size;i++)
		{
			if (match(log, words[i]))
			{
				if (words[i].size() < minLength)
				{
					index = i;
					minLength = words[i].size();
				}
			}
		}
		return words[index];
	}
	bool match(vector<int> log, string str)
	{
		int index;
		for (char a : str)
		{
			if (a <= 'Z')
			{
				index = a - 'A';
			}
			else
			{
				index = a - 'a';
			}
			if (log[index] > 0)
				log[index]--;
		}
		for (int i = 0; i < 26; i++)
		{
			if (log[i] > 0)
				return false;
		}
		return true;
	}
};