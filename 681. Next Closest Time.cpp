class Solution {
public:
	int a, b, c, d;
	string theTime;
	int minNum;
	string nextClosestTime(string time) {
		theTime = time;
		a = time[0] - '0';
		b = time[1] - '0';
		c = time[3] - '0';
		d = time[4] - '0';
		minNum = min({ a,b,c,d });

		return core(4);
	}
	string core(int index)
	{
		int minMax = keyNum(index);
		switch (index) 
		{
			case(-1):
			{
				string time;
				time += minNum + '0';
				time += minNum + '0';
				time += ":";
				time += minNum + '0';
				time += minNum += '0';
				return time;
			}
			case 0:
			{
				if (minMax > 2)
					return core(-1);
				else
				{
					string time;
					time += minMax + '0';
					time += minNum + '0';
					time += ":";
					time += minNum + '0';
					time += minNum += '0';
					return time;
				}
			}
			case 1:
			{
				
				if (theTime[0] - '0' < 2)
				{
					if (minMax > 9)
						return core(0);
				}
				else
				{
					if (minMax > 4)
						return core(0);
				}
				
				string time;
				time += theTime[0];
				time += minMax + '0';
				time += ":";
				time += minNum + '0';
				time += minNum += '0';
				return time;
			}
			case 3:
			{
				if (minMax > 5)
					return core(1);
				else
				{
					string time;
					time += theTime[0];
					time += theTime[1];
					time += ":";
					time += minMax + '0';
					time += minNum += '0';
					return time;
				}
			}
			case 4:
			{
				if (minMax > 9)
					return core(3);
				else
				{
					string time;
					time += theTime[0];
					time += theTime[1];
					time += ":";
					time += theTime[3];
					time += minMax += '0';
					return time;
				}
			}	
		}
		return theTime;
	}
	int keyNum(int index)
	{
		if (index == -1)
			return 0;
		int minMax = 10;
		if (a > theTime[index] - '0')
			minMax = min(a, minMax);
		if (b > theTime[index] - '0')
			minMax = min(b, minMax);
		if (c > theTime[index] - '0')
			minMax = min(c, minMax);
		if (d > theTime[index] - '0')
			minMax = min(d, minMax);
		return minMax;
	}
};