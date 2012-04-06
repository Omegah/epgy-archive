/*
 * File: incDecPtr.c
 * This is a diagnostic program to show the effects of various operations with pointers
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
	int arr[3];
	int *p;
	int y;
	arr[0] = 15;
	arr[1] = 25;
	arr[2] = 35;

	printf("y = 15 at the beginning of the execution of each statement \n\n");

	p = &arr[0];
	y = ++*p;
	printf("y = ++*p;\t then y=%d, p=%Iu, *p=%d \n\n", y, p, *p);

	p = &arr[0];
	arr[0] = 15;
	y = *++p;
	printf("y = *++p;\t then y=%d, p=%Iu, *p=%d \n\n", y, p, *p);

	p = &arr[0];
	arr[0] = 15;
	y = *(++p);
	printf("y = *(++p);\t then y=%d, p=%Iu, *p=%d \n\n", y, p, *p);

	p = &arr[0];
	arr[0] = 15;
	p++, y = *p;
	printf("p++, y = *p;\t then y=%d, p=%Iu, *p=%d \n\n", y, p, *p);

	p = &arr[0];
	arr[0] = 15;
	y = ++(*p);
	printf("y = ++(*p);\t then y=%d, p=%Iu, *p=%d \n\n", y, p, *p);

	system("pause");
}