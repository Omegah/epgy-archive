/*
 * File: prime.c
 * This program displays all the prime numbers from 50 to 100
 */

#include <stdio.h>

main()
{
	int i, j, isPrime;

	printf("This program displays all the prime numbers from 50 to 100\n");

	for (i = 50; i <= 100; i++)
	{
		isPrime = 1;
		for (j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				isPrime = 0;
				break;
			}
		}
		printf((isPrime == 1) ? "%d\n" : "", i);
	}
}