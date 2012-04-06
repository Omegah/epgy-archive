/*
 * File: average4.c
 * This program computes the average of four grades
 */

#include <stdio.h>

main()
{
	float average;
	float grade[4];
	int i;

	printf("This program computes the average of four grades.\n");

	for (i = 0; i < 4; i++)
	{
		printf("Enter grade number %d: ", i + 1);
		scanf("%f", &grade[i]);
	}

	average = (grade[0] + grade[1] + grade[2] + grade[3]) / 4;

	printf("Your grades were: %g %g %g %g\n", grade[0], grade[1], grade[2], grade[3]);
	printf("Your average grade is %g\n", average);
}