void deleteNode(struct ListNode* node)
{
	while (node->next->next != NULL)
	{
		node->val = node->next->val;
		node = node->next;
	}
	node->val = node->next->val;
	node->next = NULL;
}

void deleteNode(struct ListNode* node) 
{
	struct ListNode *nodeNext = node->next;
	node->next = nodeNext->next;
	node->val = nodeNext->val;
	free(nodeNext);
}