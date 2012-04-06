/*
 * File: letterCount.c
 * Counts the frequencies of letters in a file
 */

#include <stdio.h>
#include <stdlib.h>

#define maxLetters 26

void initArray(int letters[]); /* prototypes */
void frequencies(int letters[], char ch);
void displayCounts(int letters[]);

main()
{
	FILE *in;
	char *filename = malloc(sizeof(char) * 32767);
	char charBuffer;
	int letters[maxLetters];

	printf("This program counts the frequencies of the letters in a file...\n");
	printf("Enter the name of the file to read from:\n > ");
	gets_s(filename, 32766);

	fopen_s(&in, filename, "r");
	if (in == NULL)
	{
		printf("Unable to open file. Please be sure the file exists and you have permission to read it.");
		system("pause");
		exit(1);
	}

	initArray(letters);

	while (fscanf_s(in, "%c", &charBuffer) != EOF)
	{
		frequencies(letters, charBuffer);
	}

	displayCounts(letters);

	system("pause");
}

/* initArray */
/* This procedure initializes the array and sets the elements values to 0 */
void initArray(int letters[])
{
	int I;
	for (I = 0; I < maxLetters; I++)
	{
		letters[I] = 0;
	}
}

void frequencies(int letters[], char ch)
{
	int index;
	if ((ch >= 'A') && (ch <= 'Z'))
	{
		index = ch - 65;
		letters[index] = letters[index] + 1;
	}

	if ((ch >= 'a') && (ch <= 'z'))
	{
		index = ch - 97;
		letters[index] = letters[index] + 1;
	}
}

/* displayCounts */
/* This procedure displays the letter frequencies of the letters that appeared in the text */
void displayCounts(int letters[])
{
	char ch;
	int count, index;
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		index = ch - 65;
		count = letters[index];
		if (count != 0)
		{
			printf ("%c %4d\n", ch, count);
		}
	}
}