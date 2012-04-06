/*
 * File: bankSimulator.c
 * This program simulates bank transactions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef int bool;
#define FALSE 0
#define TRUE !FALSE

typedef struct
{
	char CustomerID[255];
	char CustomerName[255];
	char CustomerAddress[255];
	char CustomerPhone[255];
	float CustomerBalance;
}
CustomerData;

void Withdraw(float amount, CustomerData *dbptr);
void Deposit(float amount, CustomerData *dbptr);
CustomerData ReadDatabase(string filename);
void WriteDatabase(string customerID, CustomerData dbptr);

main()
{
	char customerID[80];
	char action;
	float amount;
	CustomerData database;

	printf("This program simulates bank transactions\n");
	printf("Please enter your customer ID: ");
	scanf_s("%s", customerID, 80);

	database = ReadDatabase(customerID);

	printf("Welcome, %s!\nYour current balance is $%g\nWhat would you like to do?\n", database.CustomerName, database.CustomerBalance);

	printf("D = Deposit\nW = Withdraw\n > ");
	scanf_s("\n");
	scanf_s("%c", &action, 1);

	if (action == 'D' || action == 'd')
	{
		printf("How much would you like to deposit?\n > ");
		scanf_s("%f", &amount, sizeof(float));
		Deposit(amount, &database);
		WriteDatabase(customerID, database);
	}
	else if (action == 'W' || action == 'w')
	{
		printf("How much would you like to withdraw?\n > ");
		scanf_s("%f", &amount, sizeof(float));
		if (database.CustomerBalance >= amount)
		{
			Withdraw(amount, &database);
			WriteDatabase(customerID, database);
		}
		else
		{
			printf("Your balance is too low to withdraw that much\n");
			system("pause");
			exit(0);
		}
	}

	system("pause");
}

void Withdraw(float amount, CustomerData *dbptr)
{
	if (dbptr->CustomerBalance >= amount)
	{
		dbptr->CustomerBalance -= amount;
	}
}

void Deposit(float amount, CustomerData *dbptr)
{
	dbptr->CustomerBalance += amount;
}

void WriteDatabase(string customerID, CustomerData dbptr)
{
	FILE *ptr;
	/* This is to hardcode the path to read files from; if left blank files will be read from the current working directory */
	char path[255] = "C:\\Documents and Settings\\Owner\\My Documents\\Visual Studio 2005\\Projects\\C\\bankSimulator\\debug\\";

	strcat_s(path, 255, customerID);

	fopen_s(&ptr, path, "w");
	if (ptr == NULL)
	{
		printf("Error: Could not save data! All bank transactions during this session are invalidated.\n");
	}

	fprintf_s(ptr, "%s\n%s\n%s\n%s\n%g\n", dbptr.CustomerID, dbptr.CustomerName, dbptr.CustomerAddress, dbptr.CustomerPhone, dbptr.CustomerBalance);

	fclose(ptr);
}

CustomerData ReadDatabase(string filename)
{
	FILE *ptr;
	int i = 0;
	/* This is to hardcode the path to read files from; if left blank files will be read from the current working directory */
	char path[255] = "C:\\Documents and Settings\\Owner\\My Documents\\Visual Studio 2005\\Projects\\C\\bankSimulator\\debug\\";
	char id[255];
	char name[255];
	char addr[255];
	char phone[255];
	char bala[255];
	CustomerData dat;

	strcat_s(path, 255, filename);

	fopen_s(&ptr, path, "r");
	if (ptr == NULL)
	{
		printf("Error: Customer not found.\n");
		system("pause");
		exit(1);
	}

	i = 0;
	while (fscanf_s(ptr, "%c", &id[i]))
	{
		if (id[i] == '\n') break;
		i++;
	}
	id[i] = '\0';

	i = 0;
	while (fscanf_s(ptr, "%c", &name[i]))
	{
		if (name[i] == '\n') break;
		i++;
	}
	name[i] = '\0';

	i = 0;
	while (fscanf_s(ptr, "%c", &addr[i]))
	{
		if (addr[i] == '\n') break;
		i++;
	}
	addr[i] = '\0';

	i = 0;
	while (fscanf_s(ptr, "%c", &phone[i]))
	{
		if (phone[i] == '\n') break;
		i++;
	}
	phone[i] = '\0';

	i = 0;
	while (fscanf_s(ptr, "%c", &bala[i]))
	{
		if (bala[i] != '.' && (bala[i] < '0' || bala[i] > '9')) break;
		i++;
	}
	bala[i] = '\0';

	fclose(ptr);

	strcpy_s(dat.CustomerID, 255, id);
	strcpy_s(dat.CustomerName, 255, name);
	strcpy_s(dat.CustomerAddress, 255, addr);
	strcpy_s(dat.CustomerPhone, 255, phone);
	dat.CustomerBalance = (float)strtod(bala, NULL);

	return dat;
}