struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
	if (headA == NULL || headB == NULL)
		return NULL;
	struct ListNode *nodeA = headA;
	struct ListNode *nodeB = headB;
	int lengthA = 0;
	int lengthB = 0;
	while (nodeA)
	{
		lengthA++;
		nodeA = nodeA->next;
	}
	while (nodeB)
	{
		lengthB++;
		nodeB = nodeB->next;
	}
	nodeA = headA;
	nodeB = headB;
	if (lengthA < lengthB)
	{
		for (int i = 0; i < lengthB - lengthA; i++)
		{
			nodeB = nodeB->next;
		}
	}
	else
	{
		for (int i = 0; i < lengthA - lengthB; i++)
		{
			nodeA = nodeA->next;
		}
	}
	while (nodeA != nodeB)
	{
		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}
	return nodeA;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
	if (headA == NULL || headB == NULL)
		return NULL;
	struct ListNode *nodeA = headA;
	struct ListNode *nodeB = headB;
	while (nodeA!=nodeB)
	{
		nodeA = nodeA->next;
		nodeB = nodeB->next;
		if (nodeA == nodeB)
			break;
		if (nodeA == NULL)
			nodeA = headA;
		if (nodeB == NULL)
			nodeB = headB;
	}
	return nodeA;
}