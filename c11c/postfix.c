/*
 * File: postfix.c
 * This program evaluates postfix expressions using linked lists
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
int ListLengthIter(LIST_TYPE list);
void push(LIST_TYPE *list, LIST_TYPE element);
LIST_TYPE pop(LIST_TYPE *list);

main()
{
	LIST_TYPE operands = NULL, temp1, temp2;
	char op;

	printf("This program evaluates postfix expressions using linked lists\n\n");
	printf("Enter the numbers/operators in the postfix expression pressing ENTER after each number or operator\nWhen you are done, press SPACEBAR, then ENTER\n\n");
	while (true)
	{
		op = getchar();
		if (op == ' ')
		{
			break;
		}
		else if (op >= '0' && op <= '9')
		{
			push(&operands, GetNewNode(op - '0'));
		}
		else if (op == '+' || op == '-' || op == '*' || op == '/')
		{
			if (ListLengthIter(operands) >= 2)
			{
				temp2 = pop(&operands);
				temp1 = pop(&operands);
				if (op == '+')
				{
					push(&operands, GetNewNode(temp1->info + temp2->info));
				}
				else if (op == '-')
				{
					push(&operands, GetNewNode(temp1->info - temp2->info));
				}
				else if (op == '*')
				{
					push(&operands, GetNewNode(temp1->info * temp2->info));
				}
				else if (op == '/')
				{
					push(&operands, GetNewNode(temp1->info / temp2->info));
				}
			}
			else
			{
				printf("Illegal postfix expression.\n");
				system("pause");
				exit(1);
			}
		}
	}

	printf("The result of the postfix expression was: %d\n", operands->info);

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

int ListLengthIter(LIST_TYPE list)
{
	int count;
	for (count = 0; list != NULL; list = list->next, count++);
	return count;
}