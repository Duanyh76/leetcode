class Solution {
public:
	int numJewelsInStones(string J, string S) {
		set<char> log;
		for (char c : J)
		{
			log.insert(c);
		}
		int count = 0;
		for (char c : S)
		{
			if (log.find(c)!=log.end())
				count++;
		}
		return count;
	}
};