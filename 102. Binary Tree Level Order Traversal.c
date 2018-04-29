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

struct Queue
{
	struct TreeNode *val;
	struct Queue *next;
	int rank;
};

struct ListNode *createList()
{
	struct ListNode *list = malloc(sizeof(struct ListNode));
	list->next = NULL;
	return list;
}
struct Queue *createQueue()
{
	struct Queue *queue = malloc(sizeof(struct Queue));
	queue->next = NULL;
	return queue;
}
struct TreeNode *deQueue(struct Queue *queue)
{
	struct Queue *deleteNode = queue->next;
	struct TreeNode *treeNode = deleteNode->val;
	queue->next = deleteNode->next;
	free(deleteNode);
	return treeNode;
}
int getLevel(struct Queue *queue)
{
	return queue->next->rank;
}
void enQueue(struct Queue *queue, struct TreeNode *treeNode, int level)
{
	struct Queue *addNode = malloc(sizeof(struct Queue));
	addNode->val = treeNode;
	addNode->rank = level;
	struct Queue *node = queue;
	while (node->next != NULL)
		node = node->next;
	node->next = addNode;
	addNode->next = NULL;
}
void enQueueTwoChild(struct Queue *queue, struct TreeNode *treeNode, int level)
{
	if (treeNode->left)
		enQueue(queue, treeNode->left, level + 1);
	if (treeNode->right)
		enQueue(queue, treeNode->right, level + 1);
}
bool isEmpty(struct Queue *queue)
{
	return queue->next == NULL;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int depth(struct TreeNode *node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	return max(depth(node->left), depth(node->right)) + 1;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
	if (root == NULL)
		return NULL;
	int treeDepth = depth(root);
	*returnSize = treeDepth;
	*columnSizes = malloc(sizeof(int)*treeDepth);
	for (int i = 0; i < treeDepth; i++)
		(*columnSizes)[i] = 0;
	int **treeMatrix = malloc(sizeof(int*)*treeDepth);
	
	struct ListNode *list = createList();
	struct ListNode *array = list;

	struct Queue *queue = createQueue();
	enQueue(queue, root, 0);

	int level;
	struct TreeNode *node;
	while (!isEmpty(queue))
	{
		level = getLevel(queue);
		node = deQueue(queue);
		array->next = malloc(sizeof(struct ListNode));
		array = array->next;;
		array->val = node->val;
		(*columnSizes)[level]++;
		enQueueTwoChild(queue, node, level);
	}

	array = list->next;
	for (int i = 0; i < treeDepth; i++)
	{
		treeMatrix[i] = malloc(sizeof(int)*(*columnSizes)[i]);
		for (int j = 0; j < (*columnSizes)[i]; j++)
		{
			treeMatrix[i][j] = array->val;
			array = array->next;
		}
	}

	return treeMatrix;
}