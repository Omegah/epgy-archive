/*
 * File: max.c
 * This program gets two integers and finds the maximum
 */

#include <stdio.h>

main()
{
	int num1, num2, max;

	printf("This program gets two integers and finds the maximum.\n");
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);

	if (num1 > num2)
	{
		max = num1;
		printf("The maximum number between %d and %d is %d\n", num1, num2, max);
	}
	else if (num2 > num1)
	{
		max = num2;
		printf("The maximum number between %d and %d is %d\n", num1, num2, max);
	}
	else if (num1 == num2)
	{
		printf("The two numbers %d and %d are equal\n", num1, num2);
	}
}