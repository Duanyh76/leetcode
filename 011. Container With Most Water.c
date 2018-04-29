int max(int a, int b)
{
	return a > b ? a : b;
}

int maxArea(int* height, int heightSize) 
{
	int tempArea;
	int theMaxArea = 0;
	int leftPosition = 0;
	int rightPosition = heightSize - 1;
	int length;
	while (leftPosition < rightPosition)
	{
		length = rightPosition - leftPosition;
		if (height[leftPosition] < height[rightPosition])
		{
			tempArea = length * height[leftPosition];
			leftPosition++;
		}
		else
		{
			tempArea = length * height[rightPosition];
			rightPosition--;
		}
		theMaxArea = max(theMaxArea, tempArea);
	}
	return theMaxArea;
}