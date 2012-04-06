/*
 * File: revint.c
 * This program reverses the integer entered and displays it to the user
 */

#include <stdio.h>

void reverse(void);

main()
{
	reverse();
}

void reverse()
{
	int i, num;
	printf("Enter an integer to reverse:\n");
	scanf("%d", &num);

	while (num > 0)
	{
		printf("%d", num % 10);
		num /= 10;
	}

	printf("\n");
}