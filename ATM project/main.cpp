/*
C programming file for ATM project
By Henry Liang    ID:1530003030
Test on Visual Studio Community 2015, Windows 10 v1607
Last modification: Dec 5, 2016
*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[16];
	char password[8];
	float balance;
	char level;
}bankCount;
//define the structe bankCount

int login()
{
	//here is for the login function
	//login function will return the account ID back to the main function
}

void check(int id)
{
	//
}

void save(int id)
{
	//
}


void withdraw(int id)
{
	//
}

void transfer(int id)
{
	//
}

void quit()
{
	//quit function used to end the program
	exit(0);
}




void function_list(int id)
{
	//here is for the function_list
	//input the function number and jump to that funcion
	int *choose;
	choose = (int *)malloc(sizeof(int));
	do
	{
		printf("\t\t|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|       Welcome to Use ATM System         	|\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|    Please Select The Following Functions:     |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|   $$-Check	 -- Press 1			|\n");
		printf("\t\t|   $$-Save      -- Press 2			|\n");
		printf("\t\t|   $$-Withdraw	 -- Press 3			|\n");
		printf("\t\t|   $$-Transfer	 -- Press 4			|\n");
		printf("\t\t|   $$-Quit      -- Press 5			|\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");

		printf("\n\n\n\n");

		printf("Please Input Number:");
		scanf_s("%d", choose, 2);

		switch (*choose)
		{
		case 1:check(id);
			break;
		case 2:save(id);
			break;
		case 3:withdraw(id);
			break;
		case 4:transfer(id);
			break;
		case 5:free(choose);
				quit();
			break;
		default:printf("Please input the number 1~5\n");
			break;
		}
	} while (1);
}

void main()
{
	int id;
	id = login();
	while (id != 0)
	{
		function_list(id);
	}
	if (id == 0)
	{
		quit();
	}
}