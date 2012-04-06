/*
 * File: power.c
 * This program computes the power of numbers by using the multiplication operation
 */

#include <stdio.h>

main()
{
	int base, power, result, i;

	printf("This program computes the power of numbers by using the multiplication operation\n");
	printf("Enter the base: ");
	scanf("%d", &base);
	printf("Enter the exponent: ");
	scanf("%d", &power);

	result = base;

	for (i = 1; i < power; i++)
	{
		result *= base;
	}

	printf("%d to the power of %d is %d\n", base, power, result);
}