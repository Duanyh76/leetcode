struct ListNode* partition(struct ListNode* head, int x)
{
	struct ListNode *smallHead = malloc(sizeof(struct ListNode));
	struct ListNode *biggerHead = malloc(sizeof(struct ListNode));
	struct ListNode *node = head;
	struct ListNode *smallNode = smallHead;
	struct ListNode *biggerNode = biggerHead;
	while (node != NULL)
	{
		if (node->val < x)
		{
			smallNode->next = node;
			smallNode = smallNode->next;
		}
		else
		{
			biggerNode->next = node;
			biggerNode = biggerNode->next;
		}
		node = node->next;
	}
	biggerNode->next = NULL;
	smallNode->next = biggerHead->next;
	head = smallHead->next;
	free(smallHead);
	free(biggerHead);
	return head;
}