#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
typedef struct node{
	int data;
	struct node * left;
	struct node * right;
	int height;
}node;

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int height(node * node)
{
	if (node == NULL)
		return -1;
	return 1 + max(height(node->left), height(node->right));
}

int isBalanced(node * root)
{
	if (root == NULL)
		return 1;

	int lh = height(root->left);
	int rh = height(root->right);


	if (abs(lh - rh) <= 1
		&& isBalanced(root->left) && isBalanced(root->right))
		return 1;

	return 0;
}

node * minvalue(node * root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}

	return root;
}

node * AddDataToTree(node * root, int data,int height)
{
	if (root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		root->height = height;
		return root;
	}
	else if (root->data > data)
	{
		if (root->left != NULL)
			return AddDataToTree(root->left, data,height);
		node * temp = (node*)malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
		temp->height = height;
		root->left = temp;
		return temp;
	}
	if (root->right != NULL)
		return AddDataToTree(root->right, data, height);
	node * temp = (node*)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	temp->height = height;
	root->right = temp;
	return temp;
}

node * NonRecAddData(node * root, int data,int h)
{
	if (!root)
	{
		node * temp = (node*)malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
		return temp;
	}
	node * prev = NULL;
	char type = ' ';
	while (root)
	{
		prev = root;
		if (root->data < data)
		{
			root = root->right;
			type = 'r';
		}
		else if (root->data > data)
		{
			root = root->left;
			type = 'l';
		}
	}
	if (type == 'l')
	{
		node * temp = (node*)malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
		prev->left = temp;
	}
	else
	{
		node * temp = (node*)malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
		prev->right = temp;
	}
	return prev;
}

node * NonRecDeleteNode(node * root, int data)
{
	node * prev = NULL;
	node * ptr = root;
	char type = ' ';
	while (ptr)
	{
		if (ptr->data == data)
		{
			if (!ptr->left && !ptr->right)
			{
				if (type == 'l')
					prev->left = NULL;
				else
					prev->right = NULL;
				break;
			}
			else if (ptr->left && ptr->right)
			{
				node * temp = ptr;
				node * minnode = minvalue(ptr->right);
				ptr = minnode;
				ptr->left = temp->left;
				if (type == 'l')
					prev->left = ptr;
				else
					prev->right = ptr;
				free(temp);
				break;
			}
			else if (ptr->left == NULL)
			{
				if (type == 'l')
				{
					prev->left = ptr->right;
				}
				else
				{
					prev->right = ptr->right;
				}
				free(ptr);
				ptr = NULL;
				break;
			}
			else if (ptr->right == NULL)
			{
				if (type == 'l')
					prev->left = ptr->left;
				else
					prev->right = ptr->left;
				free(ptr);
				ptr = NULL;
				break;
			}
		}
		prev = ptr;
		if (ptr->data < data)
		{
			ptr = ptr->right;
			type = 'r';
		}
		else if (ptr->data > data)
		{ 
			ptr = ptr->left;
			type = 'l';
		}
	}
	return root;
}


node * DeleteNode(node * root, int data)
{
	if (root == NULL) return 0;
	else if (root->data < data) root->right = DeleteNode(root->right, data);
	else if (root->data > data) root->left = DeleteNode(root->left, data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			node* temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL)
		{
			node* temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			node * temp = minvalue(root->right);
			root->data = temp->data;
			root->right = DeleteNode(root->right, temp->data);
		}
	}

	return root;
}

void inorder_print(node* root)
{
	if (root != NULL)
	{
		inorder_print(root->left);
		printf("Data : %d, Height : %d\n", root->data, root->height);
		inorder_print(root->right);
	}
}


void updateheights(int h, node * node)
{
	if (node != NULL)
	{
		int nheight = height(node);
		node->height = nheight;
		updateheights(0, node->left);
		updateheights(0, node->right);
	}
}

node * rightrotate(node * y)
{
	node * tempx = y->left;
	y->left = tempx->right;
	tempx->right = y;
	//tempx->height++;
	updateheights(0, tempx);
	//updateheights(1, tempx->left);
	//updateheights(0, y);
	return tempx;
}
int leafcount(node * node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	
	return leafcount(node->left) + leafcount(node->right);
}
void main()
{
	srand(time(NULL));
	node * root = NULL;
	root = NonRecAddData(root, 90, 4);
	NonRecAddData(root, 70, 3);
	NonRecAddData(root, 100, 0);
	NonRecAddData(root, 65, 1);
	NonRecAddData(root, 75, 2);
	NonRecAddData(root, 60, 0);
	NonRecAddData(root, 78, 1);
	NonRecAddData(root, 79, 0);
	NonRecAddData(root, 63, 0);
	printf("LeafCount : %d\n", leafcount(root));
	//NonRecDeleteNode(root, 70);
	//node * www = minvalue(root);
	//printf("Min val : %d\n", www->data);
	//updateheights(0,root);
	inorder_print(root);
	printf("---------------------------------\n");
	root = rightrotate(root);
	inorder_print(root);
	getch();
}