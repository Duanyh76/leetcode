class Solution {
public:
	int maximumSwap(int num) {
		string s = to_string(num);
		int size = s.size();
		for(int head=0;head<size;head++)
		{
			int pos = size - 1;
			for (int tail = size - 2; tail > head; tail--)
			{
				if (s[tail] > s[pos])
					pos = tail;
			}
			if (s[pos] > s[head])
			{
				char temp = s[pos];
				s[pos] = s[head];
				s[head] = temp;
				break;
			}
		}
		int res = stoi(s);
		return res;
	}
};