struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	if (head == NULL)
		return NULL;
	// copy list
	struct RandomListNode *node = head;
	while (node != NULL)
	{
		struct RandomListNode *newNode = malloc(sizeof(struct RandomListNode));
		newNode->label = node->label;
		newNode->next = node->next;
		node->next = newNode;
		node = newNode->next;
	}
	// copy random
	node = head;
	while (node != NULL)
	{
		if (node->random == NULL)
		{
			node->next->random = NULL;
		}
		else
		{
			node->next->random = node->random->next;
		}
		node = node->next->next;
	}
	// seperate list
	struct RandomListNode *copyHead = head->next;
	struct RandomListNode *copyNode = copyHead;
	node = head;
	while (copyNode->next != NULL)
	{
		node->next = copyNode->next;
		copyNode->next = copyNode->next->next;
		node = node->next;
		copyNode = copyNode->next;
	}
	node->next = NULL;

	return copyHead;
}