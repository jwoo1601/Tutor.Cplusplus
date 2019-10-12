// Lecture 05 - C++ Language

class A
{
	int a;
	float d;

	void func1(int a, int b)
	{
		int a;
	}
};

/*
	클래스의 멤버 함수를 클래스 선언 외부에서 정의하는 법
	<return-type> <class-name>::<function-name>(<params>)
	{
		...
	}

	:: -> scope resolution operator

	:  -> colon
	;  -> semi-colon
*/

/*
	1. Constructors and Destructors
	- Constructors (생성자): 클래스의 멤버 함수로써, 클래스의 오브젝트들을 '초기화(initialization)'를 하는 역할을 함. (즉, 해당 오브젝트의 모든 멤버들을 초기화 해야 함)
	- Destructors (소멸자/파괴자): 클래스의 멤버 함수로써, 클래스의 오브젝트들을 '정리(cleanup)' 하는 역할을 함. (즉, 해당 오브젝트가 사용한 모든 리소스들을 해제하는 역할을 함)

	- (1) Declaration of constructors
	: has the same name as the class

	- (2) Declaration of destructors
	: has the same name as the class but with a prefix '~'

	- Types of constructors
	: default constructor, n-argument constructors, copy-constructor, move-constructor
*/

Number var1, var2;

class Number
{
public:
	int num;
	double num2;
	float num3;

	// 1 - (1)
	// Number 클래스의 default constructor; 해당 클래스의 모든 멤버를 초기화 함
	Number()
	{
		num = 0;
		num2 = 0.0;
		num3 = 0.0f;
	}

	// 1 - (2)
	~Number() // destructor 는 parameter를 하나도 가질 수 없음
	{
		
	}

	// ~ : tilde
};

/*
	2. Objects and Instantiation
	- Objects/Instance (객체/실체): 클래스의 메모리 상의 구현된 '실체'. 실제 메모리를 점유하며, 해당 오브젝트의 메모리 구조는 클래스에 선언된 형태로 구성됨.
	- Instantiation (객체화/실체화): 클래스를 객체로 만드는 작업. 즉, 클래스를 직접적으로 메모리에 구현하는 작업.

	- (1) Declaration of objects (a.k.a. instantiation of class)
	: 일반 variable 을 선언하는 것과 같은 형태를 가짐. 이 때, 오브젝트의 선언은 해당 '오브젝트'에 대해 constructor 를 호출함.
	<class-name> <identifier>; // default constructor 를 호출함.

	- (2) Accessing members of objects
	: class 가 instantiation 된 이후부터는 해당 오브젝트의 public 멤버 (멤버함수/멤버변수)에 대해 접근할 수 있게됨.
	<object-name>.<member-name> --> 이 때, member selection operator (.) 를 통해 접근.

	- (3) Accessing members of objects using pointers to objects
	: 어떤 클래스 타입의 "포인터"가 선언 되있을 경우, 해당 포인터를 이용해서 해당 포인터가 가리키는 "오브젝트"의 멤버에 접근 가능.
	<pointer-name>-><member-name> --> 이 때, (2)의 경우와는 다르게 member selection operator 의 arrow notation (->) 를 이용해 접근.
*/

void _()
{
	// 2 - (1)
	Number object;

	// 2 - (2): Number 타입의 오브젝트 object 의 멤버에 . 를 이용해 접근
	object.num = 3;
	object.num2 = 12.3;

	// 2 - (3):
	Number* pObject = &object;
	(*pObject).num = 4;

	pObject->num3 = 144.32f; // arrow notation (->) 을 이용해 접근
}

/*
	OOP 의 특징

	1. Encapsulation (캡슐화)
	2. Privacy
	3. Inheritance
	4. Polymorphism
*/

/*
	3. Access specifiers
	: 클래스의 멤버들의 접근 수준(Access level)을 지정함.

	- public
	: public 아래에 선언된 멤버들은 해당 클래스와 해당 클래스의 자식 클래스 뿐만 아니라 외부 어디에서나 접근 가능.

	- protected
	: protected 아래에 선언된 멤버들은 해당 클래스와 해당 클래스의 자식 클래스들만 접근 가능.

	- private
	: private 아래에 선언된 멤버들은 해당 클래스만 접근 가능.

	** default access specifier
	: 아무런 access specifier 도 없는 경우, class 의 경우 private 이, struct 의 경우 public 이 적용됨

	*** 클래스의 constructor 는 일반적으로 public 으로 선언해야함. 그렇지 않으면 클래스 외부에서는 해당 클래스의 object 를 생성할 수 없게 됨.
*/

class Class1
{
public:

	int publicvar;
	void publicfunc()
	{
		// Class1 안에서는 자기 자신의 private 혹은 protected 멤버에 접근 가능
		privatevar = nullptr;
		privatefunc();
		protectedvar = 5.f;
		protectedfunc();
	}

protected:

	float protectedvar;
	void protectedfunc()
	{

	}

private:

	int* privatevar;
	void privatefunc()
	{

	}
};

class Class2
{
	void func()
	{
		Class1 c1;
		c1.publicvar = 3;
		c1.publicfunc();
		// 위의 두 member 는 Class2 에서 접근 가능; public 으로 선언되있기 때문.

		// 아래 두 멤버는 각각 private, protected 로 선언되있기 때문에 Class2 에서는 접근 불가
		c1.privatevar = 5;
		c1.protectedfunc();
	}
};

void globalfunc()
{
	Class2 c2;
	c2.func(); // c2 의 func 함수는 globalfunc 내에서 접근 불가; default access specifier 가 private 이기 때문.
}


/*
	4. Member initializer list
	: 클래스의 constructor 에서 해당 클래스의 멤버들을 초기화 할 때 사용되며, constructor 의 body 보다 먼저 실행 됨.

	<class-name>::<class-name>() : member1(value), member2(value), ...
	{
	}


	(1) Specifying default values for member variables
	: class 의 declaration 에서 일반 멤버 variable 의 경우 = value 형태를 이용해 미리 default value 를 지정해 줄 수 있음.
	(default value 가 지정된 경우 construct 가 실행되기 전에 값이 초기화되기에 따로 초기화 불필요)
*/

class Class3
{
	int a;
	float b, c;
	double d, e;

public:

	Class3() : a(5), b(3.3f), c(4.5f), d(55.55), e(1.05)
	{

	}

private:

	// 4 - (1)
	int fff = 50;
	float ddd = 30.33f;
};