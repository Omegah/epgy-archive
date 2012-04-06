/*
 * File: linkedList.c
 * This program deals with linked lists
 */

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true !false

typedef int bool;
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
void ConcatLists(LIST_TYPE list1, LIST_TYPE list2);
void SortList(LIST_TYPE list);
void InsertNodeToSorted(LIST_TYPE *list, LIST_TYPE node);

main()
{
	/* Test linked lists are 1 2 5 7 */
	LIST_TYPE testList1 = CreateTestList();
	LIST_TYPE testList2 = CreateTestList();

	/* Make a node to insert... say 6 */
	LIST_TYPE testNode = GetNewNode(6);
	
	/* Concatenate the lists and sort them */
	ConcatLists(testList1, testList2);
	SortList(testList1);

	/* Insert our test node into the list */
	InsertNodeToSorted(&testList1, testNode);

	/* Finally display the list */
	DisplayList(testList1);

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

void ConcatLists(LIST_TYPE list1, LIST_TYPE list2)
{
	if (list1->next == NULL)
	{
		list1->next = list2;
		return;
	}

	list1 = list1->next;

	ConcatLists(list1, list2);
}

void SortList(LIST_TYPE list)
{
	LIST_TYPE head = list;
	int sortcount = 0;

	while (true)
	{
		if (list->next->next == NULL)
		{
			list = head;
			sortcount = 0;
		}
		else
		{
			list = list->next;
		}

		if (list->info > list->next->info)
		{
			INFO_TYPE tmp = list->info;
			list->info = list->next->info;
			list->next->info = tmp;
			sortcount++;
		}

		if (sortcount == 0 && list->next->next == NULL) break;
	}
}

void InsertNodeToSorted(LIST_TYPE *list, LIST_TYPE node)
{
	LIST_TYPE head = *list;
	bool found = false;

	while (!found)
	{
		/* If on end */
		if ((*list)->info <= node->info && (*list)->next == NULL)
		{
			(*list)->next = node;
			*list = head;
			found = true;
			break;
		}

		/* If head */
		if ((*list)->info >= node->info)
		{
			LIST_TYPE tmp = *list;
			*list = node;
			node->next = tmp;
			found = true;
			break;
		}

		if ((*list)->next->info >= node->info)
		{
			node->next = (*list)->next;
			(*list)->next = node;
			*list = head;
			found = true;
			break;
		}

		*list = (*list)->next;
	}
}