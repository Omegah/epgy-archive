/*
 * File: stars8.c
 * This program displays a square of stars
 */

#include <stdio.h>

main()
{
	int i, j;

	printf("This program displays a square of stars\n");

	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}