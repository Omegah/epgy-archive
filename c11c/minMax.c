/*
 * File: minMax.c
 * This program computes the minimum and maximum numbers in a list of 3 integers entered by the user
 */

#include <stdio.h>
#include <stdlib.h>

void minMax(int *max, int *min, int num1, int num2, int num3);

main()
{
	int min, max, num1, num2, num3;

	printf("Enter 3 integers. The minimum and maximum ones in the list will be shown to you...\n");
	printf("Enter number 1: ");
	scanf_s("%d", &num1);
	printf("Enter number 2: ");
	scanf_s("%d", &num2);
	printf("Enter number 3: ");
	scanf_s("%d", &num3);

	minMax(&max, &min, num1, num2, num3);

	printf("The minimum number was %d and the maximum number was %d\n", min, max);

	system("pause");
}

void minMax(int *max, int *min, int num1, int num2, int num3)
{
	if (num1 >= num2 && num1 >= num3)
		*max = num1;
	else if (num2 >= num1 && num2 >= num3)
		*max = num2;
	else if (num3 >= num1 && num3 >= num2)
		*max = num3;

	if (num1 <= num2 && num1 <= num3)
		*min = num1;
	else if (num2 <= num1 && num2 <= num3)
		*min = num2;
	else if (num3 <= num1 && num3 <= num2)
		*min = num3;
}