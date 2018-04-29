struct ListNode* reverseList(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *first = head;
	struct ListNode *second = first->next;
	struct ListNode *third = second->next;
	head->next = NULL;
	struct ListNode *newHead;
	while (third != NULL)
	{
		second->next = first;
		first = second;
		second = third;
		third = third->next;
	}
	newHead = second;
	newHead->next = first;
	return newHead;
}

struct ListNode* reverseList(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *newHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}