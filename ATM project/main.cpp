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
#include "linklist.h"


int login(custinfo *head)
{
	//here is for the login function
	//login function will return the account ID back to the main function
}

void check(int id, custinfo *head)
{
	//
}

void save(int id, custinfo *head)
{
	//
}


void withdraw(int id, custinfo *head)
{
	//
}

void transfer(int id, custinfo *head)
{
	//
}

void quit(custinfo *head)
{
	//quit function used to end the program
	listDelete(head);
	exit(0);

}




void function_list(int id, custinfo *head)
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
		case 1:check(id, head);
			break;
		case 2:save(id, head);
			break;
		case 3:withdraw(id, head);
			break;
		case 4:transfer(id, head);
			break;
		case 5:free(choose);
				quit(head);
			break;
		default:printf("Please input the number 1~5\n");
			break;
		}
	} while (1);
}

void main()
{
	int id;
	FILE *fp1;
	struct custinfo *node1, *node2, *head;
	struct custinfo temp;
	fp1 = fopen("account.txt", "r");
	if (fp1 != NULL)
	{
		node1 = (struct custinfo *)malloc(sizeof(struct custinfo));
		fscanf(fp1, "%s %s %s %f %c", node1->account, node1->name, node1->password, &node1->balance, &node1->level);
		head = node1;
		printf("%s %s %s %f %c\n", node1->account, node1->name, node1->password, node1->balance, node1->level);
		while (fscanf(fp1, "%s %s %s %f %c", temp.account, temp.name, temp.password, &temp.balance, &temp.level) != EOF)
		{
			node2 = (struct custinfo *)malloc(sizeof(struct custinfo));
			//fscanf(fp1, "%d %s %d %f %c", &node2->id, node2->name, &node2->password, &node2->balance, &node2->level);
			strcpy(node2->account, temp.account);
			strcpy(node2->name, temp.name);
			strcpy(node2->password, temp.password);
			node2->balance = temp.balance;
			node2->level = temp.level;
			printf("%s %s %s %f %c\n", node2->account, node2->name, node2->password, node2->balance, node2->level);
			node1->next = node2;
			node1 = node2;
		}
		node2 = NULL;
		fclose(fp1);
	}
	else
	{
		printf("file not exist\n");
	}
	id = login(head);
	while (id != 0)
	{
		function_list(id, head);
	}
	if (id == 0)
	{
		quit(head);
	}
}