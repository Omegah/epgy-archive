/*
 * File: volume.c
 * This program computes the volume of a cube after reading the side's face value from the user
 */

#include <stdio.h>
#include <math.h>

main()
{
	int face, volume;

	printf("This program computes the volume of a cube after reading the side's face value from the user.\n");
	printf("Enter the face value of a side: ");

	scanf("%d", &face);
	volume = pow(face, 3);

	printf("The volume of a cube with side = %d is %d\n", face, volume);
}