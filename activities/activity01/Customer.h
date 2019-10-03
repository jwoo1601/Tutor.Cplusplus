#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

// 이 comment 아래에 적절한 헤더 파일을 포함해야 함 (자세한 내용은 Activity01.h 참조)

class Customer
{
public:

	// To be implemented
	Customer(int id, std::string name, PhoneNumber phoneNumber, Date date);

	// To be added (member functions)

private:
	std::string m_name;

	// TO be added (member variables)
};

#endif