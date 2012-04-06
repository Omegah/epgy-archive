/*
 * File: power2.c
 * This program produces and displays an array of integers
 */

#include <stdio.h>
#include <math.h>

#define MAX_ELEMENTS 6

main()
{
	int nums[MAX_ELEMENTS], i, j;

	for (i = 0; i < MAX_ELEMENTS; i++)
	{
		nums[i] = pow(2, i);
	}

	for (j = 0; j < MAX_ELEMENTS; j++)
	{
		printf("%d\t", nums[j]);
	}

	printf("\n");
}