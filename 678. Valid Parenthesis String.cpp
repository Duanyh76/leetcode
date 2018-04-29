class Solution {
public:
	bool checkValidString(string s) {
		stack<int> star;
		stack<int> left;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '*')
				star.push(i);
			if (s[i] == '(')
				left.push(i);
			if (s[i] == ')')
			{
				if (star.empty() && left.empty())
					return false;
				if (left.empty())
					star.pop();
				else
					left.pop();
			}
		}
		while (!left.empty())
		{
			if (star.empty())
				return false;
			if (left.top() > star.top())
				return false;
			left.pop();
			star.pop();
		}
		return true;
	}
};