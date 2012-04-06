/*
 * File: GCD1.c
 * This program computes the greatest common divisor for two integers
 */

#include <stdio.h>

main()
{
	int num1, num2, temp, orig1, orig2, i;

	printf("This program computes the greatest common divisor for two integers\n");
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);

	/* Make sure num2 > num1 */
	if (num1 > num2)
	{
		temp = num2;
		num2 = num1;
		num1 = temp;
	}

	orig1 = num1;
	orig2 = num2;

	if (num1 % num2 == 0)
	{
		printf("The GCD of %d and %d is %d\n", orig1, orig2, num2);
	}
	else
	{
		for (i = num2; i > 0; i--)
		{
			if (num1 % i == 0 && num2 % i == 0)
			{
				printf("The GCD of %d and %d is %d\n", orig1, orig2, i);
				break;
			}
		}
	}
}