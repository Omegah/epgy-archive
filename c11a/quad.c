/*
 * File.c
 * This program solves a quadratic equation
 */

#include <stdio.h>
#include <math.h>

main()
{
	int inputs[3], a, b, c, d, x, x1, x2, i, lastDigit;
	char *os, *noSol = "No solution\n", *cont = 'y';

	while (cont == 'Y' || cont == 'y')
	{
		printf("This program solves a quadratic equation\n");
		for (i = 1; i <= 3; i++)
		{
			/* BEGIN Determine ordinal suffix */
			lastDigit = i % 10;
			if (i >= 4 && i <= 20)
				os = "th";
			if (i == 1 || lastDigit == 1)
				os = "st";
			else if (i == 2 || lastDigit == 2)
				os = "nd";
			else if (i == 3 || lastDigit == 3)
				os = "rd";
			else
				os = "th";
			/* END Determine ordinal suffix */

			printf("Enter your %d%s number: ", i, os);
			scanf("%d", &inputs[i - 1]);
		}

		a = inputs[0];
		b = inputs[1];
		c = inputs[2];

		while (1)
		{
			if (a == 0)
			{
				if (b == 0)
				{
					printf(noSol);
					break;
				}
				else
				{
					x = -c / b;
					printf("The equation is not quadratic and the solution is %d\n", x);
					break;
				}
			}
			else
			{
				d = pow(b, 2) - 4 * a * c;
				if (d < 0)
				{
					printf(noSol);
					break;
				}
				else if (d == 0)
				{
					x1 = -b / 2 * a;
					printf("One solution: %d\n", x1);
					break;
				}
				else /* if (d > 0) */
				{
					x1 = (-b + sqrt(d)) / 2 * a;
					x2 = (-b - sqrt(d)) / 2 * a;
					printf("Two solutions: %d and %d\n", x1, x2);
					break;
				}
			}
		}

		printf("Would you like to run the program again? ( Y / N )\n");
		scanf("%s", &cont);
	}
}