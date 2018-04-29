struct TreeNode *subArrayToBST(int *nums, int startPos, int endPos)
{
	if (startPos > endPos)
		return NULL;
	int midPos = startPos + (endPos - startPos) / 2;
	struct TreeNode *node = malloc(sizeof(struct TreeNode));
	node->val = nums[midPos];
	node->left = subArrayToBST(nums, startPos, midPos - 1);
	node->right = subArrayToBST(nums, midPos + 1, endPos);
	return node;
}

struct TreeNode *sortedArrayToBST(int* nums, int numsSize)
{
	int startPos = 0;
	int endPos = numsSize - 1;
	return subArrayToBST(nums, startPos, endPos);
}