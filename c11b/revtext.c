/*
 * File: revtext.c
 * This program reverses the text entered and displays it to the user
 */

#include <stdio.h>
#include <string.h>

void reverse(void);

main()
{
	reverse();
}

void reverse()
{
	int i = 0, j;
	char s[256];
	printf("Enter a string to reverse:\n");
	while ((s[i] = getchar()) != EOF)
	{
		i++;
	}

	for (i = i; i < 256; i++)
	{
		s[i] = -1;
	}
	
	for (j = 255; j >= 0; j--)
	{
		if (s[j] != NULL && s[j] != EOF)
			printf("%c", s[j]);
	}

	printf("\n");
}