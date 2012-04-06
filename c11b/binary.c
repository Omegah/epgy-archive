/*
 * File: binary.c
 * This program uses the binary search algorithm
 */

#include <stdio.h>

#define SIZE 10

void sortArray(int numbers[]);
int indexMin(int numbers[], int low, int high);
void swap(int numbers[], int loc1, int loc2);
int binSearch(int val, int arr[], int size);

main()
{
	int i, j, numbers[SIZE], num, found;

	printf("This program uses the binary search algorithm\nYou will now be prompted to enter a list of %d numbers:\n", SIZE);

	for (i = 0; i < SIZE; i++)
	{
		printf("Enter number %d: ", i + 1);
		scanf("%d", &numbers[i]);
	}

	printf("\nSorting array... ");
	sortArray(numbers);
	printf("complete!\n\n");

	for (j = 0; j < SIZE; j++)
	{
		printf("%d\n", numbers[j]);
	}

	printf("\nEnter a number in the array to search for: ");
	scanf("%d", &num);

	printf("\nSearching... ");
	found = binSearch(num, numbers, SIZE);
	if (found != -1)
	{
		printf("number found at index %d\n\n", found);
	}
	else
	{
		printf("number not found\n\n");
	}
}

void sortArray(int numbers[])
{
	int i, minInd;
	for (i = 0; i < SIZE; i++)
	{
		minInd = indexMin(numbers, i, SIZE - 1);
		swap(numbers, i, minInd);
	}
}

int indexMin(int numbers[], int low, int high)
{
	int i, minInd;
	minInd = low;
	for (i = low; i <= high; i++)
	{
		if (numbers[i] < numbers[minInd])
		{
			minInd = i;
		}
	}
	return minInd;
}

void swap(int numbers[], int loc1, int loc2)
{
	int temp;

	temp = numbers[loc1];
	numbers[loc1] = numbers[loc2];
	numbers[loc2] = temp;
}

int binSearch(int val, int arr[], int size)
{
	int low, high, mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (val < arr[mid])
		{
			high = mid - 1;
		}
		else if (val > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}