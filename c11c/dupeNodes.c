/*
 * File: dupeNodes.c
 * This program removes duplicate nodes from a linked list
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
LIST_TYPE CreateTestList(void);
void SortList(LIST_TYPE list);
void DisplayList(LIST_TYPE list);
void RemoveDuplicates(LIST_TYPE *list);

main()
{
	LIST_TYPE testList = CreateTestList();
	RemoveDuplicates(&testList);
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

LIST_TYPE CreateTestList()
{
	#define NUM_NODES 9
	#define INFO_1 1
	#define INFO_2 5
	#define INFO_3 5
	#define INFO_4 5
	#define INFO_5 8
	#define INFO_6 19
	#define INFO_7 19
	#define INFO_8 20
	#define INFO_9 21

	INFO_TYPE infoTable[NUM_NODES] = { INFO_1, INFO_2, INFO_3, INFO_4, INFO_5, INFO_6, INFO_7, INFO_8, INFO_9 };

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

void RemoveDuplicates(LIST_TYPE *list)
{
	LIST_TYPE head = *list;
	LIST_TYPE tmp;
	bool dirty = false;

	SortList(*list);

	while (true)
	{
		for (; (*list) && (*list)->next; (*list) = (*list)->next)
		{
			if ((*list)->info == (*list)->next->info)
			{
				// Duplicate
				tmp = (*list)->next;
				(*list)->next = (*list)->next->next;
				free(tmp);
			}
		}

		*list = head;

		dirty = false;
		while ((*list)->next != NULL)
		{
			if ((*list)->info == (*list)->next->info)
			{
				dirty = true;
				break;
			}
			*list = (*list)->next;
		}
		if (!dirty) break;
	}

	*list = head;
}