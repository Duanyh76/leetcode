bool hasCycle(struct ListNode *head)
{
	struct ListNode *fastNode = head;
	struct ListNode *slowNode = head;
	do
	{
		if (fastNode == NULL || fastNode->next == NULL)
			return false;
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;
	} while (fastNode != slowNode);
	return true;
}
