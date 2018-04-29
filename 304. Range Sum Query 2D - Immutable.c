typedef struct List
{
	int val;
	struct  List*next;
};

typedef struct List NumList;

typedef struct Matrix
{
	NumList *thisRow;
	struct Matrix *nextRow;
};

typedef struct Matrix NumMatrix;

NumList *numListCreate(int **matrix, int matrixColSize, int thisRow)
{
	NumList *listStart = malloc(sizeof(NumList));
	NumList *node = listStart;
	for (int col = 0; col < matrixColSize; col++)
	{
		node->next = malloc(sizeof(NumList));
		node->next->val = matrix[thisRow][col];
		node = node->next;
	}
	node->next = NULL;
	node = listStart;
	listStart = listStart->next;
	free(node);
	return listStart;
}

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
	NumMatrix *myMatrix = malloc(sizeof(NumMatrix));
	NumMatrix *matrixRow = myMatrix;
	for (int row = 0; row < matrixRowSize; row++)
	{
		matrixRow->nextRow = malloc(sizeof(NumMatrix));
		matrixRow->nextRow->thisRow = numListCreate(matrix, matrixColSize, row);
		matrixRow = matrixRow->nextRow;
	}
	matrixRow = NULL;
	matrixRow = myMatrix;
	myMatrix = myMatrix->nextRow;
	free(matrixRow);
	return myMatrix;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
	int count = 0;
	int row;
	int col;
	for (row = 0; row < row1 - 1; row++)
	{
		obj = obj->nextRow;
	}
	for (; row <= row2; row++)
	{
		for (col = 0; col < col1 - 1; col++)
		{
			obj->thisRow = obj->thisRow->next;
		}
		for (; col <= col2; col++)
		{
			count += obj->thisRow->val;
		}
		obj = obj->nextRow;
	}
	return count;
}

void numListFree(NumList *list)
{
	if (list == NULL)
		return;
	NumList *node = list;
	list = list->next;
	free(node);
	numListFree(list);
}

void numMatrixFree(NumMatrix* obj)
{
	if (obj == NULL)
		return;
	NumMatrix *matrixRow = obj;
	numListFree(matrixRow->thisRow);
	obj = obj->nextRow;
	free(matrixRow);
	numMatrixFree(obj);
}

/**
* Your NumMatrix struct will be instantiated and called as such:
* struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
* int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
* numMatrixFree(obj);
*/