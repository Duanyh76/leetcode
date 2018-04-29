struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct List
{
	struct ListNode *head;
	struct ListNode *tail;
};

struct List *createList()
{
	struct List *list = malloc(sizeof(struct List));
	struct ListNode *node = malloc(sizeof(struct ListNode));
	list->head = node;
	node->next = NULL;
	list->tail = node;
	return list;
}
void addListNode(struct List *list, int key)
{
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->val = key;
	list->tail->next = node;
	list->tail = node;
}
int listLength(struct List *list)
{
	int length = 0;
	struct ListNode *node = list->head;
	while (node != list->tail)
	{
		length++;
		node = node->next;
	}
	return length;
}
int *convertListToArray(struct List *list, int length)
{
	int *array = malloc(sizeof(int)*length);
	struct ListNode *node = list->head->next;
	for (int i = 0; i < length; i++)
	{
		array[i] = node->val;
		node = node->next;
	}
	return array;
}
void *convertTreeToList(struct TreeNode *root, struct List *list)
{
	if (root == NULL)
		return;
	if (root->left != NULL)
		convertTreeToList(root->left, list);
	addListNode(list, root->val);
	if (root->right != NULL)
		convertTreeToList(root->right, list);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	struct List *list = createList();
	convertTreeToList(root, list);
	int length = listLength(list);
	*returnSize = length;
	int *array = convertListToArray(list, length);
	return array;
}