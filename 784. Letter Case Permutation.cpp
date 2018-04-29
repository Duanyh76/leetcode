class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> log;
		log.push_back(S);
		int size = S.length();
		for (int i = 0; i < size; i++)
		{
			if (S[i] > '9')
			{
				int logSize = log.size();
				int gap;
				if (S[i] > 'Z')
					gap = 'A' - 'a';
				else
					gap = 'a' - 'A';
				for (int j = 0; j < logSize; j++)
				{
					string tmpStr = log[j];
					tmpStr[i] += gap;
					log.push_back(tmpStr);
				}
			}
		}
		return log;
	}
};