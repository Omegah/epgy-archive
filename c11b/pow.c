/*
 * File: pow.c
 * This program includes and uses a recursive power function
 */

#include <stdio.h>

float pow(float b, int p);

main()
{
	float base;
	int power;

	printf("This program includes and uses a recursive power function\n");
	printf("Please enter the base: ");
	scanf("%g", &base);
	printf("Please enter the power: ");
	scanf("%d", &power);
	printf("pow(%g, %d) = %g\n", base, power, pow(base, power));
}

float pow(float b, int p)
{
	if (b == 0 && p <= 0) return 0;
	if (b != 0 && p == 0) return 1;

	if (p > 0)
	{
		return pow(b, p - 1) * b;
	}
	else
	{
		return 1 / pow(b, -p);
	}
}