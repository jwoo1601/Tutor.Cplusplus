// Lecture 05 - C Language

/*
	1. Arrays (배열)
	: 같은 타입의 variable 을 선형의 연속적인 메모리 공간에 모아놓은 형태.
	 C/C++ 에서 array 는 해당 배열 내에서의 제일 첫번째 원소를 가리키고 있는 포인터 variable 로 나타냄.
	 해당 포인터가 가리키고 있는 주소를 변경할 수 없음.

	  ---------------------------------------------------------------------------
	  | Array[0] | Array[1] | Array[2] | Array[3] | Array[4] | ... | Array[n-1] |
	  ---------------------------------------------------------------------------
	  ^
	  |
	Array

	- Element (원소)
	: 해당 array 에 있는 각각의 variable 들을 element 혹은 원소라고 부름.
	- Index
	: Array 내에서의 어떤 element 의 위치. 맨 처음 원소를 기준으로 0부터 시작하며, n 개의 element 를 가진 array 에서 제일 마지막 인덱스는 n-1.

	** Array 의 각각의 원소들은 전부 "같은" 타입이기 때문에 모두 동일한 크기를 가짐.

	(1) Declaration of arrays
	: <type-of-elements> <identifier>[<size>] [= {<value1>, <value2>, ...}];
	(2) Indexing in arrays
	: 한 배열 내에서 임의의 index i에 대하여 해당 자리에 위치한 element 를 가져오는 것을 Indexing 이라고 하며,
	 C/C++ 에서는 아래 index operator (혹은 subscript operator) 를 이용해 인덱싱 가능.
	(3) Index operator (or subscript operator)
	: <array-name>[<index>] [= <value>];
*/

// 1 - (1)
int arr1[30]; // int 타입의 element 를 30개 가진 array 를 선언. 이 array 의 메모리 상에서의 총 크기는 sizeof(int) * 30 = 4 * 30 = 120 bytes.
double arr2[10]; // double 타입의 element 를 10개 가진 array 를 선언. 크기는 sizeof(double) * 10 = 8 * 10 = 80 bytes.
int arr3[5] = { 3, 6, 9, 12, 15 }; // int 타입의 element 5개를 가진 array 선언 후 0번째 index 부터 차례로 3, 6, 9, 12, 15 의 값들로 초기화.
int arr4[] = { 1, 2, 3 }; // initialization (초기화) 식을 바로 적는 경우에 한해 [] 안에 size 를 명시하지 않아도 컴파일러에서 자동으로 유추.
int arr5[3] = { 0 }; // 모든 element 를 0 으로 초기화.
int arr6[4] = { 1, 0 }; // 첫번째 element 만 1로 초기화 후 모든 element 0으로 초기화.

// sizeof operator
// : operand 가 타입인 경우 해당 타입의 size in bytes 를, operand 가 expression 인 경우 해당 expression 의 결과값의 타입의 size in bytes 를 리턴함.
// Usage:
// sizeof(<type>) or sizeof expression
int s1 = sizeof(int); // s1 = 4
int s2 = sizeof(int*); // 32bit 환경에서는 s2 = 4, 64bit 환경에서는 s2 = 8
int s3 = sizeof 5U; // expression 인 5U 의 타입을 평가. 즉, sizeof 5U = sizeof(unsigned int) = 4 

// 1 - (3)
void _1()
{
	double arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double d1 = arr[0]; // d1 에 arr 의 0번째 index 의 값, 즉 1.1 을 대입.
	arr[2] = 10.55; // arr 의 index 가 2인 위치, 즉 세 번째 element 자리 (3.3) 에 10.55를 대입.
	
	// C 에서는 array 를 변경 불가능한 포인터를 이용해 표현하기 때문에 아래 표현이 불가능.
	arr = &d1; // 에러
	// double *arr;

	// array 변수는 해당 array 의 첫번째 element 를 가리키는 포인터
	double d2 = *arr; // 따라서 arr 자체를 dereference 하게 되면 arr 의 index 가 0 인 element, 즉 1.1 을 말함.
}

/*
	2. Structs (구조체)
	: 다양한 타입의 variable 을 한 메모리 공간에 모아놓은 형태. C/C++ 에서는 하나의 타입으로 취급됨.
	 즉, user-defined type 의 일종. (struct 의 alignment 에 따라 각 variable 들이 메모리 상에 연속적으로 배열되어 있지 않을 수 있음)

	 - Member (멤버)
	 : 한 struct 내에 있는 각각의 variable 들을 해당 struct 의 멤버라고 부름.
	 - Offset
	 : 어떤 struct 내에서의 각 멤버들의 위치. 정수값으로 표현됨.

	 (1) Declaration of structs
	 : struct <identifier>
	 {
		<type> <identifier>;
		<type> <identifier>;
		...
	 } [tags];

	 (2) Initialization of members in structs
	 : C 에서 struct 선언 내에서 각 멤버들의 inline initialization 은 불가능. 따라서 해당 struct 타입의 variable 을 선언할 때 한번에 초기화 가능.
	 struct <name-of-struct> <identifier> [= {<value1>, <value2>, ... }];

	 (3) Accessing members in structs
	 : 한 struct 내의 각 멤버들에 접근하기 위해 . (member selection operator) 를 사용.
	 <name-of-struct-variable>.<name-of-member>

	 (4) Accessing members using pointers to structs
	 : 해당 struct 타입의 포인터를 사용할 경우 arrow notation (->) 을 이용해 해당 포인터를 dereference 하지 않고도 바로 접근 가능.
	 <pointer-to-struct>-><name-of-member>
*/

// 2 - (1)
struct Company // Company 는 이제 int, double 등과 같이 동등한 하나의 "타입"으로 인정됨
{
	char name[10];
	int numEmployees;
};

struct Company cmp; // Company 타입으로 variable 선언 가능. 이때, C++ 에서는 struct 키워드는 optional.

struct Phone
{
	char manufacturerer[20];
	char modelName[20];
	int year;
} galaxyS10, iphoneX; // struct 선언과 동시에 해당 struct 타입의 variable 선언.

// 2 - (2)
void struct_eg()
{
	struct Phone iphone8 = { "Apple Inc.", "iPhone 8", 2018 }; // 멤버들이 선언된 순서대로 manufacturerer 을 Apple Inc. 로, modelName 을 iPhone 8 으로 초기화.
	struct Phone galaxyFold = { .modelName = "Galaxy Fold", .manufacturerer = "Samsung", .year = 2019 }; // designated initialization. 즉, 해당 struct 의 멤버들을 어떤 순서든지 초기화 가능.

	// 2 - (3)
	printf("%s\n", iphone8.modelName);
	galaxyFold.year = 2020;

	// 2 - (4)
	struct Phone* pPhone = &iphone8;
	(*pPhone).year = 2017;
	pPhone->year = 2017;
}