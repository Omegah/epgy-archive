/*
 * File: volumes.c
 * This program computes the volume of a shape chosen by the user, given its dimensions
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265358979

main()
{
	char *shape[8];
	float dimensions[3], volume;

	printf("This program computes the volume of a shape chosen by the user, given its dimensions\n");
	printf("Enter the shape you would like to compute the volume of (cube, cylinder or box): ");
	gets(shape);

	while (1)
	{
		if (!strcmp(shape, "cube"))
		{
			printf("Enter the side-length of the cube: ");
			scanf("%g", &dimensions[0]);
			volume = pow(dimensions[0], 3);
			printf("The volume of the cube is %g\n", volume);
			break;
		}
		else if (!strcmp(shape, "cylinder"))
		{
			printf("Enter the radius of the cylinder: ");
			scanf("%g", &dimensions[0]);
			printf("Enter the height of the cylinder: ");
			scanf("%g", &dimensions[1]);
			volume = PI * pow(dimensions[0], 2) * dimensions[1];
			printf("The volume of the cylinder is %g\n", volume);
			break;
		}
		else if (!strcmp(shape, "box"))
		{
			printf("Enter the width of the box: ");
			scanf("%g", &dimensions[0]);
			printf("Enter the length of the box: ");
			scanf("%g", &dimensions[1]);
			printf("Enter the height of the box: ");
			scanf("%g", &dimensions[2]);
			volume = dimensions[0] * dimensions[1] * dimensions[2];
			printf("The volume of the box is %g\n", volume);
			break;
		}
		else
		{
			printf("Invalid shape entered! Please enter cube, cylinder or box: ");
			gets(shape);
		}
	}
}