/*
 * File: fracts.c
 * This program computes the sum of fractions with denominator from 1 to n
 */

#include <stdio.h>

float fracts(float n);

main()
{
	int n;
	printf("This program computes the sum of fractions with denominator from 1 to n\nEnter a number to pass to fracts()\n");
	scanf("%d", &n);
	printf("The answer is: %.2f\n", fracts(n));
}

float fracts(float n)
{
	float sum = 0.0;
	if (n <= 0)
	{
		return 0;
	}
	else
	{
		while (n > 0)
		{
			sum = sum + 1 / n;
			n = n - 1;
		}
		return sum;
	}
}