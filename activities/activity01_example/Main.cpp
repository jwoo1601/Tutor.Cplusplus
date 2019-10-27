#include <stdio.h>

#include "..//activity01//Utility.h"

int main(void)
{
//	class Customer customers[10];

	PhoneNumber num;
	printf("Enter phone number: ");
	if (num.Scan())
	{
		printf("Valid phone number: ");
		num.Print();
	}
	else {
		printf("Invalid phone number format");
	}

	Date date;
	printf("Enter date: ");
	if (date.Scan())
	{
		printf("Valid date format: ");
		date.Print();
	}
	else
	{
		printf("Invalid date format");
	}

	printf("\n");

	int option;

	printf("<Customer Management Program> -author: __\n");
	
	do
	{
		printf("1. Add new customer\n" \
			"2. Find customer\n" \
			"3. Remove customer\n" \
			"4. Display all customers\n" \
			"0. Exit\n\n");

		printf("Select> ");
		scanf("%d", &option);

		printf("\n");

		switch (option)
		{
		case 1:
			printf("Case 1\n");
			break;

		case 2:
			printf("Case 2\n");
			break;

		case 3:
			printf("Case 3\n");
			break;

		case 4:
			printf("Case 4\n");
			break;

		case 0:
			printf("-> Bye!");
			break;
		}

		printf("\n");

	} while (option != 0);

	return 0;
}

/*
	%_

	data type:
	int -> d (decimal 10진수)
		   x (hexadecimal 16진수)

	char* / char[] -> s

	float -> f
	double -> lf

	char -> c
*/