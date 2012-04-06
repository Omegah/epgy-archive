/*
 * File: positive.c
 * This program checks to see if the number entered is even or odd, and informs
 * the user of the result, as well as displaying the absolute value of the number
 */

#include <stdio.h>
#include <math.h>

main()
{
	int num, abs;

	printf("This program checks to see if the number entered is even or odd, and informs\nthe user of the result, as well as displaying the absolute value of the number\n");

	printf("Enter a number: ");
	scanf("%d", &num);

	abs = fabs(num);

	if (num > 0)
	{
		printf("The number %d is positive and its absolute value is %d\n", num, abs);
	}
	else if (num < 0)
	{
		printf("The number %d is negative and its absolute value is %d\n", num, abs);
	}
	else /* It's exactly zero */
	{
		printf("The number 0 is neither positive nor negative and its absolute value is 0\n");
	}
}