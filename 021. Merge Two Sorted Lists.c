struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
	struct ListNode *node1 = l1;
	struct ListNode *node2 = l2;
	struct ListNode *node = head;
	while (node1 && node2)
	{
		if (node1->val < node2->val)
		{
			node->next = node1;
			node1 = node1->next;
		}
		else
		{
			node->next = node2;
			node2 = node2->next;
		}
		node = node->next;
	}
	if (node1)
		node->next = node1;
	else
		node->next = node2;
	node = head->next;
	free(head);
	return node;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if( !l1 || !l2 )
        return l1 ? l1 : ( l2 ? l2 : NULL );
    struct ListNode *head = l1->val < l2->val ? l1 : l2;
    head->next = mergeTwoLists( head->next, head == l1 ? l2 : l1 );
    return head;
}