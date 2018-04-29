class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int count = 0;
		int size = points.size();
		for (int i = 0; i < size; i++)
		{
			map<int, int> distanceMap;
			for (int j = 0; j < size; j++)
			{
				int distance = getDis(points[i].first, points[i].second, points[j].first, points[j].second);
				distanceMap[distance]++;
			}
			for (auto it = distanceMap.begin(); it != distanceMap.end(); it++)
			{
				int num = it->second;
				int tempCount = num * (num - 1);
				count += tempCount;
			}
		}
		return count;
	}
	int getDis(int x1, int y1, int x2, int y2)
	{
		int x = x1 - x2;
		int y = y1 - y2;
		return x * x + y * y;
	}
};