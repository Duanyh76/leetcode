struct NumArray 
{
	int val;
	struct NumArray *next;
};

/** Initialize your data structure here. */

struct NumArray *NumArrayCreate(int *nums, int numsSize)
{
	struct NumArray *array = malloc(sizeof(struct NumArray));
	struct NumArray *node = array;
	for (int i = 0; i < numsSize; i++)
	{
		node->next = malloc(sizeof(struct NumArray));
		node->next->val = nums[i];
		node = node->next;
	}
	node->next = NULL;
	node = array;
	array = array->next;
	free(node);
	return array;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	int count = 0;
	int pos;
	struct NumArray *node = numArray;
	for (pos = 0; pos < i; pos++)
	{
		node = node->next;
	}
	for (; pos <= j; pos++)
	{
		count += node->val;
		node = node->next;
	}
	return count;
}

/** Deallocates memory previously allocated for the data structure. */

void NumArrayFree(struct NumArray* numArray) {
	if (!numArray)
		return;
	struct NumArray *node = numArray->next;
	free(numArray);
	NumArrayFree(node);
}