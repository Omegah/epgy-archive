/*
 * File: ticTacToe.c
 * This program plays Tic Tac Toe with you!
 * Thanks to Steve Chapel (schapel@cs.ucsb.edu) for posting some of the code implemented in this program
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* Boolean definition */
typedef int bool;
#define true 1
#define false 0

/* Checking to see if someone won, it was a draw, or the game is still running */
#define COMPUTER 0
#define HUMAN 1
#define DRAW 2
#define CONTINUE 3

#define COMPPIECE 'X'
#define HUMANPIECE 'O'

#define String_Length 80
#define Squares 9
typedef char Square_Type;
typedef Square_Type Board_Type[Squares];
const Square_Type Empty = ' ';
const int Infinity = 10;		/* Higher value than any score */
const int Maximum_Moves = Squares;	/* Maximum moves in a game */
int Total_Nodes;			/* Nodes searched with minimax */
/* Array describing the eight combinations of three squares in a row */
#define Possible_Wins 8
const int Three_in_a_Row[Possible_Wins][3] =
{
    { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 },
    { 0, 3, 6 },
    { 1, 4, 7 },
    { 2, 5, 8 },
    { 0, 4, 8 },
    { 2, 4, 6 }
};
/* Array used in heuristic formula for each move. */
const int Heuristic_Array[4][4] =
{
    {     0,   -10,  -100, -1000 },
    {    10,     0,     0,     0 },
    {   100,     0,     0,     0 },
    {  1000,     0,     0,     0 }
};
/* Structure to hold a move and its heuristic */
typedef struct
{
    int Square;
    int Heuristic;
}
Move_Heuristic_Type;
void Describe(int Score);
void Move(Board_Type Board, Square_Type Player, int Move_Nbr);
void Game();
void Initialize(Board_Type Board);
Square_Type Winner(Board_Type Board);
Square_Type Other(Square_Type Player);
void Play(Board_Type Board, int Square, Square_Type Player);
void Print(Board_Type Board);
int Evaluate(Board_Type Board, Square_Type Player);
int Best_Move(Board_Type Board, Square_Type Player, int *Square, int Move_Nbr, int Alpha, int Beta);

void displayBoard(char positions[9], char * mode);
void doComputerMove(char positions[9], char modeChoice);
bool checkPositionOccupied(char positions[9], int mappedNumber);
int gameOver(char positions[9]);

main()
{
	/* Maps the numpad keys so that pressing them physically corresponds to a Tic Tac Toe board */
	/* This is explained when the game starts */
	int keyboardNums[9] = { 6, 7, 8, 3, 4, 5, 0, 1, 2 }, i;

	/* Position the player chooses for the next move */
	int nextMovePosition;

	/* The player's letter */
	char nextLetter = HUMANPIECE;

	/* The board; a piece is denoted by (' ', 'X' or 'O') */
	char positions[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	/* If we are still playing the game */
	bool playing = true;

	/* The "winner", this is what the (COMPUTER/HUMAN/DRAW/CONTINUE) constants are for */
	int winner;

	/* The winner for the message displayed at the end of the game */
	char * strWinner = "";

	/* For storing the mode the user wants to play in */
	char modeChoice = ' ';

	/* For storing whether we want to continue */
	char Answer[String_Length];

	do
	{
		printf("-------\n");
		printf(" T I C \n");
		printf("--+-+--\n");
		printf(" T A C \n");
		printf("--+-+--\n");
		printf(" T O E \n");
		printf("-------\n");
		printf("\n~\\* Welcome to Tic Tac Toe! */~\n\n");

		printf("%c = Computer\n", COMPPIECE);
		printf("%c = You\n", HUMANPIECE);
		printf("\nPress the numpad keys on the right of your keyboard to select which square to\nplay. The board and numpad are mapped to each other, so entering '7' would placea piece in the top-left square, '5' would place a piece in the middle, etc.\nGood luck!\n\n");

		printf("There are two modes available to play:\nNORMAL MODE - This mode tries to simulate a human vs. human game where either\nthe player or the computer can win or draw.\nINVINCIBLE MODE - In this mode, the computer will never lose. The game will\nalways result in the computer winning, or a draw.\n");
		printf("Enter 'N' for normal mode, or 'I' for invincible mode (without the quotes): ");
		modeChoice = getchar();

		while (modeChoice != 'N' && modeChoice != 'n' && modeChoice != 'I' && modeChoice != 'i')
		{
			printf("That is not a valid mode. Please choose N or I: ");
			modeChoice = getchar();
		}

		if (modeChoice == 'I' || modeChoice == 'i')
		{
			Game();
		}
		else
		{
			displayBoard(positions, (modeChoice == 'I' || modeChoice == 'i') ? "{ INVINCIBLE } mode" : "Normal mode");

			/* Game loop */
			while (playing)
			{
				printf("Enter the position you would like to place a move: ");
				scanf_s("%d", &nextMovePosition);

				/* Do not stop until a valid position is reached */
				while (checkPositionOccupied(positions, nextMovePosition))
				{
					printf("That space is already occupied. Please choose a different location: ");
					scanf_s("%d", &nextMovePosition);
				}

				/* Set the position chosen */
				positions[keyboardNums[nextMovePosition - 1]] = nextLetter;

				/* Is the game ended? */
				playing = (gameOver(positions) == CONTINUE);

				/* If the game has not ended, have the computer move */
				if (playing) doComputerMove(positions, modeChoice);

				/* Is the game ended? */
				playing = (gameOver(positions) == CONTINUE);

				/* Display the board */
				displayBoard(positions, (modeChoice == 'I' || modeChoice == 'i') ? "{ INVINCIBLE } mode" : "Normal mode");

				/* If the game has been ended by some means, display an appropriate message and exit the game loop */
				if (playing == false)
				{
					winner = gameOver(positions);
					switch (winner)
					{
						case COMPUTER: strWinner = "computer wins"; break;
						case HUMAN: strWinner = "human wins"; break;
						case DRAW: strWinner = "draw"; break;
					}
					printf("Game over: %s!\n", strWinner);
					break;
				}
			}

			/* BEGIN reset game */
			for (i = 0; i < 9; i++)
			{
				positions[i] = ' ';
			}

			nextMovePosition = -1;
			winner = CONTINUE;
			playing = true;
			modeChoice = ' ';
			/* END reset game */
		}

		printf("\nDo you want to play another game? ");
		scanf("%s", Answer);
	}
	while (toupper(Answer[0]) == 'Y');
}

/* Displays the board */
void displayBoard(char positions[9], char * mode)
{
	printf("\n\n\n\n\n\n%s\n\n%c = Computer\n%c = You\n\n", mode, COMPPIECE, HUMANPIECE);
	printf("+-------+-------+-------+\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", positions[0], positions[1], positions[2]);
	printf("|       |       |       |\n");
	printf("+-------+-------+-------+\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", positions[3], positions[4], positions[5]);
	printf("|       |       |       |\n");
	printf("+-------+-------+-------+\n");
	printf("|       |       |       |\n");
	printf("|   %c   |   %c   |   %c   |\n", positions[6], positions[7], positions[8]);
	printf("|       |       |       |\n");
	printf("+-------+-------+-------+\n");
}

/* Makes the computer do a move */
void doComputerMove(char positions[9], char modeChoice)
{
	/* Number of pieces on board, index of the last found player piece */
	int valuesFound = 0, valueFoundIndex = -1, i, j;
	char computerPiece = COMPPIECE;
	char playerPiece = HUMANPIECE;

	/* The random space to move to */
	int random = 0;

	/* If the computer has taken its move */
	bool moved = false;

	/* Seed the random number generator */
	srand((int)time(NULL));

	for (i = 0; i < 9; i++)
	{
		if (positions[i] != ' ')
		{
			valuesFound++;
		}
		else if (positions[i] == playerPiece)
		{
			valueFoundIndex = i;
		}
	}

	/* Game over... */
	if (valuesFound == 9)
		return;
	
	if (modeChoice == 'N' || modeChoice == 'n')
	{
		while (moved == false)
		{
			random = rand() % 8;
			for (j = 0; j < 9; j++)
			{
				if (j == random && positions[j] == ' ')
				{
					positions[j] = computerPiece;
					moved = true;
					break;
				}
			}
		}
	}
}

/* Checks if the keyboard mapped position (e.g. 7 = top-left corner) is occupied */
bool checkPositionOccupied(char positions[9], int mappedNumber)
{
	int keyboardNums[9] = { 6, 7, 8, 3, 4, 5, 0, 1, 2 };
	return (!(positions[keyboardNums[mappedNumber - 1]] == ' '));
}

/* Checks if the game is over by computer win, player win, draw, or the game is not over */
int gameOver(char positions[9])
{
	/* This is a bit of a long method but there isn't much other way */
	if 
	(
		(positions[0] == COMPPIECE && positions[1] == COMPPIECE && positions[2] == COMPPIECE) ||
		(positions[3] == COMPPIECE && positions[4] == COMPPIECE && positions[5] == COMPPIECE) ||
		(positions[6] == COMPPIECE && positions[7] == COMPPIECE && positions[8] == COMPPIECE) ||
		(positions[0] == COMPPIECE && positions[3] == COMPPIECE && positions[6] == COMPPIECE) ||
		(positions[1] == COMPPIECE && positions[4] == COMPPIECE && positions[7] == COMPPIECE) ||
		(positions[2] == COMPPIECE && positions[5] == COMPPIECE && positions[8] == COMPPIECE) ||
		(positions[0] == COMPPIECE && positions[4] == COMPPIECE && positions[8] == COMPPIECE) ||
		(positions[2] == COMPPIECE && positions[4] == COMPPIECE && positions[6] == COMPPIECE)
	)
	{
		return COMPUTER;
	}
	else if
	(
		(positions[0] == HUMANPIECE && positions[1] == HUMANPIECE && positions[2] == HUMANPIECE) ||
		(positions[3] == HUMANPIECE && positions[4] == HUMANPIECE && positions[5] == HUMANPIECE) ||
		(positions[6] == HUMANPIECE && positions[7] == HUMANPIECE && positions[8] == HUMANPIECE) ||
		(positions[0] == HUMANPIECE && positions[3] == HUMANPIECE && positions[6] == HUMANPIECE) ||
		(positions[1] == HUMANPIECE && positions[4] == HUMANPIECE && positions[7] == HUMANPIECE) ||
		(positions[2] == HUMANPIECE && positions[5] == HUMANPIECE && positions[8] == HUMANPIECE) ||
		(positions[0] == HUMANPIECE && positions[4] == HUMANPIECE && positions[8] == HUMANPIECE) ||
		(positions[2] == HUMANPIECE && positions[4] == HUMANPIECE && positions[6] == HUMANPIECE)
	)
	{
		return HUMAN;
	}
	else if
	(!(
		positions[0] == ' ' ||
		positions[1] == ' ' ||
		positions[2] == ' ' ||
		positions[3] == ' ' ||
		positions[4] == ' ' ||
		positions[5] == ' ' ||
		positions[6] == ' ' ||
		positions[7] == ' ' ||
		positions[8] == ' '
	))
	{
		return DRAW;
	}
	return CONTINUE;
}

/* Clear the board */
void Initialize(Board_Type Board)
{
    int I;
    for (I = 0; I < Squares; I++)
	Board[I] = Empty;
}

/* If a player has won, return the winner. If the game is a tie,
   return 'C' (for cat). If the game is not over, return Empty. */
Square_Type Winner(Board_Type Board)
{
    int I;
    for (I = 0; I < Possible_Wins; I++)
	{
		Square_Type Possible_Winner = Board[Three_in_a_Row[I][0]];
		if (Possible_Winner != Empty && Possible_Winner == Board[Three_in_a_Row[I][1]] && Possible_Winner == Board[Three_in_a_Row[I][2]])
			return Possible_Winner;
    }

    for (I = 0; I < Squares; I++)
		if (Board[I] == Empty)
			return Empty;

    return 'C';
}

/* Return the other player */
Square_Type Other(Square_Type Player)
{
    return Player == 'X' ? 'O' : 'X';
}

/* Make a move on the board */
void Play(Board_Type Board, int Square, Square_Type Player)
{
    Board[Square] = Player;
}

/* Print the board */
void Print(Board_Type Board)
{
    int I;
	printf("\n\n\n\n\n\n%s\n\n%c = Computer\n%c = You\n\n", "{ INVINCIBLE MODE }", COMPPIECE, HUMANPIECE);
    for (I = 0; I < Squares; I += 3)
	{
		printf("+-------+-------+-------+\n");
		printf("|       |       |       |\n");
		printf("|   %c   |   %c   |   %c   |\n", Board[I], Board[I + 1], Board[I + 2]);
		printf("|       |       |       |\n");
    }
	printf("+-------+-------+-------+\n");
}

/* Return a heuristic used to determine the order in which the
   children of a node are searched */
int Evaluate(Board_Type Board, Square_Type Player)
{
    int I;
    int Heuristic = 0;
    for (I = 0; I < Possible_Wins; I++)
	{
		int J;
		int Players = 0, Others = 0;
		for (J = 0; J < 3; J++)
		{
			Square_Type Piece = Board[Three_in_a_Row[I][J]];
			if (Piece == Player)
				Players++;
			else if (Piece == Other(Player))
				Others++;
		}
		Heuristic += Heuristic_Array[Players][Others];
    }
    return Heuristic;
}

/* Return the score of the best move found for a board
   The square to move to is returned in *Square */
int Best_Move(Board_Type Board, Square_Type Player, int *Square, int Move_Nbr, int Alpha, int Beta)
{
    int Best_Square = -1;
    int Moves = 0;
    int I;
    Move_Heuristic_Type Move_Heuristic[Squares];

    Total_Nodes++;

    /* Find the heuristic for each move and sort moves in descending order */
    for (I = 0; I < Squares; I++)
	{
		if (Board[I] == Empty)
		{
			int Heuristic;
			int J;
			Play(Board, I, Player);
			Heuristic = Evaluate(Board, Player);
			Play(Board, I, Empty);
			for (J = Moves-1; J >= 0 && Move_Heuristic[J].Heuristic < Heuristic; J--)
			{
				Move_Heuristic[J + 1].Heuristic = Move_Heuristic[J].Heuristic;
				Move_Heuristic[J + 1].Square = Move_Heuristic[J].Square;
			}
			Move_Heuristic[J + 1].Heuristic = Heuristic;
			Move_Heuristic[J + 1].Square = I;
			Moves++;
		}
    }

    for (I = 0; I < Moves; I++)
	{
		int Score;
		int Sq = Move_Heuristic[I].Square;
		Square_Type W;

		/* Make a move and get its score */
		Play(Board, Sq, Player);

		W = Winner(Board);
		if (W == 'X')
			Score = (Maximum_Moves + 1) - Move_Nbr;
		else if (W == 'O')
			Score = Move_Nbr - (Maximum_Moves + 1);
		else if (W == 'C')
			Score = 0;
		else
			Score = Best_Move(Board, Other(Player), Square, Move_Nbr + 1, Alpha, Beta);

		Play(Board, Sq, Empty);

		/* Perform alpha-beta pruning */
		if (Player == 'X')
		{
			if (Score >= Beta)
			{
				*Square = Sq;
				return Score;
			}
			else if (Score > Alpha)
			{
				Alpha = Score;
				Best_Square = Sq;
			}
		}
		else
		{
			if (Score <= Alpha)
			{
				*Square = Sq;
				return Score;
			}
			else if (Score < Beta)
			{
				Beta = Score;
				Best_Square = Sq;
			}
		}
	}
    *Square = Best_Square;
    if (Player == 'X')
		return Alpha;
    else
		return Beta;
}

/* Provide an English description of the score returned by Best_Move */
void Describe(int Score)
{
    if (Score < 0)
		printf("You have a guaranteed win.\n");
    else if (Score == 0)
		printf("I can guarantee a tie.\n");
    else
		printf("I have a guaranteed win by move %d.\n", Maximum_Moves - Score + 1);
}

/* Have the human or the computer move */
void Move(Board_Type Board, Square_Type Player, int Move_Nbr)
{
    int Square;
	int keyboardNums[9] = { 7, 8, 9, 4, 5, 6, 1, 2, 3 };

    if (Player == 'X')
	{
		Total_Nodes = 0;
		Describe(Best_Move(Board, 'X', &Square, Move_Nbr, -Infinity, Infinity));
		printf("%d nodes examined.\n", Total_Nodes);
		Play(Board, Square, 'X');
		printf("Move #%d - X moves to %d\n", Move_Nbr, Square + 1);
    }
	else
	{
		do
		{
			/*printf("Move #%d - What is O's move? ", Move_Nbr);*/
			printf("Enter the position you would like to place a move: ", Move_Nbr);
			scanf_s("%d", &Square);
			Square = keyboardNums[Square - 1];
			Square--;
		}
		while (Board[Square] != ' ');
		Play(Board, Square, 'O');
    }
}

/* Play a game of tic-tac-toe */
void Game()
{
    Square_Type Player;
    char Answer[String_Length];
    Board_Type Board;
    int Move_Nbr = 1;

    Initialize(Board);

	Player = HUMANPIECE;
    /*printf("\nDo you want to move first? ");
    scanf_s("%s", Answer);
    if (toupper(Answer[0]) == 'Y')
		Player = 'O';
    else
		Player = 'X';
	*/

    while(Winner(Board) == ' ')
	{
		Print(Board);
		Move(Board, Player, Move_Nbr);
		Player = Other(Player);
		Move_Nbr++;
    }
    Print(Board);

	printf("Game over: ");
    if (Winner(Board) != 'C')
		printf("%s wins!\n", (Winner(Board) == COMPPIECE) ? "computer" : "human");
    else
		printf("draw!\n");
}