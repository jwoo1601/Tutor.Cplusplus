// ** DO NOT MODIFY THIS FILE **
// Copyright © 2019 Jeongwoo Kim

/*
 *---------------------------------------------------------------------------------------
 *	Topic: Gym 회원 등록 프로그램
 *---------------------------------------------------------------------------------------
 *	Requirements
 *---------------------------------------------------------------------------------------
 *	- Customer Module (Customer.h, Customer.cpp)
 *	1. Customer class는 ID, Name, Phone Number, Registration Date 을 저장할 수 있어야 함
 *	2. 해당 Customer의 모든 정보를 Print/Scan 할 수 있어야 함
 *	3. 해당 Customer의 모든 정보를 String 형태로 리턴해주는 함수를 정의해야 함
 *
 *	- Main Module (Main.cpp)
 *	1. main 함수를 정의해야 함 (int 를 리턴하며 어떤 parameter 도 받지 않음)
 *	2. main 함수는 Customer 정보를 최소 10개 이상 저장 가능해야 함
 *	3. main 함수는 Customer 정보를 추가, 제거, 변경 (해당 Customer의 ID로 검색해서 모든
 *		정보를 변경 가능해아함), 모든 Customer 출력 기능들을 구현해야 함 (출력은 아래 Sample
 *		Output 포멧 참조)
 *	4. main 함수는 유저로부터 옵션 (선택지)을 입력받아 해당 옵션 값에 맞게끔 Customer 정보들을
 *		추가, 제거, 변경 및 출력할 수 있어야 함.
 *	5. Customer 정보가 추가될 때 마다 적절히 Customer ID 를 순차적으로 1씩 증가시켜야 함.
 *	6. 유저가 올바르지 않은 값을 입력할 시 적절한 에러 메시지를 출력한 후 다시 입력을 받아야 함.
 *		(Date 과 Phone Number 의 입력 값 검증은 Utility 모듈의 Scan 함수들 참조)
 *	7. 유저가 0을 입력시 Bye! 의 메시지와 함께 프로그램을 정상적으로 종료해야 함.
 *	8. Customer 정보를 모두 출력하는 경우 오직 "등록된" Customer 만 출력해야 함.
 *---------------------------------------------------------------------------------------
 *	Files
 *---------------------------------------------------------------------------------------
 * 수정/추가 해야하는 파일: Customer.h, Customer.cpp, Main.cpp
 * 수정/추가 불가한 파일: Activity01.h, Utility.h, Utility.cpp
 *---------------------------------------------------------------------------------------
 *	Utilities
 *---------------------------------------------------------------------------------------
 *	: Utility Module (Utility.h, Utility.cpp) 에 정의되어 있는 두 클래스 PhoneNumber과
 *	  Date 을 사용할 수 있음 (코드 변경 금지)
 *	  정확한 PhoneNumber 및 Date 클래스 사용법은 Utility.h 파일 참조
 *---------------------------------------------------------------------------------------
 *	Todo
 *---------------------------------------------------------------------------------------
 *	- To be implemented: 해당 comment 로 표시된 함수는 반드시 소스파일 (.cpp) 파일에 구현되야함
 *	- To be added: 해당 comment 로 표시된 부분 아래에 적잘한 멤버 변수를 선언 및
 *					소스파일에서 해당 변수를 적절히 용도에 맞게 사용해야 함.
 *---------------------------------------------------------------------------------------
 *	Sample Output
 *---------------------------------------------------------------------------------------
 * <Customer Management Program> -author: 이름
 * 1. Add new customer
 * 2. Find customer
 * 3. Remove customer
 * 4. Display all customers
 * 0. Exit
 *
 * Select> 4
 *
 *----------------------------------------------------------------
 *|  ID  |    Name    |    Phone Number    |  Registration Date  |
 *----------------------------------------------------------------
 *|  1   | Cornell F. |    647-332-4324    |     2018-06-12      |
 *----------------------------------------------------------------
 *|  2   | Ruth K.    |    447-549-1237    |     2019-05-43      |
 *----------------------------------------------------------------
 *...
 *
 * 1. Add new customer
 * 2. Find customer
 * 3. Remove customer
 * 4. Display all customers
 * 0. Exit
 *
 * Select> 1
 *
 * Customer Name: Jay Kim
 * Phone Number: 446-112-9911
 * Registration Date: 2019-10-03
 * -> Customer Added with ID 3
 *
 * 1. Add new customer
 * 2. Find customer
 * 3. Remove customer
 * 4. Display all customers
 * 0. Exit
 *
 * Select> 2
 *
 * Enter Customer ID: 3
 * Display---------------------------------------------------------------------------------
 * ID: 3, Name: Jay Kim, Phone Number: 446-112-9911, Registration Date: 2019-10-03
 * ----------------------------------------------------------------------------------------
 *
 * 1. Add new customer
 * 2. Find customer
 * 3. Remove customer
 * 4. Display all customers
 * 0. Exit
 *
 * Select> 3
 *
 * Enter Customer ID to remove: 3
 * -> Customer 3 (Name: Jay Kim) successfully removed
 *
 * 1. Add new customer
 * 2. Find customer
 * 3. Remove customer
 * 4. Display all customers
 * 0. Exit
 *
 * Select> 0
 * -> Bye!
 */