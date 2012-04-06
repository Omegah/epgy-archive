/*
 * File: sort.c
 * This program sorts a list of numbers according to the selection sort method, using pointers
 */

#include <stdio.h>
#include <stdlib.h>

#define size 7

void sortArray(int *numbers);
int indexMax(int *numbers, int low, int high);
void swap(int *loc1, int *loc2);
void getArray(int *numbers);
void displayArray(int *numbers);

main()
{
	int numbers[size];
	getArray(numbers);
	sortArray(numbers);
	displayArray(numbers);

	system("pause");
}

void sortArray(int *numbers)
{
	int i, maxInd;
	for (i = size - 1; i > 0; i--)
	{
		maxInd = indexMax(numbers, 0, i);
		swap(&numbers[maxInd], &numbers[i]);
	}
}

int indexMax(int *numbers, int low, int high)
{
	int i, maxInd = high;
	int *p = numbers;
	for (i = low; i <= high; p++, i++)
	{
		if (*p > numbers[maxInd])
		{
			maxInd = i;
		}
	}
	return maxInd;
}

void swap(int *loc1, int *loc2)
{
	int temp = *loc1;
	*loc1 = *loc2;
	*loc2 = temp;
}

void getArray(int *numbers)
{
	int i;
	for (i = 0; i < size; numbers++, i++)
	{
		printf("\nEnter next integer: ");
		scanf_s("%d", numbers);
	}
}

void displayArray(int *numbers)
{
	int i;
	printf("\nThe sorted list is:\n");
	for (i = 0; i < size; numbers++, i++)
	{
		printf("\t%d", *numbers);
	}
	printf("\n\n");
}