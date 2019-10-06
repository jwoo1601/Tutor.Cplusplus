// Lecture 04 - C Language

/*
	1. Functions and Parameters
	- Functions (함수): input 과 output 을 받거나 내보내는 statements 의 묶음 단위.
	- Parameters (or Arguments) (매개변수 또는 인수): 함수의 Input 으로써, 함수의 기능/역할에 따라 필요한 갯수와 값이 달라짐.
	- Return Value (반환값): 함수의 Output 으로써, 함수당 최대 하나만 가질 수 있으며, 주로 함수 동작의 결과값을 내보내는 용도로 사용.
	- Return Type (반환 타입): 함수의 return value 의 data type.

	- (1) Declaration of functions
	: 함수의 선언. 함수 헤더와 끝을 표시하는 세미콜론(;) 으로 구성되며, 헤더파일(.h) 에 저장되어 함수의 '형태' 를 컴파일러에게 알려주는 용도로 사용됨.

	<return-type> <identifier>(<parameter-type> <paramaeter-identifier>, <parameter-type> <parameter-type> <parameter-identifier>);
*/

// 1-(1)의 예시
bool start(int option1, int option2); // 리턴 타입은 void 로써, 아무 값도 리턴하지 않는 것을 나타냄.
// parameter 가 하나 이상일 경우, 컴마(,) 로써 구분함

/*
	- (2) Definition of functions
	: 함수의 정의 혹은 구현. 함수 헤더와 코드 블럭으로 둘러싸인 바디 ({}) 로 구성되며, 소스파일(.cpp) 에 저장되어 함수의 실제 구현 코드를 담고있음.
*/

// 1-(2)의 예시
bool start(int option1, int option2)
{
	if (option1 == 1 && option2 == 2)
	{
		return true; // 리턴(return) statement; 함수의 리턴 타입에 맞는 값 혹은 expression 을 리턴해야 하며, 이 이후로는 다른 코드가 실행되지 않음.
	}

	return false; // 앞에 return true 가 있음에도 이 return statement 가 실행될 수 있음. 이유: if 문의 condition 을 만족하지 않는 경우에만 이 statement 가 실행되기 떄문.
}

// 함수의 return value 를 저장하는 법
// <리턴값을 저장할 variable> 에 함수의 리턴값을 대입.
bool bStarted = start(1, 2); // bStarted 는 start 함수가 호출되고 난 뒤 그 함수에서 리턴된 값을 가지게 됨.

/*
	2. Scopes
	: 어떤 이름(identifier)가 속하게 되는 범위. 해당 identifier 는 본인이 소속된 scope 을 벗어나면 소멸됨.

	- Global scope (전역 범위): 어떤 scope 에도 속하지 않을 경우, global scope 에 소속됨.
	- Function scope (함수 범위): 특정한 함수 안에서 선언된 이름이 속하는 범위.
	- Block/Local scope (블록 범위): 특정한 코드 블록 ({}) 안에서 선언된 이름이 속하는 범위.
	- Class scope (클래스 범위): 특정한 클래스 내에서 선언된 이름이 속하는 범위.

	- (1) Shadowing
	: Inner scope 에 소속된 identifier 가 outer scope 에 소속된 같은 identifier 를 가리는 행위.
*/

// 2-(1)의 예시
void scope_eg()
{ // function scope

	int a = 3; // [1]

	{ // block/local scope

		int a = 4; // [2]

		for (int i = 0; i < 5; i++)
		{ // for 의 block scope

			int a = 5; // [3]

			a = 6; // 이 a 는 [3] 의 a를 가리킴. 즉, 위 [1] 과 [2] 의 a 를 [3] 의 a가 Shadowing 함.
		} // [3] 의 a 가 이 이후로 소멸됨.

		a = 7; // 이 a는 [2]의 a를 가리킴. 즉, 위 [1]의 a를 [2]의 a가 Shadowing 함.
	}

	a = 8; // 이 a는 [1]의 a를 가리킴.
}

/*
	3. Pointers
	: Pointer variables 를 가리키며, pointer variable 은 어떤 다른 변수의 "주소(address)"를 저장함.

	- (1) Declaration of pointer variables
	: 일반 variable 과 선언 형식은 같으나, 타입 뒤 또는 identifier 앞에 *(asterisk) 를 붙여줌.
	<가리킬 variable 의 타입> *<identifier>;

	** l-value vs r-value
	- l-value: left value 의 줄임말로써, 대입 연산자(=)를 기준으로 왼쪽에 올 수 있는 operand 를 뜻함. 반드시 "이름"을 가진 것만 가능.
	- r-value: right value 의 줄임말로써, 대입 연산자를 기준으로 오른쪽에 올 수 있는 operand. 이름 뿐만 아니라 임시 값이나 expression 도 가능.
	e.g. int i;
		i = func(5) => i는 l-value, func(5) 의 리턴값은 이때 "이름이 없는" 임시 값이기 떄문에 r-value

	- (2) Addressof(&) operator (주소 연산자)
	: unary operator (단항 연산자; 피연산자를 하나만 취하는 연산자) 로써, 해당 operand 의 주소를 가져옴. (operand 로는 반드시 l-value만 가능. 즉, 임시 값이나 expression 은 불가)
	&<identifier>

	- (3) Dereference(*) operator (역참조 연산자)
	: unary operator로써, 해당 operand 의 주소가 저장되어 있는 곳의 값을 가져옴. (operand 로는 l-value 중에서도 포인터만 가능)
	*<identifier>

*/

// 3-(1) 의 예시
double* pA; // pA 는 double 타입의 variable 을 가리키는 포인터 변수.
int *pB; // pB는 int 타입의 variable 을 가리키는 포인터 변수.

// 3-(2) 의 예시
int k = 10;
int* pK = &k; // k의 주소를 pK 라는 포인터 변수의 초기값으로 설정.

// 3-(3) 의 예시
int f = 5;
int* pF = &f; // pF 는 f를 가리키고 있음.

int g = *pF; // g 에 pF를 역참조한 값(즉, pF 가리키는 곳(f) 에 저장된 값)을 대입.
// 이 때, g 는 5의 값을 가지게 됨.


/*
	4. Pass-by-Value vs. Pass-by-Address
	
	-(1) Pass-by-Value (값에 의한 전달): 함수의 parameter 에 값이 전달될 때, 주소값이 아닌 일반 값이 저장됨.
	- 특징: 해당 parameter 의 값을 함수 내에서 변경하여도 그 함수가 return 된 후에는 해당 변경사항이 원본 (함수를 호출 할때 넣어준 값 혹은 variable)에 영향을 미치지 않음.
	
	-(2) Pass-by-Address (주소에 의한 전달): 함수의 parameter 에 값이 전달될 떄, 주소값이 저장됨.
	- 특징: 해당 parameter 가 가리키는 값을 함수 내에서 변경할 경우, 그 원본에 직접적인 영향을 미침.
*/

// 3-(1) 의 예시
void pass_by_value(int value)
{
	value = 5;
}

int n = 10;
pass_by_value(n); // pass_by_value 함수는 parameter 인 value 를 값에 의해 전달받기에 함수 내에서 value 의 값을 변경해도 n 에는 영향을 미치지 않음.
printf("%d", n); // n의 값은 여전히 10

// 3-(2) 의 예시
void pass_by_address(int* address)
{
	*address = 6;
}

int m = 12;
pass_by_address(m); // pass_by_address 함수는 parameter 인 address 를 주소에 의해 전달(이유: address가 pointer 기 때문)받기에 내부에서 address 가 가리키는 값을 변경하면 해당 값에 직접적인 영향을 미침.
printf("%d", m); // 위 함수 내에서 m 의 주소를 전달받기에 m에 직접적인 접근 후 m의 값을 변경. 그래서 m의 값은 이 경우 12가 아닌 6