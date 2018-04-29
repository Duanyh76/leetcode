bool noCycle(struct ListNode *head)
{
	struct ListNode *fastNode = head;
	struct ListNode *slowNode = head;
	while (fastNode != NULL && fastNode->next != NULL)
	{
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;
		if (slowNode == fastNode)
			return false;
	}
	return true;
}

struct ListNode *detectCycle(struct ListNode *head)
{
	if (head == NULL || noCycle(head))
		return NULL;
	// hasCycle
	struct ListNode *fastNode = head;
	struct ListNode *slowNode = head;
	do
	{
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;
	} while (fastNode != slowNode);
	fastNode = head;
	while (fastNode != slowNode)
	{
		fastNode = fastNode->next;
		slowNode = slowNode->next;
	}
	return fastNode;
}

struct ListNode *detectCycle(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return NULL;
	struct ListNode *fastNode = head;
	struct ListNode *slowNode = head;
	struct ListNode *entryNode = head;
	while (fastNode != NULL && fastNode->next != NULL)
	{
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;
		if (fastNode == slowNode)
		{
			while (entryNode != slowNode)
			{
				entryNode = entryNode->next;
				slowNode = slowNode->next;
			}
			return entryNode;
		}
	}
	return NULL;
}