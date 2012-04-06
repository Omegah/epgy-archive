/*
 * File: skipBlanks.c
 * This program reads a file and outputs it with no spaces
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
	FILE *in, *out;
	char *infile = malloc(sizeof(char) * 32767), *outfile = malloc(sizeof(char) * 32767);
	char filedata;

	printf("Type the name of the input file and press enter\n > ");
	gets_s(infile, 32766);
	printf("Type the name of the output file and press enter\n > ");
	gets_s(outfile, 32766);

	fopen_s(&in, infile, "r");
	if (in == NULL)
	{
		printf("Input file could not be read. Please be sure the file exists and you have sufficient permissions to access it.\n");
		system("pause");
		exit(1);
	}

	fopen_s(&out, outfile, "w");
	if (out == NULL)
	{
		printf("Output file could not be opened for writing. Please be sure the file exists and you have sufficient permissions to access it.\n");
		system("pause");
		exit(1);
	}

	while (fscanf_s(in, "%c", &filedata) == 1)
	{
		if (filedata != 32)
		{
			fprintf(out, "%c", filedata);
		}
	}

	printf("The file \"%s\" has been written.\n", outfile);

	fclose(in);
	fclose(out);

	system("pause");
}