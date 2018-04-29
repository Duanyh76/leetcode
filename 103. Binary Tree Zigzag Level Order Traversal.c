struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct List
{
	struct TreeNode *treeNode;
	struct List *next;
};

int max(int a, int b)
{
	return a > b ? a : b;
}
int depth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return max(depth(root->left), depth(root->right)) + 1;
}
void addNode(struct List *list, struct TreeNode *root)
{
	struct List *node = malloc(sizeof(struct List));
	node->treeNode = root;
	node->next = NULL;
	struct List *mobileNode = list;
	while (mobileNode->next != NULL)
		mobileNode = mobileNode->next;
	mobileNode->next = node;
}
struct List *findTail(struct List *current)
{
	struct List *tail = current;
	while (tail->next != NULL)
		tail = tail->next;
	return tail;
}
int getDistance(struct List *current, struct List *tail)
{
	int distance = 1;
	struct List *node = current;
	while (node != tail)
	{
		distance++;
		node = node->next;
	}
	return distance;
}

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
	if (root == NULL)
		return NULL;
	// calculate depth
	int size = depth(root);
	*returnSize = size;
	*columnSizes = malloc(sizeof(int)*size);
	int level = 0;
	// create a list
	struct List *list = malloc(sizeof(struct List));
	list->next = NULL;
	// set current
	addNode(list, root);
	struct List *current = list->next;
	struct List *tail;
	// set list
	while (current != NULL)
	{
		tail = findTail(current);
		int distance = getDistance(current, tail);
		(*columnSizes)[level++] = distance;
		while (current != tail->next)
		{
			if (current->treeNode->left != NULL)
				addNode(list, current->treeNode->left);
			if (current->treeNode->right != NULL)
				addNode(list, current->treeNode->right);
			current = current->next;
		}
	}
	// set matrix
	struct List *node = list->next;
	int **treeMatrix = malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++)
	{
		treeMatrix[i] = malloc(sizeof(int)*(*columnSizes)[i]);
		for (int j = 0; j < (*columnSizes)[i]; j++)
		{
			if (i % 2 == 0)
				treeMatrix[i][j] = node->treeNode->val;
			else
				treeMatrix[i][(*columnSizes)[i] - j - 1] = node->treeNode->val;
			node = node->next;
		}
	}
		
	return treeMatrix;
}