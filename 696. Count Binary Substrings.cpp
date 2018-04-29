class Solution {
public:
	int countBinarySubstrings(string s) {
		int zero = 0;
		int one = 0;
		int count = 0;
		if (s[0] == '0')
			zero++;
		else
			one++;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '0')
			{
				if (s[i - 1] == '0')
				{
					zero++;
					if (zero <= one)
						count++;
				}
				else // s[i-1]=='1'
				{
					count++;
					zero = 1;
				}
			}
			else // s[i]=='1'
			{
				if (s[i - 1] == '1')
				{
					one++;
					if (one <= zero)
						count++;
				}
				else // s[i-1]=='0'
				{
					count++;
					one = 1;
				}
			}
		}
		return count;
	}
};