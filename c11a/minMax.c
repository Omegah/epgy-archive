/*
 * File: minMax.c
 * This program gets a list of integers from the user and computes the minimal and maximal number appearing in the list
 */

#include <stdio.h>

main()
{
	int num, min, max;

	printf("You will now be prompted to enter a list of numbers. Enter zero when you are finished entering numbers:\n");
	printf("Enter your first number: ");
	scanf("%d", &num);

	min = num;
	max = num;

	while (num != 0)
	{
		min = (num < min) ? num : min;
		max = (num > max) ? num : max;
		printf("Enter your next number: ");
		scanf("%d", &num);
	}

	printf("The maximum number in the list is %d\n", max);
	printf("The minimum number in the list is %d\n", min);
}