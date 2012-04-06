/*
 * File: fib.c
 * This program gets the nth number in the Fibonacci sequence
 */

#include <stdio.h>

int fib(int seq);
char* getOrdSuffix(int i);

main()
{
	int seq;
	printf("This program gets the nth number in the Fibonacci sequence\n");
	printf("Which position in the sequence would you like to get the number at?\n");
	printf("Enter number: ");
	scanf("%d", &seq);
	printf("The %d%s number in the Fibonacci sequence is: %d\n", seq, getOrdSuffix(seq), fib(seq));
}

int fib(int seq)
{
	if (seq <= 0) return 0;
	if (seq == 1) return 1;
	else return (fib(seq - 1) + fib(seq - 2));
}

char* getOrdSuffix(int i)
{
	int lastDigit;
	char* os;
	/* Determine ordinal suffix */
	lastDigit = i % 10;
	if (i >= 4 && i <= 20)
		os = "th";
	else if (i == 0 || lastDigit == 0)
		os = "th";
	else if (i == 1 || lastDigit == 1)
		os = "st";
	else if (i == 2 || lastDigit == 2)
		os = "nd";
	else if (i == 3 || lastDigit == 3)
		os = "rd";
	else
		os = "th";

	return os;
}