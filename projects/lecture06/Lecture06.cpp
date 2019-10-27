/*
	정수형

	signed 타입 (부호가 있는 타입)
	(signed) char -> 1 byte [-128, +127]
	(signed) short (int) -> 2 byte [-32768, +32767]
	(signed)         int -> 4 byte [-21억, +21억]
	(signed) long  (int) -> 4 byte [-21억, +21억]
	(signed) long long (int) -> 8 byte [-9,223,372,036,854,775,809, +9,223,372,036,854,775,807]

	unsigned 타입 (부호가 없는 타입)
	unsigned char -> 1 byte [0, 255]
	unsigned short -> 2 byte [0, 65535]
	unsigned int -> 4 byte [0, 42억]
	unsigned long -> 4 byte [0, 42억]
	unsigned long long -> 8 byte [0, 2^64 -1]

	char <= short <= int <= long -> 4 byte 8 byte

	float -> 4 byte (소수점 7번쨰 자리까지)
	double -> 8 byte (15번쨰)
	long double -> 16 byte
	
	1. Type Casting (타입 변환)
	: 한 타입에서 다른 데이터 타입으로 변환하는 것.

	- Implicit Type Casting (암시적 형 변환)
	: 원래의 값을 보존하면서 타입을 변환하는 것. 어떤 두 피연산자(operand) 의 타입이 다를 경우 두 타입이 compatible 하다면
	 컴파일러가 자동으로 lower 타입에서 higher type 으로 변환함. 따라서, 특수한 키워드가 필요하지 않음.
	 이때, 작은 타입과 큰 타입의 연산에서 작은 타입의 데이터가 큰 타입으로 변환되는 것을 type promotion 이라함.

	 long double             ^  Higher
	 double                  |
	 float                   |
	 unsigned long long      |
	 long long               |  Type Hierarchy
	 unsigned long           |
	 long                    |
	 unsigned int            |
	 int                     |  Lower

	- Explicit Type Casting (명시적 형 변환)
	: 잠재적으로 원래 값의 손실이 발생할 수 있지만, 임의로 (강제로) 타입 변환을 명시하는 것. 두 타입이 compatible 하지 않을 경우에는
	 정상적인 결과를 보장하지 않음.
	(type) expression

	** Up-casting: 업캐스팅. 크기가 작은 타입에서 큰 타입으로 변환하는 경우. --> Implicit conversion 에서 자동으로 처리됨.
	** Down-casting: 다운 캐스팅. 크기가 큰 타입에서 작은 타입으로 변환하는 경우. (위험; 데이터 손실이 발생할 수 있음) --> implicit conversion 으로 불가.

	(1) C-style casting
	: explicit type conversion 에서 (type) expresison 형태를 의미.

	(2) C++ style casting
	: explicit type conversion 에서 type (expression) 형태나 다양한 용도의 캐스팅 형태를 의미.
	e.g. static_cast, dynamic_cast, const_cast, reinterpret_cast
*/

void _1()
{
	int i = 5;
	double dd = 3.3;

	double dd2 = i + dd;

	int a = 30;
	double b = 24.44;

	// implicit casting
	double c = a + b; // int 타입의 a 가 double 타입의 b와 연산되며 더 큰 타입 (double) 로 확장됨.
	
	long l1 = 50l;
	unsigned long l2 = 450ul;
	float f = l1 + l2; // long 타입의 l1 이 l2 와 같은 unsigned long 으로 확장된 후, 다시 float 으로 확장됨.

	double d1 = 55.554;
	int i1 = d1;

	// explicit casting
	short s = 333;
	int ii = 100000000;
	
	short result = s + ((short)ii);
	short result2 = s + short(ii);

	int* pI = (int*)&s; // risky
}

/*
	2. Reference (참조)
	: 이름이 있는 variable 의 alias (별명). 내부적인 처리는 pointer 와 같이 취급됨. 다른 이름의 별명이기에 선언과 동시에 초기화되야 함.

	- L-value reference
	<type> &<identifier> = <variable-name>;
	: L-value 를 가리키는 레퍼런스. 이 때, L-value 는 대입 연산자 (=) 를 기준으로 왼쪽에 올 수 있는 것들을 말하며,
	 이는 이름이 있는 variable 등을 말함.

	- R-value reference
	<type> &&<identifier> = <expression>;
	: R-value 를 가리키는 레퍼런스. 이 때, prvalue 또는 xvalue 가 rvalue 에 해당함.
	 (즉 대입 연산자를 기준으로 오른쪽에 있는 것들. e.g. temporary objects, results of operations)

	** 레퍼런스 선언 이후 해당 레퍼런스에 적용되는 연산 (operation) 들은 전부 해당 레퍼런스가 가리키는 데이터에 대한 연산으로 취급됨.

	(1) Pass-by-Reference
	: Pass by address 와 매커니즘이 동일하며, 함수 파라미터 혹은 리턴 값으로써 레퍼런스가 쓰일 경우,
	 해당 파라미터 혹은 리턴 값을 이용해 그 레퍼런스가 가리키는 원본 데이터를 수정할 수 있음.
*/

void f1(int* pi)
{

}

void f2(int& ref)
{

}

void _2()
{
	int i = 3;

	int& r1 = i;

	int&& r2 = 5;

	i = i;

	f1(&i);
	f2(i);

	class A { public: void func() { } } a;

	// lvalue reference
	A& refA = a; // A 타입의 오브젝트 a를 가리키는 레퍼런스 (참조)

	A();

	A a2(); // A a2;
	A a2;

	// rvalue reference
	A&& refB = A(); // A 타입의 temporary 오브젝트를 가리키는 레퍼런스

	// 레퍼런스에 대한 연산은 해당 레퍼런스가 가리키는 오브젝트에 대한 연산으로 취급됨
	refA.func();
	refB.func();

	A b;
	refA = b; // refA 가 가리키는 오브젝트에 b의 데이터를 복사.
}

void pass_by_ref(int& refA)
{
	refA = 10; // refA 가 가리키는 int variable 의 값이 변경됨.
}

int& return_by_ref(int& ref)
{
	return ref; // 주의: 레퍼런스를 리턴하는 함수 내에서 local variable 을 리턴해서는 안됨. (lifetime 이 함수가 리턴되며 끝나기 때문)
}

void _2_1()
{
	int i = 3;
	pass_by_ref(i); // pass by reference

	// i의 값은 10

	return_by_ref(i) = 5; // return_by_ref 가 int& 를 리턴하기에 해당 레퍼런스가 가리키는 int variable 의 값을 변경 가능
}

/*
	3. Mutability (상수성)
	: 어떤 오브젝트 혹은 데이터의 상태가 변경될 수 있는 지에 대한 속성. C/C++ 에서는 mutable 과 const, 이 두 키워드가 이 속성을 표현하는데 쓰임.

	(1) const for objects (or variables)
	: 어떤 오브젝트의 상태 (혹은 데이터) 를 전부 immutable 하게 함. 즉, 그 오브젝트를 변경 불가능하게 만듬. (이 때, primitive type 의 오브젝트들도 포함)

	(2) const for pointers
	: const 의 위치에 따라 의미하는 바가 달라짐.
	const <type> * => 해당 포인터가 가리키는 "데이터"가 상수. 즉, 포인터를 역참조한 뒤 변경이 불가능함.
	<type> const * => 위와 동일
	<type> * const => 해당 포인터 "자체"가 상수. 즉, 포인터 자체에 변경이 불가능함.

	(3) const for references
	: 항상 const <type> &<identifier> 의 형태로만 쓰일 수 있으며, 레퍼런스 그 자체는 상수로 만드는게 의미가 없음. (이미 레퍼런스 자체가 선언 시부터 상수로 취급되므로)
	 해당 레퍼런스가 가리키는 데이터 (혹은 variable) 이 상수임을 나타냄.

*/

void _3()
{
	// (1)
	const double d1 = 3.0; // d1 은 선언 이후에는 값이 변경될 수 없음.
	d1 = 5.0; // 오류

	// (2)
	int a = 3, b = 4;
	const int* pA = &a; // pointer to const
	*pA = 10; // 오류
	pA = &b; // 가능

	int const* pB = &a; // pointer to const
	*pB = 7; // 오류
	pB = &b; // 가능

	int* const pC = &a; // const pointer
	*pC = 13; // 가능: pC 가 가리키는 데이터는 상수가 아님.
	pC = &b; // 오류: pC 자체가 상수임.

	int i = 5;
	// (3)
	int& const id = i; // redundant: 레퍼런스는 선언 이후부터는 가리키는 대상을 변경할 수 없음.
	const int& id2 = i; // legal -> id2 가 가리키는 데이터, 즉 i 의 값이 상수.
	id2++; // 오류: id2 가 가리키는 데이터가 상수.
}

/*
	4. Const and Mutable in Classes
	: C++ 클래스 내에서 const 와 mutable 은 variable 혹은 function 둘 중 어느 곳에 적용되느냐에 따라 다른 의미를 가짐.

	(1) const for member variables
	: 일반적으로 const 로 선언된 variable 과 의미가 동일. 해당 멤버 변수의 값이 변경될 수 없음.
	 * 주의: const 로 선언된 멤버 변수의 경우 default value 지정 혹은 member initializer list 에서만 초기값을 지정해줄 수 있음.

	(2) const for member functions
	: 해당 멤버 함수 자체를 상수로 만듬. 즉, 해당 멤버 함수 내에서는 해당 오브젝트를 변경하려는 어떤 행위든 불가능.
	(e.g. 멤버 변수의 값을 변경하려는 것)
	 따라서 const 멤버 함수 내에서는 해당 오브젝트에 대해 const 멤버 함수만 호출 가능.

	(3) mutable for member variables
	: const object 에서 mutable 로 선언된 멤버 변수의 경우, 해당 오브젝트가 상수임에도 불구하고 해당 멤버 변수의 값을 변경할 수 있음.
	 또한, 해당 오브젝트의 const 멤버 함수들도 해당 멤버 변수의 값을 변경 가능.

	(4) const objects
	: 어떤 클래스의 인스턴스를 const 로 선언하는 경우. 즉, const 로 선언된 variable 과 동일한 효과를 지님.
	 단, 오브젝트의 경우 상수로 선언되있을 시, 해당 오브젝트에 대해 const member function 만 호출 가능.
*/

void _4()
{
	class C1
	{
	public:
		C1() : d(10) // d는 상수 멤버이기에 member initializer list 에서 초기화 해주어야 함.
		{
			i = 5; // 오류: constructor body 안에서 상수 멤버의 값을 변경할 수 없음.
		}

		void const_member_func1() const // 멤버 함수를 const 로 선언할 경우에는 const 가 () 뒤에 옴
		{
			f = 5; // 오류: const 멤버 함수 내에서 멤버 변수의 값을 변경할 수 없음.
			non_const_member_func(); // 오류: const 멤버 함수 내에서 다른 non-const 멤버 함수를 호출할 수 없음.

			const_member_func2(); // 가능: const 멤버 함수 내에서 다른 const 멤버 함수 호출 가능.
		}

		void const_member_func2() const
		{
			l = 5L; // const 멤버 함수지만 l 은 mutable 로 선언되어 const 멤버 함수 내에서도 변경 가능.
		}

		void non_const_member_func()
		{

		}

		int public_var1;
		mutable int public_var2;

	private:
		const int i = 3; // i 는 초기값을 지정해주기에 member initializer list 에서 따로 초기화가 필요하지 않음.
		const double d;
		float f;

		mutable long l;
	};

	const C1 c; // const 오브젝트.
	c = C1(); // const variable 과 마찬가지로 c의 값을 변경 불가능.

	c.non_const_member_func(); // 오류: const 오브젝트에 대해 non-const 멤버 함수 호출 불가능.
	c.const_member_func1(); // 가능: const_member_func1 은 const 멤버 함수이기 때문.

	c.public_var1 = 5; // 오류: 상수 오브젝트의 멤버 public_var1 를 변경하려 했기 때문.
	c.public_var2 = 10; // 가능: c는 상수 오브젝트이지만 public_var2 는 mutable 로 선언됬기 떄문.
}