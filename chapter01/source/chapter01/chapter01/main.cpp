#include <iostream>
#include <array>

enum PieceType {
	PieceTypeKing = 0,
	PieceTypeQueen,
	PieceTypeRook = 10,
	PieceTypePawn
};
enum PieceType2 {
	PieceType2King = 0,
	PieceType2Queen,
	PieceType2Rook = 10,
	PieceType2Pawn
};
enum class PieceTypeClass{
	PieceTypeClassKing = 0,
	PieceTypeClassQueen,
	PieceTypeClassRook = 10,
	PieceTypeClassPawn
};

//열거형은 기본적으로 int 타입과 연계 되지만 enum class에서는
//다른 타입으로 바꿀수도 있다. 
enum class PieceTypeClassByLong : long {
	PieceTypeClassKing = 0,
	PieceTypeClassQueen,
	PieceTypeClassRook = 10,
	PieceTypeClassPawn
};

int addNumber(int num1, int num2);
auto func(int i) -> int;

int main()
{

	// std::cerr 를 사용해도 똑같이 콘솔창에 출력 된다. 
	std::cerr << "Hello world" << std::endl;

	//std 안에 구조 한번 보기 
	//int a;
	//std::cout << a << std::endl;
	std::string s;
	std::cout << s.size() << std::endl;

	using std::cout;
	using std::endl;
	long double ld = 10;
	cout << sizeof(ld) << endl;
	double d = 10;
	cout << sizeof(d) << endl;

	//열거 타입
	//정해진 값 목록 이름이 아닌, 정수 자체를 직접 대입하고 있기 때문에 에러가 발생한다.
	//PieceType pt_test = 0;
	//임의로 정수를 더할 수 없다.
	//PieceType pt_test2 = PieceType::PieceTypeKing + 1;
	
	//열거 타입을 사용하지 않으면 일반 정수형 변수와 연산이 돼서 잘못된 결과를 얻을 수 있다.
	const int PieceTypeKing = 0;
	int myType = PieceTypeKing + 1;
	if (PieceTypeKing == d) {
		cout << "PieceTypeKing" << endl;
	}
	else {
		cout << "Not PieceTypeKing" << endl;
	}

	//타입이 아닌 단순 열거형은 정수 타입 취급을 받기 때문에 서로 다른 열거형을 판단 할 수 없다.
	if (PieceTypeKing == PieceType2King) {
		cout << "Same PieceTypeKing and PieceType2King" << endl;
	}
	else {
		cout << "different PieceTypeKing and PieceType2King" << endl;
	}

	//enum class는 세이프 하다. 그리고 반드시 class 이름으로 스코프 설정을 해야 사용할 수 있다. 
	//PieceTypeClass ptcTest = PieceTypeClass::PieceTypeClassKing;
	//if (PieceTypeClass::PieceTypeClassKing == PieceType2King) {

	//}

	////switch 문
	//int switch_test = 0;
	//switch (switch_test) {
	//case 0:
	//case '1':
	//case 2:
	//	break;
	//case "c":
	//	break;
	//case 'asdfe':
	//	break;
	//case 'asdf':
	//	break;
	//default:
	//	//error
	//}

	//배열
	int array_test[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		cout << array_test[i] << endl;
	}
	int array_test2[3] = { 2, };
	cout << "test2 array for ";
	//각 요소를 복제 하지 않기위해 참조형 변수를 이용했다.
	for (auto& s : array_test2)
		std::cout << s << ' ';
	cout << endl;
	//배열의 크기 가져오기
	std::cout << "Length of array = " << (sizeof(array_test2) / sizeof(*array_test2)) << std::endl;
	using std::array;
	std::array<int, 3> array_test3 = { 1,2,3 };
	cout << array_test3[1] << endl;

	using std::array;
	std::array<int, 3> array_test4 = { 0 };
	cout << array_test4[2] << endl;
	//c배열에 비해 크기를 항상 정확하게 알 수 있다.
	cout << "array_test2 size: "<<array_test4.size() << endl;

	// ranged for loop is supported
	for (auto& s : array_test3)
		std::cout << s << ' ';
	cout << endl;
	addNumber(1, 2);

	return 0;
}

int addNumber(int num1, int num2)
{
	//함수를 정의하면 다음과 같은 함수의 이름을 담고 있는 변수가
	//자동으로 함수의 지역변수로 정의 된다. 
	//static const char __func__[] = "addNumber";
	static const char func_name[] = "addNumber";
	using std::cout;
	using std::endl;
	cout << __func__ << endl;
	return num1 + num2;

	func(10);
}
//c++11부터는 리턴 타입이 함수 선언문 뒤에 따라오는 새로운 함수 정의 문법을 
//도입하고 있다. 보통에 경우 사용할 일이 없지만 템플릿 함수에서는 매우 유용하다.
auto func(int i) -> int
{
	return i + 2;
}