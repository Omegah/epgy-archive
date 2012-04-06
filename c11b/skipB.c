/*
 * File: skipB.c
 * This program repeats the user's output with any spacing characters removed
 */

#include <stdio.h>

main()
{
	char c;
	printf("Enter some text; it will be displayed back to you without any spacing characters\nPress Ctrl+Z and press Enter to exit the program\n\n");
	while ((c = getchar()) != EOF)
	{
		if (c == '\n' || c >= 33)
		{
			printf("%c", c);
		}
	}
}