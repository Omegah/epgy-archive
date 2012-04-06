/*
 * File: addMul.c
 * This program computes the sum and product of two numbers
 */

#include <stdio.h>

main()
{
	int num1, num2, sum, product;

	printf("This program adds and multiplies two numbers.\n");
	printf("Enter 1st number: ");
	scanf("%d", &num1);
	printf("Enter 2nd number: ");
	scanf("%d", &num2);

	sum = num1 + num2;
	product = num1 * num2;

	printf("The sum of %d and %d is: %d\n", num1, num2, sum);
	printf("The product of %d and %d is: %d\n", num1, num2, product);
}