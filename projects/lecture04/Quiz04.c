// Q1. int 와 double 타입의 두 parameter 를 받고, float 을 리턴하는 function 을 declare (해당 function 의 이름은 func1):


// Q2. 두 개의 int parameter 를 받고 해당 두 parameter 의 차이를 리턴하는 function 을 define:


// Q3.
void question03(int a)
{
	{
		int a = 3;

		for (int i = 0; i < 10; i++)
		{
			a += i;
		}

		printf("%d", a); // (1) 이때 출력되는 a의 값은?
	}

	printf("%d", a); // (2) 이때 출력되는 a의 값은?
}

question03(10);

// Answers
// Q3-(1):
// Q3-(2):


// Q4. 
void question04()
{
	float c = 10.5f;
	float* ptr = &c;
	float d = 5.5f, f = 6.5f;
	float* ptr2 = &d;
	ptr2 = &f;

	float value = *ptr + *ptr2;
	// 이떄 value 의 값은?
	// Answer: 
}


// Q5.
void question05_1(float f, float *g)
{
	f = f + *g;
	g = &f;
	*g = 3.4f;
}

void question05_2()
{
	float a = 2.3f;
	question05_1(5.3f, &a);
	// (1) 위 줄의 코드가 실행된 이후 a 의 값은?
	// Answer:

	// (2) 위 함수의 코드가 다 실행되었을 때, question05_1 의 f의 값은?
	// Answer:

	// (3) 위 함수의 코드가 다 실행되었을 때, g 가 가리키는 variable 의 이름은?
	// Answer:
}