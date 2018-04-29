struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
	struct ListNode *fastNode = head;
	struct ListNode *slowNode = head;
	for (int i = 0; i < n; i++)
	{
		if (fastNode->next != NULL)
			fastNode = fastNode->next;
		else
			return head->next;
	}
	while (fastNode->next != NULL)
	{
		fastNode = fastNode->next;
		slowNode = slowNode->next;
	}
	fastNode = slowNode->next;
	slowNode->next = fastNode->next;
	free(fastNode);
	return head;
}