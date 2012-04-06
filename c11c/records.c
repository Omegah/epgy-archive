/*
 * File: records.c
 * This program creates a student database and displays their average math grade
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
} students;

students new_students(string name, string address, string BirthDate, int mathGrade, char teammember);
void InitDB(students record[], int size);
void DisplayDB(students record[], int size);
double AvGrd(students record[], int size);

#define DB_SIZE 3

main()
{
	students records[DB_SIZE];

	InitDB(records, DB_SIZE);

	records[0] = new_students("Carol Wilson", "15 Mine St. LA 98760", "Nov 16, 87", 100, 'Y');
	records[1] = new_students("Oscar Smith", "32 Aster Ave. PA 46530", "Dec 27, 87", 90, 'N');
	records[2] = new_students("Judith Arbel", "88 Wolfe Rd. NY 76531", "Apr 22, 87", 85, 'Y');

	DisplayDB(records, DB_SIZE);

	printf("\nThe average grade of the students is %g\n\n", AvGrd(records, DB_SIZE));

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

void InitDB(students record[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		record[i].name = "";
		record[i].address = "";
		record[i].BirthDate = "";
		record[i].mathGrade = 0;
		record[i].teammember = 'N';
	}
}

void DisplayDB(students record[], int size)
{
	int i;
	printf("%s\t\t%s\t\t\t%s\t%s\t%s\n", "Name", "Address", "Birth Date", "Math Grade", "Soccer?");
	for (i = 0; i < size; i++)
	{
		printf("%s\t%s\t%s\t%d\t\t%c\n", record[i].name, record[i].address, record[i].BirthDate, record[i].mathGrade, record[i].teammember);
	}
}

double AvGrd(students record[], int size)
{
	int i, totalgrade = 0;
	double average;
	for (i = 0; i < size; i++)
	{
		totalgrade += record[i].mathGrade;
	}
	average = (double)totalgrade / (double)size;
	return average;
}