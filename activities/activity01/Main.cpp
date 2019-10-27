// 이 comment 아래에 적절한 header file include
#include <stdio.h>

#include "Utility.h"

// 이 comment 아래에 main 함수 정의 및 구현
int main(void)
{
	int option;

	PhoneNumber number = "123-456-7890";
	number.Scan();

	number.Print();
	

	Date date;
	if (date.Scan())
	{

	}
	else
	{
		printf("retry");
	}

	date.Print();

	do {
		printf("<Customer Management Program> -author: 이름\n" \
			   "1. Add new customer\n" \
			   "2. Find customer\n" \
			   "3. Remove customer\n" \
			   "4. Display all customers\n" \
			   "0. Exit\n\n"
			   "Select> ");

		scanf("%d", &option);

		printf("\n\n");

		switch (option)
		{
		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 0:
			printf("-> Bye!\n");
		}

	} while (option != 0);

	return 0;
}