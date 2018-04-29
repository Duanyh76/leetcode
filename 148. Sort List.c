int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}


struct ListNode* sortList(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	int length = 0;
	struct ListNode *node = head;
	while (node != NULL)
	{
		length++;
		node = node->next;
	}
	int *array = malloc(sizeof(int)*length);
	node = head;
	for (int i = 0; i < length; i++)
	{
		array[i] = node->val;
		node = node->next;
	}
	qsort(array, length, sizeof(array[0]), compare);
	node = head;
	for (int i = 0; i < length; i++)
	{
		node->val = array[i];
		node = node->next;
	}
	return head;
}

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2)
{
	struct ListNode *assistHead = malloc(sizeof(struct ListNode));
	struct ListNode *node1 = list1;
	struct ListNode *node2 = list2;
	struct ListNode *node = assistHead;
	while (node1 != NULL&&node2 != NULL)
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
	if (node1 != NULL)
	{
		node->next = node1;
	}
	if (node2 != NULL)
	{
		node->next = node2;
	}
	node = assistHead->next;
	free(assistHead);
	return node;
}

struct ListNode* sortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *slowNode = head;
	struct ListNode *fastNode = head->next;
	while (fastNode != NULL&&fastNode->next != NULL)
	{
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;
	}
	struct ListNode *newHead = slowNode->next;
	slowNode->next = NULL;
	head = sortList(head);
	newHead = sortList(newHead);
	return merge(head, newHead);
}