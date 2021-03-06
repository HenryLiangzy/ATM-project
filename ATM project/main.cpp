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

char *login(custinfo *head)
{
	//here is for the login function
	//login function will return the account ID back to the main function
	char account[4];
	strcpy(account, "1602"); //here add 1602 just for test
	return account;// 登录不成功的时候返回0000的string， 正常登录的话返回account的string
}

void check(char account[], custinfo *head)
{
	//
}

void save(char account[], custinfo *head)
{
	//
}


void withdraw(char account[], custinfo *head)
{
	//
}

void transfer(char account[], custinfo *head)
{
	//this function used to transfer function
}


//quit function: write the txt and also exit the program, close the point and file
//想要退出程序，直接执行quit()
void quit(custinfo *head)
{
	//quit function used to end the program
	FILE *fp;
	custinfo *current, *next;
	fp = fopen("account_.txt", "w"); //when the program is finish, w will change to w+, file name also change to account.txt
	//这里测试所以用account_.txt 正式的时候改成account.txt w 也会改成 w+
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




void function_list(char account[], custinfo *head)
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

		switch (*choose) //每一个分函数都可以得到主函数的head链表数据提供
		{
		case 1:check(account, head);
			break;
		case 2:save(account, head);
			break;
		case 3:withdraw(account, head);
			break;
		case 4:transfer(account, head);
			break;
		case 5:free(choose);
				quit(head);
			break;
		default:printf("Please input the number 1~5\n");
			break;
		}
	} while (1);
}



//主函数内嵌account.txt文件读写，需要数据的时候只要调用head链表即可
void main()
{
	char account[5];
	FILE *fp1;
	struct custinfo *node1, *node2, *head;
	struct custinfo temp;
	fp1 = fopen("account.txt", "r");
	node1 = (struct custinfo *)malloc(sizeof(struct custinfo));
	head = node1; //把head指向node1， 创建head的链表，head就是主函数提供调用的链表
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
		strcpy(account, login(head)); //send the head linklist to login function
		//主函数需要login函数返回(string)当前登陆账户的account，如果登陆不成功请返回string "0000"
		while (strcmp(account, "0000") != 0)
		{
			function_list(account, head); //send the head linklist to function_list
		}
		if (strcmp(account, "0000") == 0) //if the login is not pass, run quit function
		{
			quit(head);
		}
	}
	else
	{
		printf("ERROR: file not exist\n");
	}
}