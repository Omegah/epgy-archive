#include <stdio.h>

int main(void)
{
	char string[80];

	printf("What is your name?\n");
	gets(string);
	printf("Hello, %s\n\n", string);
	return 0;
}
