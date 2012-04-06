/*
 * File: palind.c
 * This program checks to see if a word is a palindrome
 */

typedef int bool;
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>

bool doCheck(void);
bool isPalindrome(char word[256]);

main()
{
	bool cont = TRUE;
	printf("This program checks to see if a word is a palindrome - enter \"end\" when you are done\n\n");
	while (cont == TRUE)
	{
		cont = doCheck();
	}
}

bool doCheck()
{
	char word[256];

	printf("Enter a word to check: ");
	scanf("%s", &word);

	printf("%s is%sa palindrome\n\n", word, (isPalindrome(word) ? " " : " NOT "));

	return (!(word[0] == 'e' && word[1] == 'n' && word[2] == 'd' && word[3] == '\0'));
}

bool isPalindrome(char word[256])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < (length / 2); i++)
	{
		if (!(word[i] == word[length - 1 - i]))
		{
			return FALSE;
		}
	}
	return TRUE;
}