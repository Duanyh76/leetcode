class MagicDictionary {
public:
	vector<string> magicDict;
	/** Initialize your data structure here. */
	MagicDictionary() {

	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (string s : dict)
			magicDict.push_back(s);
	}

	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		int length = word.size();
		for (string s : magicDict)
		{
			if (length == s.size())
			{
				if (check(word, s))
					return true;
			}
		}
		return false;
	}

	bool check(string word, string s)
	{
		int count = 0;
		int length = word.size();
		for (int i = 0; i < length; i++)
		{
			if (word[i] != s[i])
			{
				if (count == 0)
					count++;
				else
					return false;
			}
		}
		if (count == 0)
			return false;
		return true;
	}
};

/**
* Your MagicDictionary object will be instantiated and called as such:
* MagicDictionary obj = new MagicDictionary();
* obj.buildDict(dict);
* bool param_2 = obj.search(word);
*/