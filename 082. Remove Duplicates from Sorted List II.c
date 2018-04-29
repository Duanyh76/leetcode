struct ListNode* deleteDuplicates(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *node = head->next;
	struct ListNode *deletedNode;
	bool isDuplicated = false;
	while (node != NULL && head->val == node->val)
	{
		isDuplicated = true;
		deletedNode = node;
		node = node->next;
		free(deletedNode);
	}
	if (isDuplicated)
	{
		deletedNode = head;
		head = deleteDuplicates(node);
		free(deletedNode);
	}
	else
	{
		head->next = deleteDuplicates(node);
	}
	return head;
}