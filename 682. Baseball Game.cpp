class Solution {
public:
	int calPoints(vector<string>& ops) {
		int size = ops.size();
		vector<pair<int,int>> log(size+1);
		for (int i = 0; i < size; i++)
		{
			int logIndex = i + 1;
			if (ops[i] == "+")
			{
				int valid1;
				int valid2;
				valid1 = i - 1;
				while (valid1>=0&&ops[valid1] == "C")
					valid1--;
				valid2 = valid1-1;
				while (valid2>=0&&ops[valid2] == "C")
					valid2--;

				log[logIndex].first = log[valid1 + 1].first + log[valid2 + 1].first;
				log[logIndex].second = log[logIndex - 1].second + log[logIndex].first;
			}
			else if (ops[i] == "C")
			{
				int validIndex = i - 1;
				while (validIndex>=0&&ops[validIndex] == "C")
					validIndex--;
				ops[validIndex] = "C";
				log[logIndex].second = log[logIndex - 1].second - log[validIndex + 1].first;
			}
			else if (ops[i] == "D")
			{
				int validIndex = i - 1;
				while (validIndex >= 0 && ops[validIndex] == "C")
					validIndex--;
				log[logIndex].first = 2 * log[validIndex + 1].first;
				log[logIndex].second = log[logIndex - 1].second + log[logIndex].first;
			}
			else
			{
				int num = stoi(ops[i]);
				log[logIndex].first = num;
				log[logIndex].second = log[logIndex - 1].second + log[logIndex].first;
			}
		}
		return log[size].second;
	}
};