struct ListNode *reverse(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *newHead = reverse(head->next);;
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
	struct ListNode *assistHead = malloc(sizeof(struct ListNode));
	struct ListNode *assistTail = malloc(sizeof(struct ListNode));
	assistHead->next = head;
	struct ListNode *node;
	struct ListNode *preNode = assistHead;
	for (int i = 1; i < m; i++)
	{
		preNode = preNode->next;
	}
	node = preNode->next;
	for (int i = m; i < n; i++)
	{
		node = node->next;
	}
	assistTail->next = node->next;
	node->next = NULL;
	node = reverse(preNode->next);
	preNode->next = node;
	for (int i = m; i < n; i++)
	{
		node = node->next;
	}
	node->next = assistTail->next;
	head = assistHead->next;
	free(assistHead);
	free(assistTail);
	return head;
}