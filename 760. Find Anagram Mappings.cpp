class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		int size = A.size();
		vector<int> mapping(size);
		for (int i = 0; i < size; i++)
		{
			int key = A[i];
			for (int j = 0; j < size; j++)
			{
				if (B[j] == key)
				{
					mapping[i] = j;
					break;
				}
			}
		}
		return mapping;
	}
};

class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		map<int, int> log;
		int size = A.size();
		vector<int> mapping(size);
		for (int i = 0; i < size; i++)
		{
			log[B[i]] = i;
		}
		for (int i = 0; i < size; i++)
		{
			mapping[i] = log[A[i]];
		}
		return mapping;
	}
};