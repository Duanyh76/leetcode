struct ListNode* rotateRight(struct ListNode* head, int k)
{
	if (k == 0)
		return head;
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *node = head;
	struct ListNode *tail;
	int length = 1;
	while (node->next != NULL)
	{
		length++;
		node = node->next;
	}
	k %= length;
	if (k == 0)
		return head;
	tail = node;
	tail->next = head;
	node = head;
	int times = length - k - 1;
	for (int i = 0; i < times; i++)
	{
		node = node->next;
	}
	head = node->next;
	node->next = NULL;
	return head;
}