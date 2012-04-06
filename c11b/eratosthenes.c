/*
 * File: eratosthenes.c
 * This program demonstrates the Sieve of Eratosthenes
 */

#include <stdio.h>
#include <math.h>

#define SIZE 300

main()
{
	int is_prime[SIZE + 1], i, j, k, l, ij, count = SIZE - 1, sqrtn = sqrt(SIZE + 1);

	for (k = 0; k < SIZE + 1; k++)
	{
		is_prime[k] = 1;
	}

	is_prime[0] = 0;
	is_prime[1] = 0;

	for (i = 2; i < sqrtn; i++)
	{
		if (is_prime[i] != 0)
		{
			for (j = 2; j < SIZE + 1; j++)
			{
				ij = i * j;
				if (ij < SIZE + 1)
				{
					if (is_prime[ij] != 0)
					{
						is_prime[ij] = 0;
						count--;
					}
				}
			}
		}
	}

	printf("This program demonstrates the Sieve of Eratosthenes\n");
	printf("There are %d primes in the range of 1 to %d:\n", count, SIZE);

	for (l = 2; l < SIZE + 1; l++)
	{
		if (is_prime[l])
		{
			printf("%d\n", l);
		}
	}
}