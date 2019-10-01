// add
// a + b
// c = a+ b
// if c == 5
// ~~

/* 리런타입 함수의이름(파라미터...)
{
	실제코드
}

(타입 파라미터의이름, 타입 파라미터의이름)
(int a,             int b)

_a-zA-Z 로만 시작가능
_a-zA-Z0-9
keyword 는 사용할수없음



VerbNoun

make_something // c에서 많이 하는 스타일
MakeSomething // C++ 에서 많이하는 스타일
makeSomething */

// () => 소괄호 (brackets, braces, parenthesis)
// [] => 대괄호 square brackets
// {} => 중괄호 curly brackets , squiggly brackets
// 꺾쇠 괄호 < less than  > greater than
/*/ <------ forward slash
\ <------ backslash

#include <stdio.h>

int main()
{
	// statement;statement; -> ; 은 statement 구분
	int a = 3, b = 5, c = 7;
	
	int d = 10;

	b = a + c;

	// expression (표현식) = 값 또는 연산식 혹은 함수호출
	3 + 5;
	b = 3;
	12;

	// 연산식 =>
	// 피연산자(operand) 연산자(operator)
	// 연산자 피연사자
	// > 단항 연산자 (unary operator)
	// : 피연산자 하나를 필요로 하는 경우
	// ex) ++(increment) --(decrement) a++ b-- --a ++b

	// 피연산자 연산자 피연산자
	// 이항 연산자 (binary operator)
	// ex) + - * / % || &&

	// 삼항 연산자 (ternary operator)
	// 피연산자 ? 피연산자 : 피연산자 -> 삼항 조건 연산자

	// -----------------------------------------------

	// arithmetic operator (산술 연산자)
	// + - * / % ++ -- ... : 결과값은 항상 수(숫자)

	// logical operator (논리 연산자)
	// _ && _(and) _ || _(or) !_(not)
	// 결과값은 항상 true/false

	// bitwise operator (비트 연산자)
	// << >> & | ~

	// 기타 다른 연산자
	// [] (index) () (funciton operator) :: (scope resolution operator)

	// 연산자의 우선순위 (operator precedence)
	// 어떤 연산이 어떤 연산을 우선하는지
	
	// 3 + 2 * 4

	// single quote (') -> 문자 하나만 ''(x)
	// double quote (") -> 문자 0개 이상 ""(o) "a" "abcd"
	char c = 'd';

	

	printf("a: %d\n", a, b, c);
}

/*

// variable 변수
변수의타입 변수의이름; // 변수를 선언함 declaration of variable
int a;

// 변수에 대입(assignment) or 정의(definition)
변수이름 = 값;

// 변수를 선언과 동시에 정의 or 초기화 (initialization)
변수타입 변수이름 = 값;

// 변수의 타입
1. primitive types
// 정수형 타입 (integral type)
signed char  // 1byte -128 ~ +127
signed int // 4byte -21억 ~ +21억
signed short // 2byte -32278 ~ +32277
signed long // 4byte -21억 ~ +21억
signed long long // 8byte
unsigned char // 0 ~ 255
unsigned short // 0 ~ 65535
~
unsigned long long 

// 실수형 타입 혹은 부동소수점 타입 (floating point number type)
float // 4byte (정수부 / 소수점아래 7자리까지)
double // 8byte (정수부 / 소수점아래 15자리까지)
long double // 16byte (정수부 / 소수점아래 30자리?)

// 문자형 타입 (character type)
char // 문자 대입 가능 (1개만)

2. builtin types
primitive types 으로 부터 파생되는 타입
c-style string char*
size_t
nullptr_t

3. user-defined types
class, struct, union, enum

*/

/*
%d - decimal (십진수) => 정수형
%c - character (문자 하나) => char
%f - floating point (부동소수점) => 실수형
*/ 