class Solution {
public:
	int length;
	bool isOneBitCharacter(vector<int>& bits) 
	{
		length = bits.size() - 1;
		return assistOneBitCharacter(bits, 0);
	}
	bool assistOneBitCharacter(vector<int> bits, int index)
	{
		if (index > length)
			return false;
		if (index == length)
		{
			if (bits[index] == 0)
				return true;
			return false;
		}
		if (bits[index] == 0)
		{
			return assistOneBitCharacter(bits, index + 1);
		}
		return assistOneBitCharacter(bits, index + 2);
	}
};

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int length = bits.size();
		int index = 0;
		while (index < length-1)
		{
			if (bits[index] == 0)
				index++;
			else
				index += 2;
		}
		return index == length - 1;
	}
};

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int ones = 0;
		for (int i = bits.size() - 2; i >= 0 && bits[i] != 0; i--)
			ones++;
		if (ones % 2 == 1)
			return false;
		return true;
	}
};