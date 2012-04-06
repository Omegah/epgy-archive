/*
 * File: fillShapes.c
 * This program outputs a filled version of a shape that you enter
 */

typedef int bool;

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

#define SIZE 25

void fill(char arr[][SIZE], int row, int col);

main()
{
	char arr[SIZE][SIZE];
	int i = 0, j, strln = 0;
	int x = 0, y = 0;
	bool wasPrinted = false;

	printf("This program outputs a filled version of a shape that you enter\nThe max grid size is 25x25\nPlease enter a point in your shape where you would like to begin filling:\n");
	printf("X = ");
	scanf("%d", &x);
	printf("Y = ");
	scanf("%d", &y);

	printf("Please enter your shape outline now, using the * character\n");
	gets(arr[i]);

	while (i < SIZE)
	{
		if (strcmp(gets(arr[i]), "") == 0) break;
		strln = (strlen(arr[i]) > strln) ? strlen(arr[i]) : strln;
		i++;
	}

	fill(arr, x, y);
	/*fill(arr, (strln / 2) - 1, (i / 2) - 1);*/

	for (i = 0; i < SIZE; i++)
	{
		wasPrinted = false;
		for (j = 0; j < SIZE; j++)
		{
			if (arr[i][j] >= 32)
			{
				wasPrinted = true;
				printf("%c", arr[i][j]);
			}
		}
		if (wasPrinted) printf("\n");
	}
	printf("\n");
}

void fill(char arr[][SIZE], int x, int y)
{
	int fillL, fillR, i;
	int in_line = 1;

	/* Find left side, filling along the way */
	fillL = fillR = x;
	while (in_line)
	{
		arr[y][fillL] = '*';
		fillL--;
		in_line = (fillL < 0) ? 0 : (arr[y][fillL] == ' ');
	}
	fillL++;

	/* Find right side, filling along the way */
	in_line = 1;
	while (in_line)
	{
		arr[y][fillR] = '*';
		fillR++;
		in_line = (fillR > SIZE - 1) ? 0 : (arr[y][fillR] == ' ');
	}
	fillR--;

	/* Search top and bottom */
	for (i = fillL; i <= fillR; i++)
	{
		if (y > 0 && arr[y - 1][i] == ' ')
		{
			fill(arr, i, y - 1);
		}
		if (y < SIZE - 1 && arr[y + 1][i] == ' ')
		{
			fill(arr, i, y + 1);
		}
	}
}