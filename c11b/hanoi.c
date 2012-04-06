/*
 * File: hanoi.c
 * This program uses a recursive function to calculate the moves needed to solve a towers of Hanoi algorithm
 */

#include <stdio.h>
#include <math.h>

void hanoi(int discs, char src, char dst, char help);

main()
{
	int numDiscs;
	printf("Enter the number of discs you would like to use: ");
	scanf("%d", &numDiscs);
	hanoi(numDiscs, 'A', 'C', 'B');
	printf("That took %g moves...\n", pow(2, numDiscs) - 1);
}

void hanoi(int discs, char src, char dst, char help)
{
	if (discs == 0)
	{
		return;
	}

	hanoi(discs - 1, src, help, dst);

	printf("Move disc #%d from tower %c to tower %c\n", discs, src, dst);

	hanoi(discs - 1, help, dst, src);
}