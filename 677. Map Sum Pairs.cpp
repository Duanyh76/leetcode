class MapSum {
public:
	map<string, int> log;
	/** Initialize your data structure here. */
	MapSum() {

	}

	void insert(string key, int val) {
		log[key] = val;
	}

	int sum(string prefix) {
		int count = 0;
		bool check = true;
		for (auto it = log.begin(); it != log.end() && check; it++)
		{
			if (match(it->first, prefix,check))
				count += it->second;
		}
		return count;
	}
	bool match(string s, string pre,bool &check)
	{
		if (s.size() < pre.size())
			return false;
		for (int i = 0; i < pre.size(); i++)
		{
			if (s[i] == pre[i])
				continue;
			if (s[i] < pre[i])
			{
				return false;
			}
			if (s[i] > pre[i])
			{
				check = false;
				return false;
			}
		}
		return true;
	}
};