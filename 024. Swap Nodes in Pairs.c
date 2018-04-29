struct ListNode* swapPairs(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *node = head->next;
	node->next = swapPairs(node->next);
	head->next = node->next;
	node->next = head;
	return node;
}