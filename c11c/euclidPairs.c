/*
 * File: euclidPairs.c
 * This program read pairs from an input file and displays their GCDs (calculated using Euclid's algorithm) to the screen
 */

#include <stdio.h>
#include <stdlib.h>

int euclid(int num1, int num2);

main()
{
	FILE *in;
	char *filename = malloc(sizeof(char) * 32767);
	int val1, val2;

	printf("This program read pairs from an input file and displays their GCDs (calculated\nusing Euclid's algorithm) to the screen\n");
	printf("Enter the filename of the file to read values from:\n > ");
	gets_s(filename, 32766);

	fopen_s(&in, filename, "r");
	if (in == NULL)
	{
		printf("Failed opening file. Please be sure the file exists and you have permission to read it.\n");
		system("pause");
		exit(1);
	}

	while (fscanf_s(in, "%d %d", &val1, &val2) != EOF)
	{
		printf("The GCD of %d and %d is %d\n", val1, val2, euclid(val1, val2));
	}

	fclose(in);

	system("pause");
}

int euclid(int num1, int num2)
{
	int temp, orig1, orig2, rem;

	if (num1 > num2)
	{
		temp = num2;
		num2 = num1;
		num1 = temp;
	}

	orig1 = num1;
	orig2 = num2;

	rem = num1 % num2;

	while (rem != 0)
	{
		num1 = num2;
		num2 = rem;
		rem = num1 % num2;
	}

	return num2;
}