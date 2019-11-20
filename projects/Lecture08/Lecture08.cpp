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

	(3) Overloading 이 불가능한 operators:
	. (member selection), :: (scope resolution), ?: (ternary conditional expression), sizeof

	(4) Operator overloading 이 가지는 의의
	: C++ 클래스들이 각종 연산(operation) 에 사용될 수 있게 함으로써 사용자가 정의한 클래스들이 보다 더 "타입"의 역할을 수행할 수 있게함.

	(5) Member operators vs global operators
	: 멤버 operator 의 경우 원래 해당 operator 가 필요로 하는 operand 의 갯수에서 하나 뺸 수만큼의 parameter 가 필요함.
	e.g. a + b 라는 연산식에서 + operator 는 원래 좌변과 우변, 총 2개의 operand 를 필요로 함.
		하지만, 이 + operator 가 member operator 로 정의될 경우, +
*/

class ComplexNumber
{
public:
	ComplexNumber(double real, double imaginary)
		: m_real(real), m_imaginary(imaginary) { }

	ComplexNumber(const ComplexNumber& other) // Unnecessary; 따로 정의하지 않아도 컴파일러가 기본적으로 생성하는 default copy ctor 만으로도 충분함.
		: m_real(other.m_real), m_imaginary(other.m_imaginary) { }

	// (1) overloading of copy assignment operator
	ComplexNumber& operator=(const ComplexNumber& other)
	{
		m_real = other.m_real;
		m_imaginary = other.m_imaginary;

		return *this;
	}

	// (2) overloading of + (addition) operator
	ComplexNumber operator+(const ComplexNumber& other) const
		// return type: 두 오브젝트 a + b 의 연산 결과는 a 랑 b 에는 영향을 주지 않는, a 와 b의 값이 더해지는 "사본(copy)" 이어야 함.
		// parameter: 이 operator 의 
	{
		return ComplexNumber(m_real + other.m_real, m_imaginary + other.m_imaginary);
	}

private:
	// Tip: 멤버 variable 들의 경우, 일반적으로 constructor 의 paramete 와 이름이 겹치기 때문에 "my" 를 의미하는 m_ 접두사를 붙여줌.
	double m_real;
	double m_imaginary;
};