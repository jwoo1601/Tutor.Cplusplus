/*
	C -> 절차 지향 언어 (Procedural Language)
	: 동작들의 나열로 설명
	엔진을 점화한다
	엑셀을 밟는다
	브레이크를 밟는데

	C++ -> 객체 지향 언어 (Object Oriented Language)
	: 자동차에는 바퀴가 있다
		바퀴는 구른다
	  자동차에는 핸들이 있다
		핸들을 돌리면 방향을 바꾼다
	  자동차에는 브레이크가 있다
		브레이크는 밟으면 멈춘다

	class -> classification : 분류
	e.g. 바퀴
		 엔진
		 핸들
		 와이퍼
		 유리창
		 디스플레이
*/

// class <identifier>
// {
//		멤버 함수 (instance function = member functions = method)
//		멤버 변수 (member variable = instance variable = field)
// };

class Test
{
	int a;

	void func1();
	int func2();
	short func3();
};

// 클래스의 멤버함수는 해당 클래스의 멤버 변수에 접근을 할 수있음

void Test::func1()
{
	a = 3;
}

// <return-type> <identifier>(<parameter>);    -> 이 함수의 signature or 머리 
// {
// }

// opr1::opr2 -> scope resolution operator  -> opr2 가 opr1 에 속해있다는 소속을 밝힘

// function -> 동작을 정의
// 손을 흔든다
// 밥을 먹는다
// 화장실에 간다

//variable을 만들어라
// a에다 3을 대입해라
// a 가 4보다 크면 ~~해라

// function 의 input: parameter (매개변수) or argument (인수)
// function 의 output: return value (리턴값)
// <return-type> <identifier>(<parameter1-type> <param1-name>, <param2-type> <param2-name>...)
// {
//		코드
// }

// 두 파라미터를 더해서 더한값을 리턴하는 function
int add(int a, int b)
{
	return a + b;
}

// 값을 내보내기: return expression;

// function 을 사용하는 법 (function call or 함수 호출)
// call __ function
// <identifier>(<parameter>);

int main()
{
	int c = add(5, 3);
	add(c - 5, 1);
}

// 아무곳에도 소속되있지 않은 범위 -> global scope
// function 안에 소속되면 -> function scope / local scope
// class 안에 소속되면 -> class scope
// code block 안에 소속되면 -> block scope