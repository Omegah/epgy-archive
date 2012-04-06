/*
 * File: multiArray.c
 * This program uses a two - dimensional array to find the elements that are larger than all their neighbors
 */

#include <stdio.h>

#define size 3

int checkNeighbors(int ne[size][size], int i, int j);

main()
{
	int g, h, i, j;
	int ne[size][size];

	printf("This program uses a two - dimensional array to find the elements that are larger than all their neighbors\n\n");

	for (g = 0; g < size; g++)
	{
		for (h = 0; h < size; h++)
		{
			printf("Enter value at position (%d, %d): ", g, h);
			scanf("%d", &ne[g][h]);
		}
	}

	printf("\nThe elements that are larger than all their neighbors are:\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (checkNeighbors(ne, i, j))
			{
				printf("%d in location (%d, %d)\n", ne[i][j], i, j);
			}
		}
	}
}

int checkNeighbors(int ne[size][size], int i, int j)
{
	if (i <= size - 2)
	{
		if (!(ne[i][j] > ne[i+1][j]))
		{
			return 0;
		}
	}

	if (j <= size - 2)
	{
		if (!(ne[i][j] > ne[i][j+1]))
		{
			return 0;
		}
	}

	if (i <= size - 2 && j <= size - 2)
	{
		if (!(ne[i][j] > ne[i+1][j+1]))
		{
			return 0;
		}
	}

	if (i >= 1)
	{
		if (!(ne[i][j] > ne[i-1][j]))
		{
			return 0;
		}
	}

	if (j >= 1)
	{
		if (!(ne[i][j] > ne[i][j-1]))
		{
			return 0;
		}
	}

	if (i >= 1 && j >= 1)
	{
		if (!(ne[i][j] > ne[i-1][j-1]))
		{
			return 0;
		}
	}

	if (i >= 1 && j <= size - 2)
	{
		if (!(ne[i][j] > ne[i-1][j+1]))
		{
			return 0;
		}
	}

	if (i <= size - 2 && j >= 1)
	{
		if (!(ne[i][j] > ne[i+1][j-1]))
		{
			return 0;
		}
	}

	return 1;
}