/*
 * File: summer.c
 * This program checks to see if a month is in the summer
 */

#include <stdio.h>

main()
{
	int num;
	char notInSummer[] = "The month is not in the summer\n";

	printf("This program checks to see if a month is in the summer\nEnter the number of the month: ");
	scanf("%d", &num);

	switch (num)
	{
		case 1: printf(notInSummer); break;
		case 2: printf(notInSummer); break;
		case 3: printf(notInSummer); break;
		case 4: printf(notInSummer); break;
		case 5: printf(notInSummer); break;
		case 6: printf("June\n"); break;
		case 7: printf("July\n"); break;
		case 8: printf("August\n"); break;
		case 9: printf(notInSummer); break;
		case 10: printf(notInSummer); break;
		case 11: printf(notInSummer); break;
		case 12: printf(notInSummer); break;
		default: printf("Your input is out of range\n"); break;
	}
}