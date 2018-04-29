struct ListNode *reverse(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *newHead = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

void reorderList(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return head;
	struct ListNode *slowNode = head;
	struct ListNode *fastNode = head;
	while (fastNode != NULL&&fastNode->next != NULL)
	{
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
	}
	struct ListNode *newHead = reverse(slowNode->next);
	slowNode->next = NULL;
	struct ListNode *smallNode = head;
	struct ListNode *bigNode = newHead;
	struct ListNode *assistNode;
	while (bigNode != NULL)
	{
		assistNode = bigNode->next;
		bigNode->next = smallNode->next;
		smallNode->next = bigNode;
		smallNode = bigNode->next;
		bigNode = assistNode;
	}
}