struct ListNode *findPosition(struct ListNode *head, struct ListNode *node)
{
	struct ListNode *checkNode = head;
	while (1)
	{
		if (checkNode->next->val >= node->val)
		{
			break;
		}
		checkNode = checkNode->next;
	}
	return checkNode;
}

struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *node = head; // node is the end of sorted list
	struct ListNode *assistHead = malloc(sizeof(struct ListNode));
	assistHead->val = INT_MIN;
	assistHead->next = head;
	struct ListNode *insertionPosition;
	struct ListNode *nextNode;
	while (node->next != NULL)
	{
		nextNode = node->next;
		if (nextNode->val >= node->val)
		{
			node = nextNode;
		}
		else
		{
			insertionPosition = findPosition(assistHead, nextNode);
			node->next = nextNode->next;
			nextNode->next = insertionPosition->next;
			insertionPosition->next = nextNode;
		}
	}
	head = assistHead->next;
	free(assistHead);
	return head;
}