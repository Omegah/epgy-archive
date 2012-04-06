/*
 * File: pascalTriangle.c
 * This program displays the first 7 rows of Pascal's triangle
 */

#include <stdio.h>

#define SHOW_ROWS 7

int fac(int num);
int getPos(int x, int y);

main()
{
	int i, j, t;
	for (i = 1; i <= SHOW_ROWS; i++)
	{
		for (t = 0; t < (SHOW_ROWS - i); t++)
		{
			printf("   ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("%d      ", getPos(i - 1, j - 1));
		}
		printf("\n");
	}
}

int fac(int num)
{
	int i, fac = num;

	if (num <= 0) return 1;
	for (i = 1; i < num; i++)
	{
		fac *= i;
	}
	return fac;
}

int getPos(int x, int y)
{
	return (fac(x) / (fac(y) * fac(x - y)));
}