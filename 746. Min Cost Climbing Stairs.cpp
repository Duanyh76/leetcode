class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int size = cost.size();
		vector<int> log(size, 0);
		log[0] = cost[0];
		log[1] = cost[1];
		for (int i = 2; i < size; i++)
		{
			log[i] = min(log[i - 1], log[i - 2]) + cost[i];
		}
		return min(log[size - 1], log[size - 2]);
	}
};