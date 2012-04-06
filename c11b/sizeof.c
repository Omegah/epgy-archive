/*
 * File: sizeof.c
 * This program checks how many bytes are required to store values of type int and values of type char
 */

#include <stdio.h>

main()
{
	printf("Size of int: %d byte(s)\n", sizeof(int));
	printf("Size of char: %d byte(s)\n", sizeof(char));
}