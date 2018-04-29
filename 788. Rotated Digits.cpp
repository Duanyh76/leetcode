class Solution {
public:
	int rotatedDigits(int N) {
		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			if (isGood(i))
				count++;
		}
		return count;
	}
	bool isGood(int num)
	{
		bool diff = false;
		while (num != 0)
		{
			int temp = num % 10;
			if (temp == 3 || temp == 4 || temp == 7)
				return false;
			if (temp == 2 || temp == 5 || temp == 6 || temp == 9)
				diff = true;
			num /= 10;
		}
		return diff;
	}
};