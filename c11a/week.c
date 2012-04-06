/*
 * File: week.c
 * This program translates an integer into the corresponding day of the week
 */

#include <stdio.h>

main()
{
	int dayofweek;
	char *days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	printf("This program translates an integer into the corresponding day of the week\n");
	printf("Enter an integer from one to seven: ");
	scanf("%d", &dayofweek);

	if (dayofweek >= 1 && dayofweek <= 7)
	{
		printf("%s\n", days[dayofweek - 1]);
	}
	else
	{
		printf("The number you entered, %d, is out of range\n", dayofweek);
	}
}