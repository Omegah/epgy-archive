/*
 * File: perfectNum.c
 * This program displays "perfect" integers
 * A positive integer is perfect if the sum of all its divisors smaller than itself, add up to the number
 */

#include <stdio.h>

int isPerfectNumber(int num);

main()
{
	int i;
	printf("The perfect numbers in the range 1 - 100:\n");
	for (i = 1; i <= 100; i++)
	{
		if (isPerfectNumber(i)) printf("%d\n", i);
	}
}

int isPerfectNumber(int num)
{
	int i, divisorSum = 0;

	for (i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			divisorSum += i;
		}
	}

	return (divisorSum == num);
}