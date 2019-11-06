#ifndef LECTURE06_PRACTICE_HPP
#define LECTURE06_PRACTICE_HPP

/*
	1. 했던 내용 반복 복습
	2. Database 클래스 완성
	3. 모든 멤버 function 들 body 완성
*/

/*
	*Understanding of Mutability In-depth*

	<Case Study>
	: 어떤 은행 A 에서는 고객들의 정보를 통합적으로 관리할 전산 시스템을 구축하려함. 이 때, 회사 내에서의 직책 혹은
	직급에 따라 해당 시스템에 대해서 각 employee 들이 제한적인 권한을 부여받아야 함. (그렇지 않으면 어떤 employee 든
	이 시스템을 망가뜨릴 수 있으므로) 이 때, 해당 employee 의 권한을 관리하는 데이터베이스와 그에 맞게 employee 가 요청한
	작업의 유효성을 판별해 작업을 수행 혹은 거절하는 시스템을 구현해야 한다면?

	1. 저장해야 하는 데이터와 그 구조에 대해 설계
	Employee (Name, Position, Age, Gender)
	Customer (Name, Balance, Age, CreditScore, Gender)
	Position (Name, Permission)
	Database (Customers, Employees)

	Employee | 이름, 나이, 성별, 직급(직책)
	Position | 직급 이름, 가능한 작업
	Operation (가능한 작업)
	CustomerInfo | 고객 이름, 나이, 성별, balance
	Database | 고객 정보 저장 및 요청에 따라 데이터 입출력

	enum class Gender
	{
		Male = 0,
		Female = 1,
		Unspecified = 2
	}

	2. 각 데이터들 간의 dependency 파악
	Employee (string Name, class Position, int Age, enum Gender)
	Customer (string Name, double Balance, int Age, int CreditScore, enum Gender)
	Position (string Name, enum Permission)
	Database (array Customers, array Employees)

	3. 각각의 데이터를 실제 C++ 클래스를 이용해 표현

	4. 클래스별 세부적인 기능 정의
	Employee:
		권한 설정: SetPermission(NewPermission) -> void or previous permission
		이름 변경: ChangeName(NewName) -> void or previous name

	Customer:
		이름 변경: ChangeName(NewName) -> void
		잔액 조회: GetBalance() -> double
		신용등급 조회: GetCreditScore() -> int
		Tranfer: Tranfer(AccountNumber, Amount) -> bool
		Deposit: Deposit(AccountNumber, Amount) -> void
		Withdrawal: Withdraw(AccountNumber, Amount) -> bool

	Database:
		Customer 검색/조회
		Customer 추가/제거
		Employee 검색/조회
		Employee 추가/제거
		모든 Customer 출력
		모든 Employee 출력

*/

#include <string>

enum class Gender
{
	Male,
	Female,
	Unspecified
};

enum class Permission
{
	Read,
	Write,
	ReadAndWrite
};

class Position
{
	std::string name;
	Permission permission;
};

// 클래스가 자기 자신의 상태(state)와 그 상태를 관리하는 기능(logic) 을 가지고 있는 성질을 encapsulation (캡슐화)
class Employee
{
public:

	/*
			권한 설정: SetPermission(NewPermission) -> void or previous permission
			이름 변경: ChangeName(NewName) -> void or previous name
	*/

	void SetPermission(Permission newPermssion);
	void ChangeName(std::string newName);

private:
	std::string name;
	Position position;
	int age;
	Gender gender;
};

class Customer
{
public:

	/*
		이름 변경: ChangeName(NewName) -> void
		잔액 조회: GetBalance() -> double
		신용등급 조회: GetCreditScore() -> int
		Tranfer: Tranfer(AccountNumber, Amount) -> bool
		Deposit: Deposit(AccountNumber, Amount) -> void
		Withdrawal: Withdraw(AccountNumber, Amount) -> bool
	*/

	void ChangeName(std::string newName);
	double GetBalance() const;
	int GetCreditScore() const;
	bool Transfer(int accountNumber, double amount);
	void Deposit(int accountNumber, double amount);
	bool Withdraw(int accountNumber, double amount);

private:
	std::string name;
	double balance;
	int age;
	int creditScore;
	Gender gender;
};

void DeleteCustomer(const Customer &customer);

/*
	함수의 파라미터를 받을때 해당 파라미터를 함수내에서 변경하지 않는 경우
	그 파라미터를 const 형태로 받아주면 해당 함수를 호출할떄
	const 혹은 non-const 도 받을 수 있음
*/

void main()
{
	Customer Jay;
	printf("%lf", Jay.GetBalance());
	// %x -> heXadecimal 16진수

	const Customer President;
	DeleteCustomer(President);
	President.GetBalance();
	President.GetCreditScore();

	DeleteCustomer(Jay);
}

class Database
{
	Customer customers[10];
	Employee employees[10];
};

#endif