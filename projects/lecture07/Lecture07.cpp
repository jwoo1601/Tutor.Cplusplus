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

		// other ------------> File
		//                     const
		// 1. 복사 constructor -> 즉, 원본 오브젝트는 그대로 변경하지 X. 원본 오브젝트는 읽기만 해야 됨.
		// 2. 원본 오브젝트는 읽기만 해야되기 떄문에 아예 const object 라도 됨.

		// const File f1;
		// File f3 = f1;

		// File other = f1;
		// File (File other2)

		// File other2 = f1;
		// File (File other3)

		// ... 무한반복

		File(const File &other) // (2) copy constructor
		{
			printf("Copy Constructor!\n");
			this->data = other.data; // 같은 타입의 어떤 오브젝트 other 의 데이터를 현재 오브젝트 (자기자신)에 복사.
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

	const File cf1;
	File fff3 = cf1;

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

			data[1] = 5;
		}

	private:
		int data1;
		int* data2;
		const char* message; // c-style string
	};

	// C 에서 String (문자열) 표현 방식 (array of chars)
	// ... | H | e | l | l | o | \0 |... => "Hello"
	// '\0' (null character/terminator) -> ascii code: 0
	// printf("Hello"); -> 보이지 않는

	// double quote ("") 을 이용해 문자열을 값 형태(literal) 로 넣어주면 자동으로 컴파일러가 맨 뒤에 null character 를 넣어줌.
	// char str[] = "Hello";
	// str -> | H | e | l | l | o | \0 |

	// char array 는 초기화 할떄 외에는 string literal 로부터 대입을 받을 수 없음.
	// char str2[3 + 1];
	// str2 = "sdd"; (X) illegal
	// (1) str2[0] = 's';
	//     str2[1] = 'd';
	//     str2[2] = 'd';
	//     str2[3] = '\0';
	// (2) strcpy(str2, "sdd");

	// array variable 의 이름 자체는 해당 array 의 첫번째 element 를 가리키는 (즉, 첫번쨰 element 의 주소를 가지는) 포인터 variable
	// const char *msg = "Hello"; // msg 는 여기서 Hello 를 가리키기만 형태
	// char msg2[6] = "Hello"; // msg2 는 메모리 공간을 새로 할당해서 array 를 만들고 그 안에 Hello 라는 값을 복사함

	// const char *message = "Hello";
	// message 의 내용을 변경하지 않을 경우

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

			// data2 = other.data2;

			message = other.message;
		}

	private:
		float data1;
		// double * const data2
		// data2 = ... (x)
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

/*
	3. Current object and this pointer
	: 클래스의 멤버 함수 내에서 해당 함수가 "현재 대상이 되는" 오브젝트를 current object 라고 함.

	(1) Representation of current object
	: current object 에 explicit 하게 접근하기 위해서는 parameter 로 해당 오브젝트를 전달받아야 함.

	(2) Difference between member functions and global functions
	: 멤버 함수와 전역(global) 함수는 단 하나의 가장 큰 차이점을 가짐.
	-> 멤버 함수는 호출(call) 될 때 해당 함수가 취하는 parameter 들에 상관없이
	   제일 "첫 번째 parameter" 로 해당 함수가 호출되는 "대상 오브젝트"에 대한 "상수 포인터"를 취함.

	(3) This pointer
	: 멤버 함수가 호출되는 대상 오브젝트에 대한 상수 포인터의 이름(identifier) 는 항상 this 임.
	this 를 이용해 current object 의 다른 멤버들에 접근할 수 있음.
*/

namespace _3
{
	#include <string>
	using namespace std;

	class Car
	{
	public:
		Car() { }

		Car(const string& name, const string& brand, double speed)
		{
			// (3) this pointer
			// 이 경우와 같이 parameter 의 이름과 member variable 의 이름이 겹치는 경우,
			// 이름만으로는 member variable 에 접근할 수 없음 (parameter 가 속한 멤버 함수의 function scope 이 해당 함수가 속한 class scope 의 inner scope 이기 때문)
			// 즉 이 경우에서는 parameter 에 있는 name, brand, speed 가 member variable 인 name, brand, speed 를 "shadowing" 함.
			this->name = name;
			this->brand = brand;
			this->speed = speed;

			name = name; // parameter 인 name 에 자기 자신 대입. 하지만 name 은 ref-to-const object 이므로 name 이 가리키는 대상이 상수.
						 // 따라서, name 이 변경 불가능하므로 오류가 남.
		}

		// this 는 implicit 하게 멤버 함수에 전달되는 첫 번째 parameter.
		// 즉, 따로 this 를 parameter 로 받지 않아도 컴파일러가 자동으로 생성함.
		const string& GetName() const
		{
			// this 는 항상 Class* const this 형태로 정의됨.
			// 즉, 이때 GetName 은 Car 클래스 내부에 있으므로 이떄 Class 는 Car 이 됨.
			// => Car* const this
			return this->name;
		}

		const string& GetBrand() const
		{
			// 이떄, this 를 통한 접근이 꼭 필요하진 않음.
			// 즉, return brand; 만으로도 충분. 이유: brand 라는 이름이 이 scope 에서 하나밖에 없으므로
			return this->brand;
		}

		double GetSpeed() const
		{
			return speed;
		}

		Car& SetName(const string& name)
		{
			// 이 때, name 은 현재 scope 에 2개가 정의되어 있으므로 this 를 이용해 접근하지 않는다면
			// member variable 의 name 은 parameter 의 name 에 가려짐.
			this->name = name;

			// 이 떄, this 는 Car 을 가리키는 포인터 이므로 this 를 dereference 하게 되면 해당 포인터가 가리키는 오브젝트를 의미함.
			// 또한 this 가 가리키는 대상은 current object 이므로 아래 return 에서는 현재 오브젝트에 대한 reference 를 리턴하는 거로 생각할 수 있음.
			return *this;
			// Car *this

			Car &refToThis = *this; // 즉, refToThis 가 가리키는 대상은 current object 임.
		}

		Car& SetBrand(const string& brand)
		{
			this->brand = brand;

			return *this;
		}

		Car& SetSpeed(double speed)
		{
			this->speed = speed;
			
			return *this;
		}


		// void obj.DummyFn(Car *this);
		void DummyFn()
		{
			Car obj;
			this = &obj; // this 는 const pointer (상수 포인터) 이므로 this 가 가리키는 대상을 변경할 수 없음.
		}

		void PrintCar() const
		{
			printf("Car: name=%s, brand=%s, speed=%s\n", name.c_str(), brand.c_str(), speed);
		}

	private:
		string	name;
		string	brand;
		double	speed;
	};

	void PrintCar(Car* const car)
	{
		// 이 때, GetName 의 this 로는 &car 이 전달됨. 즉 GetName 함수 내에서 this 는 PrintCar 의 parameter 인 car 을 가리키고 있음.
		const string& name = car->GetName();
		const string& brand = car->GetBrand();

		printf("Car: name=%s, brand=%s, speed=%s\n", name.c_str(), brand.c_str(), car->GetSpeed());
	}

	void main()
	{
		Car hyundai_sonata("Sonata", "Hyundai", 120.0);
		Car toyota_camry("Camry", "Toyota", 120.0);

		// 아래 두 PrintCar 은 정확하게 똑같은 동작을 하지만, 형태가 다름.
		hyundai_sonata.PrintCar(); // 멤버함수 PrintCar (Car::PrintCar)
		PrintCar(&hyunda_sonata); // 전역함수 PrintCar (::PrintCar)

		// 실제 내부적으로는 컴파일러가 Car::PrintCar 을 이런 형태로 인식함.
		void PrintCar(Car* const this);

		// 함수가 해당 오브젝트에 대한 레퍼런스를 리턴하는 경우, 아래와 같이 연속적으로 함수 호출을 연결할 수 있음.
		// 이를 function call chaining 이라 부름.
		hyunda_sonata.SetName("Santa Fe")
					 .SetBrand("Hyundai Motors")
					 .SetSpeed(200.0)
					 .PrintCar();

		// SetName 은 Car& 를 리턴
		// -> SetBrand 를 SetName 이 리턴하는 Car& 에 대해 호출
		// -> SetSpeed 를 SetBrand 가 리턴하는 Car& 에 대해 호출
		// -> PrintCar 를 SetSpeed 가 리턴하는 Car& 에 대해 호출
	}
}

void SetName(const string& name)
{
	m_name = name;
}

const string& GetName() const
{
	return m_name;
}

void main()
{
	Player p1;
	string s = p1.GetName();

	const Player p2;
	p2.SetName("sdf");
	p2.GetName();
}