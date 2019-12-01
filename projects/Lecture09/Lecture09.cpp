/*
	1. Inheritance (상속)
	: 클래스 사이의 관계의 일종으로, 두 클래스 사이의 관계에서 한 클래스가 다른 클래스의 특성(traits/characteristics)을 물려받는 관계를 뜻함.
	 이 때, 특성이란 클래스의 각종 멤버 (variables/functions) 들을 뜻함.

	 - 의의: Object Oriented Programming 을 구현을 할 떄, 이 Object 의 뼈대가 되는 Class 들 사이에 특수한 관계를 정의해
			어떤 클래스가 다른 클래스의 인터페이스 (interface) 를 물려받게 함으로써 중복되는 특성의 경우 재정의를 할 필요가 없게 되어
			결과적으로 코드의 재사용성 (reusability) 을 획기적으로 높임.

	(1) Base and derived classes
	: 어떤 클래스가 다른 클래스를 상속받게 (inherted) 되었을 떄, 상속을 받는 클래스를 derived (or child/sub) class, 상속을 하는 클래스를 base (or parent/super) class 라고 지칭함.

	(2) Member access level
	: derived class 에서는 base class 의 private 멤버를 제외한 public 및 protected 멤버에 접근이 자유로움.

	(3) Inherited members
	: derived class 는 base class 의 기능들을 흉내내기 위해 base class 의 모든 멤버 (private, protected, public) 를 상속받음.
	 즉, 상속을 받는 시점부터 base class 의 모든 멤버가 derived class 에도 존재함. (다만 inheritance type 에 따라 derived class 에서 접근이 불가능 할 수도 있음.)

	(4) Types of inheritanace
	: derived class 에서 base class 를 상속받을 때, public, protected 혹은 private inheritance 에 따라 상속받는 멤버들의 access level 이 달라지게 됨.
		- public inheritance: base class 이름 앞에 public 을 붙여야 하며, base class 의 모든 멤버들의 access level 을 base class 에 정의된 access level 을 따름.
		- protected inheritance: base class 이름 앞에 protected 를 붙여야 하며, private 을 제외한 모든 멤버들의 access level 을 protected 로 변경함.
		- private inheritance (default): base class 의 이름 앞에 private 을 붙이거나 붙이지 않을 경우 기본으로 설정되며,
										base class 의 모든 멤버들의 access level 을 private 으로 변경함.


*/

/*
	2. Staic (Class) Members
	: instance variables 혹은 member functions 와 같이 어떤 "오브젝트" 혹은 "인스턴스" 에 종속되는 것이 아닌, "클래스" 자체에 종속이 되어
	 해당 클래스의 오브젝트들 사이에서 "공유" 되는 멤버들을 말함.

	(1) Static (class) variables
	: 

	(2) Static (class) functions
	:

	(3) Context of current object
	:
*/