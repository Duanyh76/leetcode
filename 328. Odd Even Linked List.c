struct ListNode* oddEvenList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *oddHead = malloc(sizeof(struct ListNode));
	struct ListNode *evenHead = malloc(sizeof(struct ListNode));
	oddHead->next = evenHead->next = NULL;
	struct ListNode *oddNode = oddHead;
	struct ListNode *evenNode = evenHead;
	struct ListNode *node = head;
	bool oddFlag = true;;
	while (node != NULL)
	{
		if (oddFlag) // odd
		{
			oddNode->next = node;
			oddNode = oddNode->next;
			oddFlag = false;
		}
		else // even
		{
			evenNode->next = node;
			evenNode = evenNode->next;
			oddFlag = true;
		}
		node = node->next;
	}
	evenNode->next = NULL;
	head = oddHead->next;
	oddNode->next = evenHead->next;
	free(oddHead);
	free(evenHead);
	return head;
}

struct ListNode* oddEvenList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode *oddNode = head;
	struct ListNode *evenNode = head->next;
	struct ListNode *node = head;
	struct ListNode *evenHead = evenNode;
	while (evenNode != NULL&&evenNode->next != NULL)
	{
		oddNode->next = oddNode->next->next;
		evenNode->next = evenNode->next->next;
		oddNode = oddNode->next;
		evenNode = evenNode->next;
	}
	oddNode->next = evenHead;
	return head;
}