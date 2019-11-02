// ** DO NOT MODIFY THIS FILE **
// Copyright © 2019 Jeongwoo Kim

#include "Utility.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <vector>

#define IS_NUMBER(ch) ((ch) >= '0' && (ch) <= '9')
#define TO_NUMBER(ch) ((ch) - '0' >= 0 && (ch) - '0' <= 9? (ch) - '0' : -1)

enum TokenType
{
	TK_None = 0,
	TK_Number = 1,
	TK_Literal = 2,
	TK_LiteralAny = 3
};

struct Token
{
	enum TokenType type;
	char value;
};

bool TestString(const char* pattern, const char* string)
{
	size_t patternLength = strlen(pattern);
	std::vector<Token> tokens(patternLength, Token{ TK_None, 0 });

	bool bInterpretAsLiteral = false;
	for (size_t i = 0u; i < patternLength; i++)
	{
		switch (pattern[i])
		{
		case '\\':
			bInterpretAsLiteral = true;
			break;

		case '.':
			if (!bInterpretAsLiteral)
			{
				tokens[i].type = TK_LiteralAny;
				break;
			}

		case 'N':
		case 'n':
			if (!bInterpretAsLiteral && tokens[i].type == TK_None)
			{
				tokens[i].type = TK_Number;
				break;
			}

		default:
			int j;
			if (bInterpretAsLiteral)
			{
				j = i - 1;
				bInterpretAsLiteral = false;
			}
			else
			{
				j = i;
			}

			tokens[j].type = TK_Literal;
			tokens[j].value = pattern[i];
			break;
		}
	}

	size_t actualTokensCount = tokens.size();
	for (size_t i = 0u; i < tokens.size(); i++)
	{
		if (tokens[i].type == TK_None)
		{
			actualTokensCount = i;
			break;
		}
	}

	size_t stringLength = strlen(string);
	if (actualTokensCount != stringLength)
	{
		return false;
	}

	for (size_t i = 0u; i < stringLength; i++)
	{
		switch (tokens[i].type)
		{
		case TK_Number:
			if (!IS_NUMBER(string[i]))
			{
				return false;
			}
			break;

		case TK_Literal:
			if (tokens[i].value != string[i])
			{
				return false;
			}
			break;

		case TK_LiteralAny:
			break;

		default:
			return false;
		}
	}

	return true;
}

const char* PhoneNumber::DefaultValue = "000-000-0000";

PhoneNumber::PhoneNumber()
{
	m_numberString = DefaultValue;
}

PhoneNumber::PhoneNumber(const char* numberString)
{
	m_numberString = ValidatePhoneNumber(numberString) ? numberString : DefaultValue;
}

PhoneNumber::PhoneNumber(const std::string& numberString) : PhoneNumber(numberString.c_str()) { }

PhoneNumber::PhoneNumber(const PhoneNumber& other) : PhoneNumber(other.m_numberString) { }

PhoneNumber& PhoneNumber::operator=(const PhoneNumber& other)
{
	m_numberString = other.m_numberString;
	return *this;
}

PhoneNumber& PhoneNumber::operator=(const char* numberString)
{
	m_numberString = ValidatePhoneNumber(numberString)? numberString : DefaultValue;
	return *this;
}

PhoneNumber& PhoneNumber::operator=(const std::string& numberString)
{
	return *this = numberString.c_str();
}

void PhoneNumber::Print() const
{
	printf("%s", m_numberString.c_str());
}

bool PhoneNumber::Scan()
{
	char buffer[13], ignored;
	scanf("%12s", buffer);
	scanf("%*c");

	if (ValidatePhoneNumber(buffer))
	{
		m_numberString = buffer;
		return true;
	}
	else
	{
		m_numberString = DefaultValue;
		return false;
	}
}

const char* PhoneNumber::ToString() const
{
	return m_numberString.c_str();
}

const std::string& PhoneNumber::ToStringObject() const
{
	return m_numberString;
}

bool PhoneNumber::ValidatePhoneNumber(const char* numberString)
{
	return TestString("NNN-NNN-NNNN", numberString);
}


void Date::Parse(Date& date, const char* dateString)
{
	date.m_year = TO_NUMBER(dateString[0]) * 1000 +
				  TO_NUMBER(dateString[1]) * 100 +
				  TO_NUMBER(dateString[2]) * 10 +
				  TO_NUMBER(dateString[3]);
	date.m_month = TO_NUMBER(dateString[5]) * 10 +
				   TO_NUMBER(dateString[6]);
	date.m_day = TO_NUMBER(dateString[8]) * 10 +
				 TO_NUMBER(dateString[9]);
}

bool Date::ValidateDate(const char* dateString)
{
	return TestString("NNNN-NN-NN", dateString);
}

const char* Date::DefaultString = "0000-00-00";

Date::Date()
{
	m_cachedString = DefaultString;
}

Date::Date(const char* dateString)
{
	if (ValidateDate(dateString))
	{
		Parse(*this, dateString);
		m_cachedString = dateString;
	}

	else
	{
		m_cachedString = DefaultString;
	}
}

Date::Date(const std::string& dateString) : Date(dateString.c_str()) { }

Date::Date(const Date& other) : Date(other.m_cachedString) { }

Date& Date::operator=(const Date& other)
{
	m_year = other.m_year;
	m_month = other.m_month;
	m_day = other.m_day;
	m_cachedString = other.m_cachedString;
	return *this;
}

Date& Date::operator=(const char* dateString)
{
	if (ValidateDate(dateString))
	{
		Parse(*this, dateString);
		m_cachedString = dateString;
	}
	else
	{
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_cachedString = DefaultString;
	}
	return *this;
}

Date& Date::operator=(const std::string& dateString)
{
	*this = dateString.c_str();
	return *this;
}

void Date::Print() const
{
	printf("%s", m_cachedString.c_str());
}

bool Date::Scan()
{
	char buffer[11], ignored;
	scanf("%10s", buffer);
	scanf("%*c");

	if (ValidateDate(buffer))
	{
		Parse(*this, buffer);

/*		std::stringstream stream;
		stream << m_year << '-'
			   << std::setw(2) << std::setfill('0') << m_month << '-'
			   << std::setw(2) << std::setfill('0') << m_day;
		m_cachedString = stream.str(); */

		m_cachedString = buffer;

		return true;
	}
	else
	{
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_cachedString = DefaultString;
		return false;
	}
}

const char* Date::ToString() const
{
	return m_cachedString.c_str();
}

const std::string& Date::ToStringObject() const
{
	return m_cachedString;
}

int Date::GetYear() const
{
	return m_year;
}

enum Month Date::GetMonth() const
{
	return static_cast<enum Month>(m_month);
}

int Date::GetDay() const
{
	return m_day;
}