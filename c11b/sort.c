/*
 * File: sort.c
 * This program sorts a list of numbers according to the selection sort method
 */

#include <stdio.h>

#define size 7

void sortArray(int numbers[]);
int indexMax(int numbers[], int low, int high);
void swap(int numbers[], int loc1, int loc2);
void getArray(int numbers[]);
void displayArray(int numbers[]);

main()
{
	int numbers[size];
	getArray(numbers);
	sortArray(numbers);
	displayArray(numbers);
}

void sortArray(int numbers[])
{
	int i, maxInd;
	for (i = size - 1; i > 0; i--)
	{
		maxInd = indexMax(numbers, 0, i);
		swap(numbers, maxInd, i);
	}
}

int indexMax(int numbers[], int low, int high)
{
	int i, maxInd = high;
	for (i = low; i <= high; i++)
	{
		if (numbers[i] > numbers[maxInd])
		{
			maxInd = i;
		}
	}
	return maxInd;
}

void swap(int numbers[], int loc1, int loc2)
{
	int temp = numbers[loc1];
	numbers[loc1] = numbers[loc2];
	numbers[loc2] = temp;
}

void getArray(int numbers[])
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("\nEnter next integer: ");
		scanf("%d", &numbers[i]);
	}
}

void displayArray(int numbers[])
{
	int i;
	printf("\nThe sorted list is:\n");
	for (i = 0; i < size; i++)
	{
		printf("\t%d", numbers[i]);
	}
	printf("\n\n");
}