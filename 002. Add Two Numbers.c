struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry = 0;
	int tempVal;
	struct ListNode *node1 = l1;
	struct ListNode *node2 = l2;
	struct ListNode *returnList;
	int returnListFlag=1;

	while (node1 || node2)
	{
		if (node1 && node2)
		{
			tempVal = node1->val + node2->val + carry;
			node1->val = tempVal % 10;
			node2->val = tempVal % 10;
			node1 = node1->next;
			node2 = node2->next;
		}
		else if (node1)
		{
			tempVal = node1->val + carry;
			node1->val = tempVal % 10;
			returnListFlag = 1;
			node1 = node1->next;
		}
		else
		{
			tempVal = node2->val + carry;
			node2->val = tempVal % 10;
			returnListFlag = 2;
			node2 = node2->next;
		}
		carry = tempVal / 10;
	}

	if (returnListFlag == 1)
		returnList = l1;
	else
		returnList = l2;

	if (carry)
	{
		struct ListNode *newNode = malloc(sizeof(struct ListNode));
		struct ListNode *node = returnList;
		newNode->val = 1;
		newNode->next = NULL;
		while (node->next)
			node = node->next;
		node->next = newNode;
	}

	return returnList;
}