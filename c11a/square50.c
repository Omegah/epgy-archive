/*
 * File: square50.c
 * This program that computes and displays all the squares of the numbers from 1 to 50.
 */

#include <stdio.h>

main()
{
	int i;

	printf("This program that computes and displays all the squares of the numbers from 1 to 50\n");

	for (i = 1; i <= 50; i++)
	{
		printf("%d\t%d\n", i, i*i);
	}
}