#pragma once


typedef struct custinfo
{
	char account[5];
	char name[16];
	char password[7];
	float balance;
	char level;
	struct custinfo *next;
}custinfo;
//定义struct 注意string的位数


//used for delete the linklist
//这个函数用来删除链表
void listDelete(custinfo *head)
{
	custinfo *next, *current;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	//printf("list delete complete\n");
}




//used for check the n of the linklist
//这个函数通过输入链表头和目的链表的编号返回目的链表
custinfo *searchByindex(custinfo *head, int n)
{
	custinfo *current;
	int i = 1;
	current = head;
	while ((i < n) && (current != NULL))
	{
		current = current->next;
		i++;
	}
	return current;
}




//This function used for print the linklist(only in this project)
//这个函数用来打印链表（仅限ATMproject的链表）
void printLinklist(custinfo *head)
{
	custinfo *current, *next;
	current = (custinfo *)malloc(sizeof(custinfo));
	next = (custinfo *)malloc(sizeof(custinfo));
	current = head;
	while (current != NULL)
	{
		next = current->next;
		printf("%s %s %s %f %c\n", current->account, current->name, current->password, current->balance, current->level);
		current = next;
	}
	free(current);
	free(next);
}




//used for search the account
//这个函数用来查找匹配的account的链表，输入链表头和account(string)，返回目的链表(point)
custinfo *searchByaccount(custinfo *head, char account[])
{
	custinfo *current;
	current = head;
	while ((current != NULL) && (strcmp(current->account, account) != 0))
	{
		current = current->next;
	}
	return current;
}



//used for search the name
//这个函数用来查找匹配name的链表，输入head和name(string)， 返回目的链表(point)
custinfo *searchByname(custinfo *head, char name[])
{
	custinfo *current;
	current = head;
	while ((current != NULL) && (strcmp(current->name, name) != 0))
	{
		current = current->next;
	}
	return current;
}
