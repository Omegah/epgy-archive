/*
 * File: games.c
 * This program displays the scores of the basketball games for 1 season
 */

#include <stdio.h>

main()
{
	int i, k, j;
	char league[256];
	int numGames;
	char teams[4][256];
	float gamesWon[4];
	float percentage;

	printf("This program displays the scores of the basketball games for 1 season\n\n");

	printf("Enter the name of the league: ");
	gets(league);
	printf("Enter the total number of games played in the season (per team): ");
	scanf("%d", &numGames);
	fflush(stdin);

	for (i = 0; i < 4; i++)
	{
		printf("Enter the name of team %d: ", i + 1);
		gets(teams[i]);
	}

	for (k = 0; k < 4; k++)
	{
		printf("How many games did the team %s win? ", teams[k]);
		scanf("%g", &gamesWon[k]);
		fflush(stdin);
	}

	printf("\nLeague: %s\n\n", league);
	printf("|-----------------------------------------------------------------------|\n");
	printf("| %-30s | %s | %s | %s |\n", "Team", "Total Games", "Games Won", "Percentage");
	printf("|-----------------------------------------------------------------------|\n");
	for (j = 0; j < 4; j++)
	{
		percentage = (gamesWon[j] / numGames) * 100;
		printf("| %-30s | %-11d | %-9g | %-10.4g |\n", teams[j], numGames, gamesWon[j], percentage);
	}
	printf("|-----------------------------------------------------------------------|\n\n");

	system("pause");
}