class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		int count = 0;
		for (int i = L; i <= R; i++)
		{
			if (hasPrime(i))
				count++;
		}
		return count;
	}
	bool hasPrime(int num)
	{
		int ones = 0;
		while (num > 0)
		{
			if (num % 2 == 1)
				ones++;
			num /= 2;
		}
		return isPrime(ones);
	}
	bool isPrime(int num)
	{
		if (num <= 1)
			return false;
		int flag = sqrt(num);
		for (int i = 2; i <= flag; i++)
		{
			if (num%i == 0)
				return false;
		}
		return true;;
	}
};

class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		set<int> primes{ 2,3,5,7,11,13,17,19,23,29 };
		int count = 0;
		for (int i = L; i <= R; i++)
		{
			int bits = 0;
			int num = i;
			while (num != 0)
			{
				if (num % 2 == 1)
					bits++;
				num /= 2;
			}
			count += primes.count(bits);
		}
		return count;
	}
};