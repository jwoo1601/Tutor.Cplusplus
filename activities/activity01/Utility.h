// ** DO NOT MODIFY THIS FILE **
// Copyright © 2019 Jeongwoo Kim

/*
 *	Utility Module
 *	: this module contains useful classes and functions such as PhoneNumber and Date used to complete this activity
 *	
 *	class PhoneNumber
 *	: this class encapsulates essential features for managing a phone number, such as Print and Scan.
 *
 *	> Creating a PhoneNumber object from string literals:
 *		PhoneNumber number = "437-534-1239";
 *	> from C++ string object:
 *		std::string numberString = "234-114-9392";
 *		PhoneNumber number = numberString;
 *	> from other PhoneNumber object:
 *		PhoneNumber number1 = "647-332-1155";
 *		PhoneNumber number2 = number1;
 *	> Printing a phone number:
 *		PhoneNumber number = "437-534-1239";
 *
 *		printf("%s", number.ToString());
 *		or
 *		number.Print();
 *
 *	> Scanning a user input for a phone number:
 *		PhoneNumber number;
 *		number.Scan();
 *	> PhoneNumber to C-String:
 *		PhoneNumber number1 = "437-534-1239";
 *		const char *number2 = number1.ToString();
 *	> PhoneNumber to C++ String Object:
 *		PhoneNumber number1 = "647-332-1155";
 *		std::string number2 = number1.ToStringObject();
 *
 *	class Date
 *	: this class encapsulates necessary features for managing dates in a convenient way.
 *
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <string>

bool TestString(const char* pattern, const char* string);

class PhoneNumber
{
	static bool ValidatePhoneNumber(const char* numberString);

	static const char* DefaultValue;
public:

	PhoneNumber();
	PhoneNumber(const char* numberString);
	PhoneNumber(const std::string& numberString);
	PhoneNumber(const PhoneNumber& other);

	PhoneNumber& operator=(const PhoneNumber& other);
	PhoneNumber& operator=(const char* numberString);
	PhoneNumber& operator=(const std::string& numberString);

	void Print() const;
	bool Scan();

	const char* ToString() const;
	const std::string& ToStringObject() const;

private:
	std::string m_numberString;
};

enum Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

class Date
{
	static bool ValidateDate(const char* dateString);
	static void Parse(Date& date, const char* dateString);

	static const char* DefaultString;
public:

	Date();
	Date(const char* dateString);
	Date(const std::string& dateString);
	Date(const Date& other);

	Date& operator=(const Date& other);
	Date& operator=(const char* dateString);
	Date& operator=(const std::string& dateString);

	void Print() const;
	bool Scan();

	const char* ToString() const;
	const std::string& ToStringObject() const;

			int GetYear() const;
	enum Month GetMonth() const;
			int GetDay() const;

private:
	int m_year = 0;
	int m_month = 0;
	int m_day = 0;
	std::string m_cachedString;
};

#endif