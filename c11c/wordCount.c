/*
 * File: wordCount.c
 * This program counts how many times each word occurs in a file
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

#define ARRAY_SIZE 100
#define WORD_LENGTH 31

void InitializeCounter(int counts[], int arrsize);
int FindIndex(char word[], char wordarray[ARRAY_SIZE][WORD_LENGTH]);
void ToLower(char chars[]);
void CleanWord(char word[]);
void SortArrays(char wordarray[ARRAY_SIZE][WORD_LENGTH], int count[ARRAY_SIZE]);

int indexMaxSTR(char wordarray[ARRAY_SIZE][WORD_LENGTH], int low, int high);
void swap(int numbers[], int loc1, int loc2);
void swapAddr(char wordarray[ARRAY_SIZE][WORD_LENGTH], int loc1, int loc2);

main()
{
	FILE *in;
	string filename = malloc(sizeof(char) * ARRAY_SIZE);
	char tmpWord[WORD_LENGTH];
	char words[ARRAY_SIZE][WORD_LENGTH];
	int counts[ARRAY_SIZE];
	int i = 0, j = 0;
	int foundIndex = -1;

	InitializeCounter(counts, ARRAY_SIZE);

	printf("This program counts how many times each word occurs in a file\n");
	printf("Enter the filename of the file to read from:\n > ");
	gets_s(filename, ARRAY_SIZE - 1);

	fopen_s(&in, filename, "r");
	if (in == NULL)
	{
		printf("The file could not be opened. Please be sure it exists and you have permission to read it.\n");
		system("pause");
		exit(1);
	}

	while (fscanf_s(in, "%s", tmpWord, WORD_LENGTH) != EOF)
	{
		CleanWord(tmpWord);
		if (strcmp(tmpWord, "") != 0)
		{
			foundIndex = FindIndex(tmpWord, words);
			if (foundIndex >= 0)
			{
				(counts[foundIndex])++;
			}
			else
			{
				strcpy_s(words[i], WORD_LENGTH, tmpWord);
				(counts[i])++;
				i++;
			}
		}
	}

	SortArrays(words, counts);

	for (j = 0; j < i; j++)
	{
		printf("%s\t%d\n", &(words[j]), counts[j]);
	}

	fclose(in);
	
	system("pause");
}

void InitializeCounter(int counts[], int arrsize)
{
	int i = 0;
	for (i = 0; i < arrsize; i++)
	{
		counts[i] = 0;
	}
}

int FindIndex(char word[], char wordarray[ARRAY_SIZE][WORD_LENGTH])
{
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (strcmp(wordarray[i], word) == 0)
		{
			return i;
		}
	}
	return -1;
}

void ToLower(char chars[])
{
	size_t count = strlen(chars);
	unsigned int i;
	for (i = 0; i < count; i++)
	{
		if (chars[i] >= 'A' && chars[i] <= 'Z')
		{
			chars[i] += ('a' - 'A');
		}
	}
}

void CleanWord(char word[])
{
	size_t count = strlen(word);
	unsigned int i, j = 0, k;
	char wordNew[WORD_LENGTH];

	/* Convert to lowercase */
	ToLower(word);

	/* Create a new string without nonalphabetic characters present */
	for (i = 0; i < count; i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z')
		{
			wordNew[i] = word[i];
			j++;
		}
	}

	/* Nullify the rest of the string */
	for (; j < WORD_LENGTH; j++) wordNew[j] = '\0';

	/* Set the old array to the new one with all nonalphabetic characters removed */
	for (k = 0; k < WORD_LENGTH; k++) word[k] = wordNew[k];
}

void SortArrays(char wordarray[ARRAY_SIZE][WORD_LENGTH], int count[ARRAY_SIZE])
{
	int i, maxInd;
	for (i = ARRAY_SIZE - 1; i > 0; i--)
	{
		maxInd = indexMaxSTR(wordarray, 0, i);
		swapAddr(wordarray, maxInd, i);
		swap(count, maxInd, i);
	}
}

int indexMaxSTR(char wordarray[ARRAY_SIZE][WORD_LENGTH], int low, int high)
{
	int i, maxInd = high;
	for (i = low; i <= high; i++)
	{
		if (strcmp(wordarray[i], wordarray[maxInd]) > 0)
		{
			maxInd = i;
		}
	}
	return maxInd;
}

void swap(int numbers[], int loc1, int loc2)
{
	int temp = numbers[loc1];
	numbers[loc1] = numbers[loc2];
	numbers[loc2] = temp;
}

void swapAddr(char wordarray[ARRAY_SIZE][WORD_LENGTH], int loc1, int loc2)
{
	int i;
	for (i = 0; i < WORD_LENGTH; i++)
	{
		char temp = wordarray[loc1][i];
		wordarray[loc1][i] = wordarray[loc2][i];
		wordarray[loc2][i] = temp;
	}
}