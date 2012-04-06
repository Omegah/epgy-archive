/*
 * File: fractSum.c
 * This program uses a recursive function to add the numbers from 1/2 to n/n+1
 */

#include <stdio.h>

float sum(float n);

main()
{
	float number = 8;

	printf("This program uses a recursive function to add the numbers from 1/2 to n/n+1\n");
	printf("sum(%g) = %.2f\n", number, sum(number));
}

float sum(float n)
{
	if (n <= 0) return 0;
	else return (sum(n - 1) + n/(n+1));
}