/*
 * File: euclid.c
 * This program computes the GCD of two numbers using Euclid's algorithm
 */

#include <stdio.h>

main()
{
	int num1, num2, temp, orig1, orig2, rem;

	printf("This program computes the GCD of two numbers using Euclid's algorithm\n");
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);

	if (num1 > num2)
	{
		temp = num2;
		num2 = num1;
		num1 = temp;
	}

	orig1 = num1;
	orig2 = num2;

	rem = num1 % num2;

	if (rem == 0)
	{
		printf("The GCD of %d and %d is %d\n", num1, num2, num2);
	}
	else
	{
		while (rem != 0)
		{
			num1 = num2;
			num2 = rem;
			rem = num1 % num2;
		}
		printf("The GCD of %d and %d is %d\n", orig1, orig2, num2);
	}
}