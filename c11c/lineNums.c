/*
 * File: lineNums.c
 * This program shows line numbers on input
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
	FILE *in;
	char tmpC;
	char tmpStr[31];
	char *filename = malloc(sizeof(char) * 32767);
	int i = 1;
	int wordcount = 0;
	int lettercount = 0;

	printf("This program shows line numbers on input\n");
	printf("Enter the file to read from:\n > ");
	gets_s(filename, 32766);

	fopen_s(&in, filename, "r");
	if (in == NULL)
	{
		printf("Could not open file. Please be sure the file exists and you have permission to read it.\n");
		exit(1);
	}

	/* Show output */
	printf("\n%d | ", i);
	while (fscanf_s(in, "%c", &tmpC) != EOF)
	{
		printf("%c", tmpC);
		if (tmpC == 10) { printf("%d | ", ++i); }
		lettercount++;
	}

	fseek(in, 0, 0);
	while (fscanf_s(in, "%s", tmpStr, 31) != EOF)
	{
		wordcount++;
	}

	printf("\n\nTotal lines: %d\nTotal words: %d\nTotal characters: %d\n\n", i, wordcount, lettercount);

	system("pause");
}