/*
 * File: prime.c
 * This program demonstrates the use of functions by including a function to check whether a number is prime
 */

#include <stdio.h>

int prime(int num);

main()
{
	int i;

	printf("This program uses a function to check whether a number is prime, and print it out - here the first 100 primes have been displayed\n");

	for (i = 1; i <= 100; i++)
	{
		if (prime(i))
		{
			printf("%d\n", i);
		}
	}
}

int prime(int num)
{
	int i;

	if (num <= 1) return 0;

	for (i = 2; i < num; i++)
	{
		if (num % i == 0) return 0;
	}

	return 1;
}