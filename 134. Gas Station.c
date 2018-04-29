int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) 
{
	int count = 0;
	for (int i = 0; i < gasSize; i++)
	{
		count += gas[i] - cost[i];
		gas[i] -= cost[i];
	}
	if (count < 0)
		return -1;
	int startPosition = 0;
	int endPositon;
	while (startPosition < gasSize)
	{
		if (gas[startPosition] < 0)
		{
			startPosition++;
		}
		else
		{
			count = 0;
			for (endPositon = startPosition; endPositon < gasSize && count >= 0; endPositon++)
			{
				count += gas[endPositon];
			}
			if (count < 0)
			{
				startPosition = endPositon;
			}
			else
			{
				return startPosition;
			}
		}
	}
	return -1;
}