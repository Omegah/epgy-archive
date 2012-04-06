/*
 * File: guess.c
 * This program reads your mind - no, actually it finds the number you are thinking of with the least possible amount of questions
 */

#include <stdio.h>
#include <string.h>

#define RANGELOW 1
#define RANGEHIGH 200

int guess(int low, int high);
void scanbool(char answer[4]);

main()
{
	int number = 0;

	printf("Think of an integer from %d to %d and I will guess it!\n\n", RANGELOW, RANGEHIGH);

	number = guess(RANGELOW, RANGEHIGH);
	if (number > 0) { printf("I have guessed your number! It was %d!\n", number); }
}

int guess(int low, int high)
{
	int guessed = 0;
	int minpossible = low;
	int maxpossible = high;
	int not = 0;
	int number = high / 2;
	char answer[4];
	while (guessed == 0)
	{
		if (number < minpossible || number > maxpossible) { printf("That's not possible...\n"); return 0; }

		printf("Is the number %d? ", number);
		scanbool(answer);
		if (strcmp(answer, "yes") == 0) return number; else not = number;

		if (number == maxpossible) maxpossible -= 1;
		if (number == minpossible) minpossible += 1;

		if (minpossible == maxpossible) return minpossible;

		printf("Is the number less than %d? ", number);
		scanbool(answer);
		if (strcmp(answer, "yes") == 0)
		{
			maxpossible = number - 1;
			number = minpossible + ((maxpossible - minpossible) / 2);
			if (number < minpossible) number = minpossible;
			if (number > maxpossible) number = maxpossible;
		}
		else
		{
			minpossible = number + 1;
			number = maxpossible - ((maxpossible - minpossible) / 2) - ((maxpossible - minpossible) % 2);
			if (number < minpossible) number = minpossible;
			if (number > maxpossible) number = maxpossible;
		}

		if (maxpossible == not) maxpossible -= 1;
		if (minpossible == not) minpossible += 1;

		if (minpossible == maxpossible) return minpossible;
	}
}

void scanbool(char answer[4])
{
	printf("Please enter \"yes\" or \"no\": ");
	gets(answer);
}