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
