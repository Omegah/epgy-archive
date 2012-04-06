/*
 * File: reverse.c
 * This program reverses a number
 */

#include <stdio.h>

main()
{
	int num, temp;
	char *cont = 'y';

	printf("This program reverses a number\n");

	while (cont == 'y' || cont == 'Y')
	{
		printf("Enter a number: ");
		scanf("%d", &num);

		while (num > 0)
		{
			temp = num % 10;
			num = num / 10;
			printf("%d", temp);
		}
		printf("\n");

		printf("Would you like to try another number? ( Y / N )\n");
		scanf("%s", &cont);
	}
}