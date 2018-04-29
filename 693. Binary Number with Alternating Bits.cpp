class Solution {
public:
	bool hasAlternatingBits(int n) {
		int key = n % 2;
		n /= 2;
		while (n != 0)
		{
			int tail = n % 2;
			if (tail == key)
				return false;
			key = tail;
			n /= 2;
		}
		return true;
	}
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/2) & n+1);
    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n/4) & n-1);
    }
};