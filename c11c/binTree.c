/*
 * File: binTree.c
 * This program implements binary trees
 *
 * Stanford EPGY Assignment 16910.1 - "Write a function that determines whether a given tree is balanced." - See "IsTreeBalanced()"
 * Stanford EPGY Assignment 16910.2 - "Write a function that determines whether a tree... [is a valid binary tree.]" - See "IsTreeValid()"
 * Stanford EPGY Assignment 16920 - "Write a function that takes a binary search tree and returns its height." - See "TreeHeight()"
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFIX 0
#define PREFIX 1
#define POSTFIX 2

#define false 0
#define true !false

typedef int bool;

typedef char string[200];
typedef struct nodeT *treeT;
typedef struct nodeT
{
	string key;
	treeT left;
	treeT right;
} *treeT;

treeT FindNode(treeT t, string key);
void InsertNode(treeT *treeP, string key);
void DisplayTree(treeT t, int order);
bool IsTreeBalanced(treeT t);
bool IsTreeValid(treeT t);
int TreeHeight(treeT t);
int Largest(int num1, int num2);

main()
{
	string input;
	treeT t = NULL, findThisNode = NULL;

	InsertNode(&t, "Paris");
	InsertNode(&t, "Tokyo");
	InsertNode(&t, "London");
	InsertNode(&t, "New Delhi");
	InsertNode(&t, "Beijing");
	InsertNode(&t, "Washington, D.C.");
	InsertNode(&t, "Moscow");
	InsertNode(&t, "Berlin");

	printf("=== Tree details ===\n");
	printf("Tree height: %d\n", TreeHeight(t));
	printf("Is tree balanced?: %s\n", IsTreeBalanced(t) ? "true" : "false");
	printf("Is tree valid?: %s\n", IsTreeValid(t) ? "true" : "false");
	printf("\nInfix display of data:\n");
	DisplayTree(t, INFIX);

	printf("\nWould you find to find a particular node in the tree? Type its name: "); gets_s(input, sizeof(input));
	findThisNode = FindNode(t, input);
	if (findThisNode->key != NULL)
	{
		printf("The value \"%s\" was found.\n\n", findThisNode->key);
	}
	else
	{
		printf("That value was not found in the tree.\n\n");
	}

	system("pause");
}

treeT FindNode(treeT t, string key)
{
	int sign;
	if (t == NULL) return NULL;
	sign = strcmp(key, t->key);
	if (sign == 0) return t;
	if (sign < 0)
	{
		return FindNode(t->left, key);
	}
	else /* if (sign > 0) */
	{
		return FindNode(t->right, key);
	}
}

void InsertNode(treeT *treeP, string key)
{
	treeT t = *treeP;
	int sign;
	if (t == NULL)
	{
		t = (treeT)malloc(sizeof(*t));
		strcpy_s(t->key, sizeof(t->key), key);
		t->left = NULL;
		t->right = NULL;
		*treeP = t;
	}
	else
	{
		sign = strcmp(key, t->key);
		if (sign == 0) return;
		else if (sign < 0)
		{
			InsertNode(&t->left, key);
		}
		else /* if (sign > 0) */
		{
			InsertNode(&t->right, key);
		}
	}
}

void DisplayTree(treeT t, int order)
{
	if (t != NULL)
	{
		if (order == INFIX)
		{
			DisplayTree(t->left, INFIX);
			printf("\t%s\n", t->key);
			DisplayTree(t->right, INFIX);
		}
		else if (order == PREFIX)
		{
			printf("\t%s\n", t->key);
			DisplayTree(t->left, PREFIX);
			DisplayTree(t->right, PREFIX);
		}
		else if (order == POSTFIX)
		{
			DisplayTree(t->left, POSTFIX);
			DisplayTree(t->right, POSTFIX);
			printf("\t%s\n", t->key);
		}
	}
}

bool IsTreeBalanced(treeT t)
{
	int lHeight = 0, rHeight = 0;

	if (t == NULL) return true;

	if (t->left != NULL)
	{
		lHeight = TreeHeight(t->left);
	}
	if (t->right != NULL)
	{
		rHeight = TreeHeight(t->right);
	}

	if ((lHeight - rHeight) < -1 || (lHeight - rHeight) > 1) return false;

	if (t->left != NULL)
	{
		return IsTreeBalanced(t->left);
	}
	if (t->right != NULL)
	{
		return IsTreeBalanced(t->right);
	}

	return true;
}

bool IsTreeValid(treeT t)
{
	if (t == NULL) return true;

	if (t->left != NULL)
	{
		if (strcmp(t->left->key, t->key) < 0)
		{
			IsTreeValid(t->left);
		}
		else
		{
			return false;
		}
	}
	if (t->right != NULL)
	{
		if (strcmp(t->right->key, t->key) > 0)
		{
			IsTreeValid(t->right);
		}
		else
		{
			return false;
		}
	}

	return true;
}

int TreeHeight(treeT t)
{
	int leftHeight;
	int rightHeight;

	if (t == NULL)
	{
		return 0;
	}
	else
	{
		leftHeight = TreeHeight(t->left);
		rightHeight = TreeHeight(t->right);

		return Largest(leftHeight, rightHeight) + 1;
	}
}

int Largest(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else if (num2 > num1)
	{
		return num2;
	}
	return 0;
}