/*
 * File: bubble.c
 * This program sorts an array using the bubble-sort method
 */

#include <stdio.h>

#define size 10

void bubblesort(int numbers[size]);
void display(int numbers[size]);

main()
{
	int numbers[size], i;

	printf("This program sorts an array using the bubble-sort method\n");

	for (i = 0; i < size; i++)
	{
		printf("Enter number %d: ", i + 1);
		scanf("%d", &numbers[i]);
	}

	bubblesort(numbers);
	display(numbers);
}

void bubblesort(int numbers[size])
{
	int i, temp, sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				sorted = 0;
			}
		}
	}
}

void display(int numbers[size])
{
	int i, dirty = 0;
	printf("The sorted array is: ");
	for (i = 0; i < size; i++)
	{
		printf("%s%d", (dirty == 1 ? ", " : ""), numbers[i]);
		dirty = 1;
	}
	printf("\n");
}