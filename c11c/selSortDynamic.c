/*
 * File: sort.c
 * This program sorts a list of numbers according to the selection sort method, using pointers
 */

#include <stdio.h>
#include <stdlib.h>

void sortArray(int *numbers, int arrSize);
int indexMax(int *numbers, int low, int high);
void swap(int *loc1, int *loc2);
void getArray(int *numbers, int arrSize);
void displayArray(int *numbers, int arrSize);
int *powerArray(int size);

main()
{
	int size;
	int *numbers;
	printf("What do you wish to be the size of the array? ");
	scanf_s("%d", &size);

	numbers = powerArray(size);
	if (numbers == NULL)
	{
		printf("Not enough memory to complete the operation; program will now exit\n");
		return;
	}

	getArray(numbers, size);
	sortArray(numbers, size);
	displayArray(numbers, size);

	free(numbers);

	system("pause");
}

void sortArray(int *numbers, int arrSize)
{
	int i, maxInd;
	for (i = arrSize - 1; i > 0; i--)
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

void getArray(int *numbers, int arrSize)
{
	int i;
	for (i = 0; i < arrSize; numbers++, i++)
	{
		printf("\nEnter next integer: ");
		scanf_s("%d", numbers);
	}
}

void displayArray(int *numbers, int arrSize)
{
	int i;
	printf("\nThe sorted list is:\n");
	for (i = 0; i < arrSize; numbers++, i++)
	{
		printf("\t%d", *numbers);
	}
	printf("\n\n");
}

int *powerArray(int size)
{
	return malloc((sizeof(int)) * (size));
}