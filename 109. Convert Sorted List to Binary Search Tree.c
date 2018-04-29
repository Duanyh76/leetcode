struct TreeNode *assistListToBST(struct ListNode *head, int length)
{
	if (head == NULL || length == 0)
		return NULL;
	int midPosition = length / 2;
	struct ListNode *node = head;
	for (int i = 0; i < midPosition; i++)
	{
		node = node->next;
	}
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->val = node->val;
	root->left = assistListToBST(head, midPosition);
	root->right = assistListToBST(node->next, length - midPosition - 1);
	return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) 
{
	if (head == NULL)
		return NULL;
	int length = 0;
	struct ListNode *node = head;
	while (node != NULL)
	{
		length++;
		node = node->next;
	}
	return assistListToBST(head, length);
}