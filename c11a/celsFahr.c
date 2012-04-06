/*
 * File: celsFahr.c
 * This program displays the table of Fahrenheit to Celsius temperatures
 */

#include <stdio.h>
#define stepAmount 20
#define maxTemp 200

main()
{
	int i;

	printf("Fahrenheit\tCelsius\n");
	for (i = 0; i <= maxTemp; i += stepAmount)
	{
		printf("%d\t\t%.1f\n", i, ((5.0 / 9.0) * (i - 32.0)));
	}
}