/*
 * File: recurBin.c
 * This program uses a recursive binary search algorithm to locate values in an array
 */

#include <stdio.h>

#define SIZE 10

void sortArray(int numbers[]);
int indexMin(int numbers[], int low, int high);
void swap(int numbers[], int loc1, int loc2);
int binSearch(int val, int arr[], int low, int high);

main()
{
	int i, j, numbers[SIZE], num, found;

	printf("This program uses the recursive binary search algorithm!\nYou will now be prompted to enter a list of %d numbers:\n", SIZE);

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
	found = binSearch(num, numbers, 0, SIZE - 1);
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

int binSearch(int val, int arr[], int low, int high)
{
	int mid;

	if (high < low) return -1;

	mid = (low + high) / 2;

	if (arr[mid] > val)
	{
		return binSearch(val, arr, low, mid - 1);
	}
	else if (arr[mid] < val)
	{
		return binSearch(val, arr, mid + 1, high);
	}
	else
	{
		return mid;
	}
}