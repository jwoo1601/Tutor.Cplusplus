/*
	1. Types of Constructors
	: C++ 에는 다양한 종류의 constructor 가 존재함. 또한, C++11 이후로 constructor 를 제거하거나 디폴트 지정이 가능해짐.

	#: 따로 정의하지 않을 경우 컴파일러가 자동으로 만들어줌

	(1) Default constructor (디폴트 생성자)#
	: argument 의 갯수가 0개 이거나 argument 없이 호출할 수 있는 constructor.

	(2) Copy constructor (복사 생성자)#
	: 같은 타입의 상수 오브젝트에 대한 레퍼런스를 argument 로 취하며, 해당 오브젝트의 내용을 현재 오브젝트에 복사 생성하는 constructor.

	(3) Converting constructor (변환 생성자)
	: 어떤 다른 임의의 타입의 '단일' 오브젝트로 부터 데이터를 변환하여 현재 오브젝트를 생성하는 constructor.
	(이때, explicit 키워드가 사용되지 않아야 함.)
	* 변환 생성자는 implicit conversion 이 가능하게 함.

	(4) Move constructor (이동 생성자)#
	: 같은 타입의 어떤 오브젝트에 대해 해당 오브젝트가 소유한 데이터의 소유권을 현재 오브젝트로 '이전'하는 constructor.

	(4) explicit specifier
	: 해당 constructor 가 explicit 임을 표시함. 즉, 해당 constructor 가 implicit conversion 과 copy initialization 맥락에서 사용될 수 없음.
	(즉, explicit conversion 이 필요함)
*/

class Car
{
public:

	Car(int size, int maxSpeed, int hoursePower ...)
	{

	}

private:
	int size;
	int maxSpeed;
	int hoursePower;
	int maxDistance;
	int colour;
	const char* name;
	const char* brand;
};

void dd()
{
	Car hyundai_sonata2; // default constructor
	Car hyundai_sonata(); // default constructor

	hyundai_sonata2.size = 100;
}

void _1()
{
	class File
	{
	public:

		File() // (1) default constructor
		{
			printf("Default Constructor!\n");
		}

		// const File f1;
		// File f3 = f1;
		// File other = f1;

		// f3 의 copy ctor 호출 -> f1이 other 에 복사 -> other 의 copy ctor -> f1 이 other2 에 복사 -> other2 의 copy -> ...

		/*
			Class이름(const Class이름& other)
			{ }

			A(const A& other)
		*/

		File(const File& other) // (2) copy constructor
		{
			printf("Copy Constructor!\n");
			data = other.data; // 같은 타입의 어떤 오브젝트 other 의 데이터를 현재 오브젝트 (자기자신)에 복사.
		}

		File(int fileData) // (3) converting constructor
		{
			printf("Int Converting Constructor!\n");
			data = process(fileData);
		}

		File(int a, int b, int c)
		{
			printf("3-Argument Constructor!\n");
		}

		// other: ~~~

		File(File&& other) // (4) move constructor
		{
			printf("Move Constructor!\n");
			// File 타입의 어떤 오브젝트 other 의 데이터의 소유권을 현재 오브젝트로 '이전'함.
			data = other.data; // 데이터 복사
			other.data = 0; // 데이터를 소유하던 오브젝트의 데이터를 invalidate.
		}

		explicit File(const char* fileData) // implicit 하게 즉, 암묵적으로 호출될 수 없음
		{
			printf("String Converting Constructor!\n");
			data = atoi(fileData);
		}

	private:
		int data;
	};

	// 기본 constructor 를 호출하는 방법
	// Class이름 오브젝트이름(파라미터);

	File f1; // implicit default initialization
	File f2(); // explicit default initialization

	File f3 = f1; // copy initialization
	File ff3(f1); // explicit copy initialization

	File f4 = 5; // implicit converting initialization from int
	File f42(5); // explicit **
	File ff4 = 10.5; // File(double) -> File(int)
	// File(int)

	File f5 = File(); // move initialization
	File ff5(File());

	// string literal 은 C/C++ const char * 로 취급됨
	// string 형태의 converting constructor
	File f6 = "implicit"; // error: implicit conversion; due to explicit
	File f8("explicit"); // success: another explicit call to the constructor
}

class PlasticBottle;
class Glass;

class Plastic
{
public:

	Plastic(PlasticBottle &bottle)
	{

	}

	Plastic(Glass& other) // 논리적으로 말이 안됨 (X)
	{

	}
};

/*
	PlasticBottle a;
	Glass g;

	Plastic p = a;
	Plastic p2 = g;
*/

/*
	2. Shallow-copy (얕은 복사) vs Deep-copy (깊은 복사)
	: 프로그래밍에서 데이터를 복사하는 방식의 차이.

	(1) Shallow copy
	: 어떤 데이터를 source 에서 destination 으로 '표면적으로' 복사를 하는 것. 즉, src 의 데이터를
	bit-wise 로 dest 로 복사함.
	* shallow copy 는 많은 경우에 예기치 않은 버그를 발생시킬 수 있음.

	(2) Deep copy
	: 어떤 데이터를 source 에서 destination 으로 논리적으로 '완전하게' 복사하는 것. 즉, src 의 데이터가
	어떤 다른 데이터를 참조 (reference) 하고 있을 경우, 해당 참조까지 완전히 복사함.
*/

void _2()
{
	class Shallow
	{
	public:

		Shallow()
		{

		}

		Shallow(const Shallow& other)
		{
			data1 = other.data1;
			data2 = other.data2;
			message = other.message;
		}

	private:
		int data1;
		int* data2;
		const char* message;
	};

	Shallow s1;
	Shallow s2 = s1;

	/*
	        ---------------------------
		s1: | data1 | data2 | message |
		    ---------------------------
			    |       |        |
			   \ /     \ /      \ /
			---------------------------
		s2: | data1 | data2 | message |
		    ---------------------------

		     s1.data2 -> int <- s2.data2
	*/

	class Deep
	{
	public:

		Deep(const Deep& other)
		{
			data1 = other.data1;
			
			for (int i = 0; i < 4; i++)
			{
				data2[i] = other.data2[i];
			}

			message = other.message;
		}

	private:
		float data1;
		double data2[4];
		const char* message;
	};

	/*
			---------------------------
		s1: | data1 | data2 | message |
			---------------------------
				|       |        |
			   \ /     \ /      \ /
			---------------------------
		s2: | data1 | data2 | message |
			---------------------------

			 s1.data2 -> double[4]
			 s2.data2 -> double[4]
	*/

	class DefaultCopy
	{
	public:

		DefaultCopy(const DefaultCopy& other)
		{
			data1 = other.data1;
			data2 = other.data2;
			data3 = other.data3;
		}

	private:
		int data1;
		float data2;
		double data3;
	};
}