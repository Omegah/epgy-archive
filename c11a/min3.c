/*
 * File: min3.c
 * This program finds the minimum of three integers
 */

#include <stdio.h>

main()
{
	int i, j, min;
	int num[3];

	printf("This program finds the minimum of three integers\n");
	for (i = 0; i < 3; i++)
	{
		printf("Enter integer %d: ", i + 1);
		scanf("%d", &num[i]);
		if (i == 0) min = num[0];
	}

	for (j = 0; j < 3; j++)
	{
		min = (num[j] < min) ? num[j] : min;
	}

	printf("The minimum number between %d, %d and %d is %d\n", num[0], num[1], num[2], min);
}