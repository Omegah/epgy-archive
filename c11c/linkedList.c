/*
 * File: linkedList.c
 * This program deals with linked lists
 */

#include <stdio.h>
#include <stdlib.h>

typedef int INFO_TYPE;
typedef struct NODE_TYPE *LIST_TYPE;
typedef struct NODE_TYPE
{
	INFO_TYPE info;
	LIST_TYPE next;
}
NODE_TYPE;

LIST_TYPE GetNewNode(INFO_TYPE newInfo);
void DisposeNode(LIST_TYPE *node0, LIST_TYPE *eraseNode);
void Remove(LIST_TYPE *list);
LIST_TYPE CreateTestList(void);
void DisplayList(LIST_TYPE list);
int ListLengthIter(LIST_TYPE list);
void ReverseListIter(LIST_TYPE *head);
LIST_TYPE ReverseListRecur(LIST_TYPE head);

main()
{
	/* Test linked list is 1 2 5 7 */
	LIST_TYPE testList = CreateTestList();

	/* First let's drop the head node of the list */
	Remove(&testList);

	/* Then reverse the linked list using the recursive reverse function */
	testList = ReverseListRecur(testList);

	/* After that, reverse it back with the iterative function */
	ReverseListIter(&testList);

	/* Finally display the list */
	DisplayList(testList);

	system("pause");
}

LIST_TYPE GetNewNode(INFO_TYPE newInfo)
{
	LIST_TYPE pNode;
	pNode = (LIST_TYPE)malloc(sizeof(*pNode));
	if (pNode == NULL)
	{
		printf("Failed to allocate enough memory to perform this operation. Exiting.\n");
		exit(1);
	}
	else
	{
		pNode->info = newInfo;
		pNode->next = NULL;
	}

	return pNode;
}

void DisposeNode(LIST_TYPE *node0, LIST_TYPE *eraseNode)
{
	LIST_TYPE temp = *node0;
	if (temp == *eraseNode) /* Erasing the head */
	{
		*node0 = (*node0)->next;
	}
	else
	{
		for (; temp != NULL; temp = temp->next)
		{
			if (temp->next == *eraseNode)
			{
				temp->next = temp->next->next;
				free(*eraseNode);
				break;
			}
		}
	}
}

void Remove(LIST_TYPE *list)
{
	DisposeNode(list, list);
}

LIST_TYPE CreateTestList()
{
	#define NUM_NODES 4
	#define FIRST_INFO 1
	#define SECOND_INFO 2
	#define THIRD_INFO 5
	#define FOURTH_INFO 7

	INFO_TYPE infoTable[NUM_NODES] = { FIRST_INFO, SECOND_INFO, THIRD_INFO, FOURTH_INFO };

	LIST_TYPE list;
	LIST_TYPE link;
	LIST_TYPE node;
	int i;

	node = GetNewNode(infoTable[0]);
	list = node;

	/* Create other nodes... allocation is done by calling GetNewNode() */
	for (link = list, i = 1; i < NUM_NODES; i++)
	{
		node = GetNewNode(infoTable[i]);
		link->next = node;
		link = link->next;
	}

	return list;
}

void DisplayList(LIST_TYPE list)
{
	LIST_TYPE link;
	for (link = list; link != NULL;)
	{
		printf("%d\t", link->info);
		link = link->next;
	}

	/* Add a couple newlines for display purposes */
	printf("\n\n");
}

int ListLengthIter(LIST_TYPE list)
{
	int count;
	for (count = 0; list != NULL; list = list->next, count++);
	return count;
}

void ReverseListIter(LIST_TYPE *head)
{
   LIST_TYPE newList = NULL;
   LIST_TYPE temp;

   while (*head != NULL)
   {
	  temp = (*head)->next;
	  (*head)->next = newList;
	  newList = *head;
	  *head = temp;
   }

   *head = newList;
}

LIST_TYPE ReverseListRecur(LIST_TYPE head)
{
	LIST_TYPE temp;

	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	temp = ReverseListRecur(head->next);
	head->next->next = head;
	head->next = NULL;

	return temp;
}