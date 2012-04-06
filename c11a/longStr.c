/*
 * File: longStr.c
 * This program reads a list of strings entered by the user and find the longest one
 */

#include <stdio.h>
#include <string.h>

main()
{
	char input[256], longest[256];

	printf("This program reads a list of strings entered by the user and find the longest one\n");
	printf("Enter a string: ");
	gets(input);
	strcpy(longest, input);

	while (strcmp(input, "end"))
	{
		if (strlen(input) > strlen(longest))
		{
			strcpy(longest, input);
		}

		printf("Enter a string: ");
		gets(input);
	}

	printf("The longest string entered was \"%s\"\n", longest);
}