/*
 * File: removeD.c
 * This program removes duplicate values from an array of integers
 */

#include <stdio.h>

#define size 10

int removedup(int inpArray[], int inpArraySize, int outArray[]);
void sortArray(int numbers[]);
int indexMax(int numbers[], int low, int high);
void swap(int numbers[], int loc1, int loc2);

main()
{
	int inputArray[size], outArray[size], i, j, k, newsize;

	printf("This program sorts an array and removes the duplicates\nYou will now be prompted to enter an array of %d numbers\n", size);

	for (i = 0; i < size; i++)
	{
		printf("Enter number %d: ", i + 1);
		scanf("%d", &inputArray[i]);
	}

	sortArray(inputArray);

	newsize = removedup(inputArray, size, outArray);

	printf("\nThe sorted input array is:\n");
	for (j = 0; j < size; j++)
	{
		printf("%d ", inputArray[j]);
	}

	printf("\n\nThe sorted output array (duplicates removed) is:\n");
	for (k = 0; k < newsize; k++)
	{
		printf("%d ", outArray[k]);
	}
	printf("\n\n");
}

int removedup(int inpArray[], int inpArraySize, int outArray[])
{
	int i, j = 0, lastValue = inpArray[0] - 1;
	for (i = 0; i < inpArraySize; i++)
	{
		if (inpArray[i] != lastValue) { outArray[j] = inpArray[i]; j++; }
		lastValue = inpArray[i];
	}

	return j;
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