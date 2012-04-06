/*
 * File: factorial.c
 * This program computes the factorials in a certain range
 */

#include <stdio.h>

#define facStart 1
#define facEnd 10

main()
{
	int i, j;
	long facTmp = 1;
	for (i = facStart; i <= facEnd; i++)
	{
		for (j = 1; j <= i; j++)
		{
			facTmp *= j;
		}
		printf("%d\t%lu\n", i, facTmp);
		facTmp = 1;
	}
}