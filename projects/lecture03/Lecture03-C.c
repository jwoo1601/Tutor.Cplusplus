// 1. if-else if-else statement
// expression 을 검사 -> true or false 로 평가될 수 있는 식
// int a = 3;
// a -> expression (0: false, 0이 아닌 값은 true)

// Logical operator (논리 연산자) (operation 즉 연산식의 결과가 true 나 false)
// opr1 == opr2 (상등 비교): opr1 이 opr2 와 같은지 (같으면 true, 다르면 false)
// opr1 != opr2 : opr1이 opr2와 다른지 (다르면 ture, 같으면 false)
// opr1 > opr2 : opr1 이 opr2보다 큰지 (크면 true, 크지 않으면 => 작거나 같으면 false)
// opr1 < opr2 : opr1 이 opr2보다 작은지 (작으면 true, 크거나 같으면 false)
// opr1 >= opr2 : opr1 이 opr2보다 크거나 같은지 (크거나 같으면 true, 작으면 false)
// opr1 <= opr2 : opr1 이 opr2보다 작거나 같은지 (작거나 같으면 true, 크면 false)
// opr1 && opr2 : opr1 과 opr2가 둘다 true 일때만 true 아니면 나머지 다 false
// e.g. a > 3 && a < 5
// opr1 || opr2 : opr1 과 opr2 둘중에 하나라도 true 면 true 즉 false 인 경우는 둘다 false 경우
// e.g. a > 3 || a < 5
// !opr : opr의 값을 뒤집기 (opr이 true면 false로, opr이 false면 true)
// !(a > 3) : a 가 3보다 크지 않다 즉, a 가 3보다 작거나 같다
// !a = false로 평가 (a가 1일때) (a의 값을 변경하진 않음)

// if statement
// if (expression)
// {
//		...
// }

// e.g. if (a > 5)  if (!a) -> !0 -> !false -> true
//		{
//			a = 3;
//		}

// if (expression)
//	{
//		...
//	}
// else
// {
//		...
// }

// if (expression)  (조건이 여러개)
// {
//		...
// }
// else if (expression)
// {
//		...
// }
// ...
// else
// {
//		...
// }

// switch ~ case statement (조건은 하나, 다만 그 조건의 값이 여러개일때)
/*
	switch (expression)  // expression 의 평가값이 정수여야만 함 -> true/false, int, short, char, long
	{
		case <value1>:
		...
		break;

		case <value2>:
		...
		break;
		
		...

		default:
		...
		break;
	}
*/

// for 문은 정해진 횟수만큼 반복할 때
// for (<init>;expression;증감문) // 증감문
// {
//		반복할 코드
// }

// for (int i =0; i < size; i++)
// for (int i =1; i <= size; i++)
// for (int i =5; i > 0; i--)
// for (int i =4; i >=0; i--)
// 전부다 실행횟수: 5번

// while 문은 조건을 만족하는 동안 반복할 때
// while (expression)     -> expression 이 true 일 경우에 반복
// {
//		반복할코드
// }

// a = 0;
// while (a < 5)
// {
//		a = a + 1;
// }