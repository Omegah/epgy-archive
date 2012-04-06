/*
 * File: stack.c
 * This program implements a stack using linked lists; it compares two entered strings to see if they are opposite
 */

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true !false

typedef int bool;
typedef char INFO_TYPE;
typedef struct NODE_TYPE *LIST_TYPE;
typedef struct NODE_TYPE
{
	INFO_TYPE info;
	LIST_TYPE next;
}
NODE_TYPE;

void DisposeNode(LIST_TYPE *node0, LIST_TYPE *eraseNode);
LIST_TYPE GetNewNode(INFO_TYPE newInfo);
void push(LIST_TYPE *list, LIST_TYPE element);
LIST_TYPE pop(LIST_TYPE *list);

main()
{
	char c;
	LIST_TYPE list1 = NULL;
	LIST_TYPE list2 = NULL;
	bool match = true;
	LIST_TYPE foo;

	printf("This program implements a stack using linked lists; it compares two entered strings to see if they are opposite\n\n");
	printf("Enter string 1: ");
	while ((c = getchar()) != '\n')
	{
		push(&list1, GetNewNode(c));
	}

	printf("Enter string 2: ");
	while ((c = getchar()) != '\n')
	{
		push(&list2, GetNewNode(c));
	}

	while (list1 != NULL)
	{
		if (list2 == NULL)
		{
			match = false;
			break;
		}

		foo = pop(&list2);
		if (foo->info == list1->info)
		{
			list1 = list1->next;
		}
		else
		{
			match = false;
			break;
		}
	}

	match = !(list1 != NULL || list2 != NULL);

	printf("\nThe result of the operation is %s\n", match ? "TRUE" : "FALSE");

	system("pause");
}

LIST_TYPE GetNewNode(INFO_TYPE newInfo)
{
	LIST_TYPE pNode;
	pNode = (LIST_TYPE)malloc(sizeof(*pNode));
	if (pNode == NULL)
	{
		printf("Failed to allocate enough memory to perform this operation. Exiting.\n");
		system("pause");
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

void push(LIST_TYPE *list, LIST_TYPE element)
{
	LIST_TYPE tmp = *list;

	if (*list == NULL)
	{
		*list = element;
	}
	else
	{
		while ((*list)->next != NULL)
		{
			(*list) = (*list)->next;
		}
		(*list)->next = element;
		*list = tmp;
	}
}

LIST_TYPE pop(LIST_TYPE *list)
{
	LIST_TYPE node = *list;
	LIST_TYPE retNode;

	while (node->next != NULL)
	{
		node = node->next;
	}

	retNode = GetNewNode(node->info);
	DisposeNode(list, &node);

	return retNode;
}