class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> numbers;
		for (int i = left; i <= right; i++)
		{
			if (selfDividing(i))
				numbers.push_back(i);
		}
		return numbers;
	}
	bool selfDividing(int num)
	{
		int copy = num;
		int key;
		while (copy != 0)
		{
			key = copy % 10;
			if (key == 0)
				return false;
			if (num%key != 0)
				return false;
			copy /= 10;
		}
		return true;
	}
};