class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int size = letters.size();
		if (letters[size - 1] <= target || letters[0]>target)
			return letters[0];
		int front = 0;
		int tail = size - 1;
		int mid;
		while (front<=tail)
		{
			mid = (front + tail) / 2;
			if (letters[mid] > target)
				tail = mid - 1;
			if (letters[mid] <= target)
				front = mid + 1;
		}
		return letters[front];
	}
};