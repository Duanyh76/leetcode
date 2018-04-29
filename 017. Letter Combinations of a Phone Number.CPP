class Solution {
public:
	char dict[10][5] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
		{
			vector<string> temp;
			return temp;
		}
		int count = 1;
		for (char num : digits)
		{
			if (num != '7' && num != '9')
				count *= 3;
			else
				count *= 4;
		}
		vector<string> log(count, "");
		for (char num : digits)
		{
			int group;
			if (num == '7' || num == '9')
				group = 4;
			else
				group = 3;
			int index = 0;
			for (int i = 0; i < count; i++)
			{
				log[i] += dict[num - '0'][index];
				index++;
				if (index == group)
					index = 0;
			}
			sort(log.begin(), log.end());
		}
		return log;
	}
};

class Solution {
public:
	char dict[10][5] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	int total[10] = { 0,0,3,3,3,3,3,4,3,4 };
	vector<string> log;
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
			return log;
		vector<int> phone(digits.size());
		recursiveSearch(digits,phone,0);
		return log;
	}
	void recursiveSearch(string digits,vector<int> &phone, int index)
	{
		if (index == digits.size())
		{
			string a = "";
			for (int i = 0; i < digits.size(); i++)
				a += dict[digits[i]-'0'][phone[i]];
			log.push_back(a);
			return;
		}
		for (phone[index] = 0; phone[index] < total[digits[index]-'0']; phone[index]++)
		{
			recursiveSearch(digits, phone,index + 1);
		}
	}
};