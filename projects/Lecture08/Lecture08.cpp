/*
	1. Function overloading
	: 같은 identifier 를 가지지만 function signature 는 다른 function 들을 두 개 이상 정의하는 행위.

	(1) function signature
	: 어떤 함수에서 해당 함수의 리턴 타입을 제외한, 다른 function 과 구분해주는 unique 한 시그니쳐로 사용되는 부분.
	즉, 해당 function 의 declaration 에서 리턴 타입을 제외한 parameter types, num of parameters, cv-qualifiers, ref-qualifier 등이
	어떤 function 을 identifier 가 같은 다른 function 과 구분해주는 signature 로 사용됨.

	**function signature of void Class1::print(int par1, double par2) const:
	Class1::print(int, double) const
	-> 리턴 타입과 parameter 의 이름은 포함되지 않음.

	(2) function overloading
	: 일반적으로 identifier 는 같지만 parameter 의 타입 혹은 갯수를 다르게 만들어 다른 타입 혹은 파라미터 갯수에 대해 같은 로직의
	다른 구현을 만들고 싶은 경우, function signature 만을 다르게 하여 같은 이름의 여러 함수를 정의할 수 있음.

	(3) name mangling
	: C++ 컴파일러는 같은 identifier 를 가지지만 signature 가 다른 여러 함수의 정의가 가능하도록 하기 위해 name mangling 이라고 부르는 특수한 기능을 수행함.
	컴파일러마다 각자의 방식으로 identifier 가 같지만 signature 가 다른 함수들의 이름을 바꿔 저장함.
	e.g.     void h(int)	void h(int, char)	void h(void)
	MSVC     ?h@@YAXH@Z	    ?h@@YAXHD@Z	        ?h@@YAXXZ
	GCC	     _Z1hi	        _Z1hic	            _Z1hv
*/

namespace _4
{
	void print(int a)
	{

	}

	void print(const int a)
	{

	}

	void print(const char* str)
	{

	}

	void print(double d)
	{

	}

	void print(class Class1* c1)
	{

	}

	int print(class Class1* c1) // 리턴 타입은 function signature 에 해당되지 않음.
	{

	}

	class Class2
	{
	public:

		void func1() const // const 의 유무도 function signature 에 해당함.
		{
			
		}

		void func1()
		{

		}
	};
}

/*
	2. Operator overloading
	: C++ 에서는 operator 들도 function 의 일종으로 작동함. 즉, operator 도 function 처럼 오버로딩 가능.

	(1) 필수적으로 오버로딩 해야하는 operators:
	= (copy assignment, move assignment)

	(2) 자주 쓰이는 operators:
	+, -, +=, ++, --, () (function call), tyep-casting operators

	a + b
	a += 3;

	// prefix and postfix
	++a; // prefix increment => a 값이 1 증가되고 그 뒤에 값이 평가됨
	a++; // postfix increment => a 의 값이 평가가 되고 그 뒤에 a 값을 1 증가시킴

	int a = 3;
	int b = ++a; // a 가 1 증가되서 4가 된 뒤에 그 값이 평가되서 b 에 대입됨 (b의 값은 4)
	int b = a++; // a 값이 먼저 평가가 되고 그 뒤에 a 값이 1 증가됨 (b의 값은 3, 그리고 a 는 4)

	a + 1 // 리턴값을 저장하지 않으면 날아감
	a++ 혹은 ++a 는 a 값을 직접적으로 변경

	--a; // prefix decrement
	a--; // postfix decrement

	(3) Overloading 이 불가능한 operators:
	. (member selection), :: (scope resolution), ?: (ternary conditional expression), sizeof

	(4) Operator overloading 이 가지는 의의
	: C++ 클래스들이 각종 연산(operation) 에 사용될 수 있게 함으로써 사용자가 정의한 클래스들이 보다 더 "타입"의 역할을 수행할 수 있게함.

	(5) Member operators vs global operators
	: 멤버 operator 의 경우 원래 해당 operator 가 필요로 하는 operand 의 갯수에서 하나 뺸 수만큼의 parameter 가 필요함.
	e.g. a + b 라는 연산식에서 + operator 는 원래 좌변과 우변, 총 2개의 operand 를 필요로 함.
		하지만, 이 + operator 가 member operator 로 정의될 경우, +
*/

/*
	ComplexNumber c1;
	ComplexNumber c2 = c1; // copy constructor (선언)
				  c2 = c1; // copy assignment operator (정의)
				  c3 = c2 = c1; (결합순서: right to left)

				  c2 = c1 => c2.operator=(c1)

				  // operator 결합 순서
				  : 같은 operator 가 동시에 여러개 사용되었을 떄 어느 방향으로부터 연산이 진행되는지

	int a = 3, b = 4;

	+ 연산: 좌변과 우변의 값을 읽어와서 더한뒤에 그 결과값을 리턴
	int c = a + b; // a 나 b 둘중에 하나라도 변경을 하는지? X
*/

/*
	Member operator (멤버 function 인 operator) 에서 연산 좌변 혹은 첫번째 항은 무조건 current object
*/
class ComplexNumber
{
public:
	ComplexNumber(double real, double imaginary)
		: m_real(real), m_imaginary(imaginary) { }

	// 특수한 이 클래스만의 복사하는 logic 이 필요
	ComplexNumber(const ComplexNumber& other) // Unnecessary; 따로 정의하지 않아도 컴파일러가 기본적으로 생성하는 default copy ctor 만으로도 충분함.
		: m_real(other.m_real), m_imaginary(other.m_imaginary) { }

	// return-type operator+(____)

	// Member operator 가 필요로하는 parameter 의 갯수는 그 operator 의 원래 피연산자(operand) 의 갯수 - 1
	// 이유: member operator 는 member function 이기 때문에 기본적으로 첫번째 연산자가 무조건 current object

	// assignment operator 가 필요로 하는 피연산자 갯수: 2
	// (1) overloading of copy assignment operator
	ComplexNumber& operator=(const ComplexNumber& other) // 실제 형태: ComplexNumber& operator=(ComplexNumber *this, const ComplexNumber& other)
	{
		m_real = other.m_real;
		m_imaginary = other.m_imaginary;

		// dereference 연산: 해당 포인터가 가리키는 값(혹은 오브젝트) 자체를 가져옴
		// ComplexNumber *this; -> *this 
		return *this;
	}

	int main()
	{
		ComplexNumber c1, c2;
		ComplexNumber c3 = x의 사본;

		(c3 = c1) => &c3;

		ComplexNumber c4 = c3 의 주소;
	}

	// Complex = Complex + Complex
	// (2) overloading of + (addition) operator
	ComplexNumber operator+(const ComplexNumber& other) const // 이 operator 는 current object 는 수정하지 않음.
		// return type: 두 오브젝트 a + b 의 연산 결과는 a 랑 b 에는 영향을 주지 않는, a 와 b의 값이 더해지는 "사본(copy)" 이어야 함.
		// parameter: 이 operator 의 
	{
		//return ComplexNumber x(m_real + other.m_real, m_imaginary + other.m_imaginary);
		return ComplexNumber(m_real + other.m_real, m_imaginary + other.m_imaginary);
	}

	// (2) overloading of - (subtraction) operator
	ComplexNumber operator-(const ComplexNumber& other) const // 이 operator 는 current object 는 수정하지 않음.
	{
		return ComplexNumber(m_real - other.m_real, m_imaginary - other.m_imaginary);
	}

	// (2) overloading of += operator
	ComplexNumber& operator+=(const ComplexNumber& other)
		// return type: a = b, a += b 의 등의 대입 연산식은 항상 대입받은 쪽(a)에 대한 레퍼런스를 리턴함
		//              이유: a += b += c -= d 등의 chaining 이 가능하게 하기 위해서. (이 때, 결합 순서는 right to left)
	{
		*this = *this + other;

		return *this;
	}

	// (2) overloading of -= operator
	ComplexNumber& operator-=(const ComplexNumber& other)
	{
		*this = *this - other;

		return *this;
	}

	// (2) overloading of ++ (prefix) operator
	ComplexNumber& operator++()
		// return type: ++a, --b 와 같은 prefix increment/decrement 의 연산식은 증감/감소된 대상에 대한 l-value reference 를 리턴해야 함.
		//              따라서, ++a = b; 와 같은 연산식이 가능함. (a를 증가 후 b의 값을 a에 대입)
		//              b = ++a; 이 연산식은 a 를 먼저 증가시킨 이후, a 값을 평가해 b 에 대입해야 하므로 
		//                       ++a 에서 증가된 대상(자기자신)이 리턴이 되어야 b 에 '증가된 값'이 대입될 수 있음.
	{
		*this += ComplexNumber(1.0, 1.0);

		return *this;
	}

	// (2) overloading of -- (prefix) operator
	ComplexNumber& operator--()
	{
		*this -= ComplexNumber(1.0, 1.0);

		return *this;
	}

	// (2) overloading of ++ (postfix) operator
	ComplexNumber operator++(int)
		// return type: 
	{
		ComplexNumber temp = *this;
		++*this;

		return temp;
	}

	ComplexNumber operator--(int)
	{
		ComplexNumber temp = *this;
		--*this;

		return temp;
	}

	// (2) overloading of function call () operator
	// : function call operator 는 정해진 형태를 가지지 않음. 즉, logical 하게 말이 되는 한에서는 어떤 parameter/return type 을 써도 무방.
	// (주로 function object 에서 사용이 됨)
	ComplexNumber& operator()(double real, double imaginary)
	{
		m_real = real;
		m_imaginary = imaginary;

		return *this;
	}

	// (2) overloading of casting operator (to double)
	operator double() const // 이 operator 는 current object 를 변경하지 않음.
	{
		return m_real;
	}

	explicit operator const char*() const
	{
		return "Real Number";
	}

private:
	// Tip: 멤버 variable 들의 경우, 일반적으로 constructor 의 paramete 와 이름이 겹치기 때문에 "my" 를 의미하는 m_ 접두사를 붙여줌.
	double m_real;
	double m_imaginary;
};

// Functor
class Add
{
public:
	ComplexNumber operator()(const ComplexNumber& a, const ComplexNumber& b) const
	{
		return a + b;
	}
};

void _2()
{
	ComplexNumber c1(1.5, 3.4);
	ComplexNumber c2(2.4, 6.9);

	// declaration (선언): 어떤 이름의 존재를 알려줌.
	// definition (정의): 어떤 이름에 의미(값)를 부여.

	int a; // declaration -> 무조건 타입 이름;
	a = 5; // definition -> 타입 x

	// operator +
	ComplexNumber c3 = c1 + c2; // copy constructor (constructor 는 선언에서만 호출)
	ComplexNumber c4 = c3 = c1 + c2; // copy assignment operator (선언 이후에만 호출)
	// operator -
	ComplexNumber c4 = c2 - c1;

	// operator +=
	c4 += c3 += ComplexNumber(2.0, -1.5);
	// operator -=
	c4 -= c3 -= ComplexNumber(1.0, 0.3);

	// operator ++ (prefix)
	ComplexNumber c5 = ++c3 + c4;
	// operator -- (prefix)
	ComplexNumber c6 = --c4 + c3;

	// operator ++ (postfix)
	c5 = c4++ + c3;
	// operator -- (postfix)
	c6 = c3-- + c4++;

	// casting operators
	double realNum = c5;
	const char* realNumString = c5; // Error: ComplexNumber -> const char * 로 변환하는 operator 가 explicit 이기 떄문.
	const char* realNumString2 = (const char*)c5;

	// function call operator
	ComplexNumber c7 = Add()(c5, c6); // Add 타입의 익명 object 를 생성한 뒤, 해당 오브젝트의 function call operator 를 바로 호출함.
	Add add;
	ComplexNumber c8 = add(c3, c4); // Add 타입의 오브젝트인 add 를 마치 함수처럼 호출할 수 있음.
	                                // 이런 형태로 function call operator 를 overloading 하는 오브젝트들을 function object 혹은 functor 라고 부름.
}

/*
	3. Helper functions and friend

	(1) helper functions
	: global function 들로써, 어떤 클래스의 기능을 보조 혹은 보충하는 역할로 사용됨.

	(2) friend class
	: OOP 의 핵심 원칙 중 하나인 privacy 에 반대되지만, 두 클래스 간의 관계에서 한 클래스가 다른 클래스에 필연적으로
	 접근해야 할 경우, 해당 클래스에 대해서만 이 원칙에 예외를 적용함.
	 즉, 어떤 클래스 A 가 어떤 클래스 B 의 friend 로 지정될 경우,  클래스 A 내에서는 클래스 B 의 private/protected 멤버에도 접근할 수 있음.

	(3) friend function
	: friend 클래스와 마찬가지로, 어떤 클래스의 friend 로 지정된 function 은 (다른 클래스의 멤버 function 혹은 global function)
	 해당 클래스의 private 멤버에 무제한적으로 접근할 수 있음.

	(4) how to implement helper functions
	: 일반적으로 어떤 클래스의 기능을 보조하는 helper function 의 경우, 해당 클래스의 오브젝트를 parameter 로 전달받아
	 내부적으로 처리하는 방식으로 logic 을 전개함. 이 때, 이 helper function 내에서 해당 오브젝트를 임의로 변경하기 위해서는
	 이 helper function 이 해당 클래스의 friend 로 지정이 되어야 함.
*/

class Engine
{
	friend class Car;
	friend void Ship::SetSpeed(float newSpeed);
	friend void SetAcceleration(Engine&, float);

public:

	void Start(float acceleration)
	{
		m_bStarted = true;
		m_acceleration = acceleration;
		m_currentSpeed = m_acceleration;
	}

	void Update(float drag)
	{
		const void* ptr;
		if (m_currentSpeed + m_acceleration - drag <= m_maxSpeed)
		{
			m_currentSpeed += m_acceleration - drag;
		}
	}

	void StopImmediately()
	{
		m_bStarted = false;
		m_acceleration = 0.0f;
		m_currentSpeed = 0.0f;
	}

private:
	bool	m_bStarted;
	float	m_currentSpeed;
	float	m_maxSpeed;
	float	m_acceleration;
};

class Car
{
public:

	void StartMove()
	{
		m_engine.Start(4.0f);
	}

	void SetSpeed(float newSpeed)
	{
		// m_currentSpeed 멤버는 m_engine 의 private member.
		// 이 때, 이 private 
		m_engine.m_currentSpeed = newSpeed / 1000;
	}

	void StopMoveImmediately()
	{
		m_engine.StopImmediately();
	}

private:
	Engine	m_engine;
};

class Ship
{
public:

	void StartMove()
	{
		m_engine.Start();
	}

	void SetSpeed(float newSpeed)
	{
		m_engine.m_currentSpeed = newSpeed * 1.94384;
	}

	void StopMoveImmediately()
	{
		m_engine.StopImmediately();
	}

private:
	Engine	m_engine;
};

void SetAcceleration(Engine& engine, float acceleration)
{
	engine.m_acceleration = acceleration;
}

void _3()
{
	Car c;
	c.SetSpeed(5000.0f);
}