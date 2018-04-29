class Solution {
public:
	string toHex(int num) {
		long long longNum = num;
		if (num < 0)
			longNum = 0x100000000 + num;
		return longToHex(longNum);
	}
	string longToHex(long long num)
	{
		string hex;
		long long flag = 1;
		long long key;
		char c;
		while (flag <= num)
			flag *= 16;
		flag /= 16;
		while (flag != 0)
		{
			key = num / flag;
			if (key <= 9)
				c = '0' + key;
			else
				c = 'a' + key - 10;
			hex.push_back(c);
			num %= flag;
			flag /= 16;
		}
		if (hex.empty())
			hex = "0";
		return hex;
	}
};