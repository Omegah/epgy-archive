/*
 * File: mulByAdd.c
 * This program executes multiplication of two integers entered by the user, by using ONLY the addition operation
 */

#include <stdio.h>

main()
{
	int num1, num2, temp, product, counter;

	printf("This program executes multiplication of two integers entered by the user, by using ONLY the addition operation.\n");
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);

	// If second number > first number, switch the values of the variables
	if (num2 > num1)
	{
		temp = num1;

		num1 = num2;
		num2 = temp;
	}

	// Initialize the product and counter variables
	product = 0;
	counter = 0;

	while (counter < num2)
	{
		product += num1;
		counter++;
	}

	printf("The result of %d * %d is %d\n", num1, num2, product);
}