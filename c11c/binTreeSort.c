/*
 * File: binTreeSort.c
 * This program displayed a sorted list of numbers using a binary tree
 */

#include <stdio.h>
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
	int key;
	treeT left;
	treeT right;
} *treeT;

void InsertNode(treeT *treeP, int key);
void DisplayTree(treeT t, int order);

main()
{
	treeT sorterTree = NULL;
	char ch;
	char lastchar = '\0';
	int number = 0;

	printf("Please enter a list of unique integers. They will be inserted into a binary search tree, then displayed back to you in numerical order by invoking the display method of the binary tree in infix mode. Press ENTER after each number entered. When you are finished entering numbers, press SPACEBAR, then ENTER.\n\n");
	while (true)
	{
		ch = getchar();
		if (ch >= '0' && ch <= '9')
		{
			number = (number * 10) + (ch - '0');
		}
		else if (ch == '\n')
		{
			if (lastchar >= '0' && lastchar <= '9') InsertNode(&sorterTree, number);
			number = 0;
		}
		else if (ch == ' ')
		{
			break;
		}
		lastchar = ch;
	}

	DisplayTree(sorterTree, INFIX);

	printf("\n\n");
	system("pause");
}

void InsertNode(treeT *treeP, int key)
{
	treeT t = *treeP;
	if (t == NULL)
	{
		t = (treeT)malloc(sizeof(*t));
		t->key = key;
		t->left = NULL;
		t->right = NULL;
		*treeP = t;
	}
	else
	{
		if (key == t->key) return;
		else if (key < t->key)
		{
			InsertNode(&t->left, key);
		}
		else
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
			printf("%d ", t->key);
			DisplayTree(t->right, INFIX);
		}
		else if (order == PREFIX)
		{
			printf("%d ", t->key);
			DisplayTree(t->left, PREFIX);
			DisplayTree(t->right, PREFIX);
		}
		else if (order == POSTFIX)
		{
			DisplayTree(t->left, POSTFIX);
			DisplayTree(t->right, POSTFIX);
			printf("%d ", t->key);
		}
	}
}