bool isPalindrome(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return true;
	struct ListNode *node = head;
	int length = 0;
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
	int midPosition = length / 2;
	for (int i = 0; i < midPosition; i++)
	{
		if (array[i] != array[length - i - 1])
			return false;
	}
	return true;
}

struct ListNode *reverse(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *newHead = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

bool isPalindrome(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return true;
	struct ListNode *fastNode = head->next;
	struct ListNode *slowNode = head;
	while (fastNode != NULL&&fastNode->next != NULL)
	{
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
	}
	struct ListNode *newHead = reverse(slowNode->next);
	while (newHead != NULL)
	{
		if (head->val != newHead->val)
		{
			return false;
		}
		head = head->next;
		newHead = newHead->next;
	}
	return true;
}