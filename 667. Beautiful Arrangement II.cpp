class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> log(n);
		int head = 1;
		int tail = n;
		int i;
		k++;
		for (i = 0; i < n&&k != 1; i++)
		{
			if (k % 2)
			{
				log[i] = head++;
			}
			else
			{
				log[i] = tail--;
			}
			k--;
		}
		if (log[i - 1] == head - 1)
		{
			for (; i < n; i++)
				log[i] = head++;
		}
		else
		{
			for (; i < n; i++)
				log[i] = tail--;
		}
		return log;
	}
};