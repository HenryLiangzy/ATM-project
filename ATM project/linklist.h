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



//used for delete the linklist
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
custinfo *searchByname(custinfo *head, char account[])
{
	custinfo *current;
	current = head;
	while ((current != NULL) && (strcmp(current->name, account) != 0))
	{
		current = current->next;
	}
	return current;
}
