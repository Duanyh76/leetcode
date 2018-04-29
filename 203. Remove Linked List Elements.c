struct ListNode* removeElements(struct ListNode* head, int val)
{
	while (head && head->val == val)
	{
		head = head->next;
	}
	struct ListNode *node = head;
	while (node && node->next != NULL)
	{
		if (node->next->val == val)
			node->next = node->next->next;
		else
			node = node->next;
	}
	return head;
}

struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}