/*
 * File: fibonacci.c
 * This program displays the Nth number in the fibbonacci sequence
 */

#include <stdio.h>

int fibonacci(int num);

main()
{
	int input;
	printf("This program displays the Nth number in the fibbonacci sequence\n");
	printf("Enter a number to find the fibonacci number at that position in the sequence: ");
	scanf("%d", &input);

	printf("f(%d)=%d\n", input, fibonacci(input));
}

int fibonacci(int num)
{
	int i, nFib_2 = 1, nFib_1 = 1, nFib = 0;
	for (i = 0; i < num; i++)
	{
		if (num <= 0) return 0;

		nFib_2 = nFib_1;
		nFib_1 = nFib;
		nFib = nFib_2 + nFib_1;
	}

	return nFib;
}