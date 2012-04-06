/*
 * File: quicksort.c
 * This program sorts an integer array using the quicksort method
 */

#include <stdio.h>

#define SIZE 20

char* getOrdSuffix(int i);
void switchValues(int *a, int *b);
void quicksort(int arr[], int start, int size);

main()
{
	int arr[SIZE], c, i;

	printf("This program sorts an integer array using the quicksort method\n");
	printf("You will now be prompted to enter a list of 20 numbers:\n");
	for (c = 0; c < SIZE; c++)
	{
		printf("Enter %d%s number: ", c + 1, getOrdSuffix(c + 1));
		scanf("%d", &arr[c]);
	}

	printf("\nThe sorted list is:\n");
	quicksort(arr, 0, SIZE);
	for (i = 0; i < SIZE; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

void switchValues(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int arr[], int start, int size)
{
	if (size > start + 1)
	{
		int pivot = arr[start], left = start + 1, right = size;
		while (left < right)
		{
			if (arr[left] <= pivot)
			{
				left++;
			}
			else
			{
				switchValues(&arr[left], &arr[--right]);
			}
		}
		switchValues(&arr[--left], &arr[start]);
		quicksort(arr, start, left);
		quicksort(arr, right, size);
	}
}

char* getOrdSuffix(int i)
{
	int lastDigit;
	char* os;
	/* Determine ordinal suffix */
	lastDigit = i % 10;
	if (i >= 4 && i <= 20)
		os = "th";
	else if (i == 0 || lastDigit == 0)
		os = "th";
	else if (i == 1 || lastDigit == 1)
		os = "st";
	else if (i == 2 || lastDigit == 2)
		os = "nd";
	else if (i == 3 || lastDigit == 3)
		os = "rd";
	else
		os = "th";

	return os;
}