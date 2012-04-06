/*
 * File: binary.c
 * This program gets a number from zero to three and returns the binary representation of that number
 */

#include <stdio.h>

main()
{
	int input;
	int binary[] = { 0, 1, 10, 11 };

	printf("This program gets a number from zero to three and returns the binary representation of that number\n");
	printf("Enter a number from zero to three: ");
	scanf_s("%d", &input);

	if (input >= 0 && input <= 3)
	{
		printf("The binary code of %d is %02d\n", input, binary[input]);
	}
	else
	{
		printf("Your input, %d, was out of range\n", input);
	}
}

/* 01001001011001100010000001111001011011110111010100100000011100100110010101100001011001000010000001110100011010000110100101110011001011100010111000101110001000000110101001110101011100110111010000100000011100110110000101111001011010010110111001100111001000000110100001100101011011000110110001101111001000000011101000101001 */