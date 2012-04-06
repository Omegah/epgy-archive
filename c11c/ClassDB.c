/*
 * File: ClassDB.c
 * This is a class database where you can enter student data
 */

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define FALSE 0
#define TRUE !FALSE
typedef char* string;

typedef struct
{
	string name;
	string address;
	string BirthDate;
	int mathGrade;
	char teammember;
}
students;

students new_students(string name, string address, string BirthDate, int mathGrade, char teammember);
void cleanBuffer(void);

main()
{
	students *p_stuDB;
	int DB_SIZE;
	int i;
	char tmpName[255], tmpAddress[255], tmpBirthDate[255];
	int tmpMathGrade;
	char tmpTeammember;
	double totalgrade = 0;

	printf("Enter the size of the database to create (number of records): ");
	scanf_s("%d", &DB_SIZE);
	cleanBuffer();

	p_stuDB = malloc(sizeof(students) * DB_SIZE);

	for (i = 0; i < DB_SIZE; i++)
	{
		printf("\nEntering record %d...\n", i + 1);

		printf("Enter student name: ");
		fgets(tmpName, 255, stdin);

		printf("Enter student address: ");
		fgets(tmpAddress, 255, stdin);

		printf("Enter student birth date: ");
		fgets(tmpBirthDate, 255, stdin);

		printf("Enter student math grade (0-100): ");
		scanf_s("%d", &tmpMathGrade);
		cleanBuffer();

		if (tmpMathGrade < 0) tmpMathGrade = 0;
		if (tmpMathGrade > 100) tmpMathGrade = 100;
		totalgrade += tmpMathGrade;

		printf("Enter student soccer team membership (Y/N): ");
		scanf_s("%c", &tmpTeammember);
		cleanBuffer();

		if (tmpTeammember == 'y') tmpTeammember = 'Y';
		if (tmpTeammember == 'n') tmpTeammember = 'N';

		p_stuDB[i] = new_students(tmpName, tmpAddress, tmpBirthDate, tmpMathGrade, tmpTeammember);
	}

	printf("\nThe average math grade of the %d students entered is %g\n\n", DB_SIZE, totalgrade / DB_SIZE);

	system("pause");
}

students new_students(string name, string address, string BirthDate, int mathGrade, char teammember)
{
	students stu;
	stu.name = name;
	stu.address = address;
	stu.BirthDate = BirthDate;
	stu.mathGrade = mathGrade;
	stu.teammember = teammember;
	return stu;
}

void cleanBuffer()
{
	while (scanf_s("%c") == '\n');
}