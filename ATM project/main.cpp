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

void function_list(int id)
{
	//here is for the function_list
	//input the function number and jump to that funcion
}

void main()
{
	int id;
	id = login();
	while (id != 0)
	{
		function_list(id);
	}
}