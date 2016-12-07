/*
C programming file for ATM project
By Henry Liang    ID:1530003030
Test on Visual Studio Community 2015, Windows 10 v1607
Last modification: Dec 7, 2016
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
	return 1602;
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
	//this function used to transfer function
}


//quit function: write the txt and also exit the program, close the point and file
//��Ҫ�˳�����ֱ��ִ��quit()
void quit(custinfo *head)
{
	//quit function used to end the program
	FILE *fp;
	custinfo *current, *next;
	fp = fopen("account_.txt", "w");
	current = (custinfo *)malloc(sizeof(custinfo));
	next = (custinfo *)malloc(sizeof(custinfo));
	current = head;
	while (current != NULL) //uesd loop to write the file
	{
		next = current->next;
		fprintf(fp, "%s %s %s %f %c\n", current->account, current->name, current->password, current->balance, current->level);
		current = next;
	}
	free(current);
	free(next);
	listDelete(head); //delete the linklist
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
		scanf("%d", choose);

		switch (*choose) //ÿһ���ֺ��������Եõ���������head���������ṩ
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



//��������Ƕaccount.txt�ļ���д����Ҫ���ݵ�ʱ��ֻҪ����head������
void main()
{
	int id;
	FILE *fp1;
	struct custinfo *node1, *node2, *head;
	struct custinfo temp;
	fp1 = fopen("account.txt", "r");
	node1 = (struct custinfo *)malloc(sizeof(struct custinfo));
	head = node1; //��headָ��node1�� ����head������head�����������ṩ���õ�����
	if (fp1 != NULL)
	{
		fscanf(fp1, "%s%s%s%f%*c%c", node1->account, node1->name, node1->password, &node1->balance, &node1->level);
		while (fscanf(fp1, "%s%s%s%f%*c%c", temp.account, temp.name, temp.password, &temp.balance, &temp.level) != EOF)
		{
			node2 = (struct custinfo *)malloc(sizeof(struct custinfo));
			*node2 = temp;
			node1->next = node2;
			node1 = node2;
			node2->next = NULL;//keep each of the node for a whole node
		}
		fclose(fp1);
		id = login(head); //send the head linklist to login function
		//��������Ҫlogin�������ص�ǰ��½�˻���account�������½���ɹ��뷵��0
		while (id != 0)
		{
			function_list(id, head); //send the head linklist to function_list
		}
		if (id == 0) //if the login is not pass, run quit function
		{
			quit(head);
		}
	}
	else
	{
		printf("ERROR: file not exist\n");
	}
}