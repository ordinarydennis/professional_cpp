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

//�������� �⺻������ int Ÿ�԰� ���� ������ enum class������
//�ٸ� Ÿ������ �ٲܼ��� �ִ�. 
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

	// std::cerr �� ����ص� �Ȱ��� �ܼ�â�� ��� �ȴ�. 
	std::cerr << "Hello world" << std::endl;

	//std �ȿ� ���� �ѹ� ���� 
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

	//���� Ÿ��
	//������ �� ��� �̸��� �ƴ�, ���� ��ü�� ���� �����ϰ� �ֱ� ������ ������ �߻��Ѵ�.
	//PieceType pt_test = 0;
	//���Ƿ� ������ ���� �� ����.
	//PieceType pt_test2 = PieceType::PieceTypeKing + 1;
	
	//���� Ÿ���� ������� ������ �Ϲ� ������ ������ ������ �ż� �߸��� ����� ���� �� �ִ�.
	const int PieceTypeKing = 0;
	int myType = PieceTypeKing + 1;
	if (PieceTypeKing == d) {
		cout << "PieceTypeKing" << endl;
	}
	else {
		cout << "Not PieceTypeKing" << endl;
	}

	//Ÿ���� �ƴ� �ܼ� �������� ���� Ÿ�� ����� �ޱ� ������ ���� �ٸ� �������� �Ǵ� �� �� ����.
	if (PieceTypeKing == PieceType2King) {
		cout << "Same PieceTypeKing and PieceType2King" << endl;
	}
	else {
		cout << "different PieceTypeKing and PieceType2King" << endl;
	}

	//enum class�� ������ �ϴ�. �׸��� �ݵ�� class �̸����� ������ ������ �ؾ� ����� �� �ִ�. 
	//PieceTypeClass ptcTest = PieceTypeClass::PieceTypeClassKing;
	//if (PieceTypeClass::PieceTypeClassKing == PieceType2King) {

	//}

	////switch ��
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

	//�迭
	int array_test[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		cout << array_test[i] << endl;
	}
	int array_test2[3] = { 2, };
	cout << "test2 array for ";
	//�� ��Ҹ� ���� ���� �ʱ����� ������ ������ �̿��ߴ�.
	for (auto& s : array_test2)
		std::cout << s << ' ';
	cout << endl;
	//�迭�� ũ�� ��������
	std::cout << "Length of array = " << (sizeof(array_test2) / sizeof(*array_test2)) << std::endl;
	using std::array;
	std::array<int, 3> array_test3 = { 1,2,3 };
	cout << array_test3[1] << endl;

	using std::array;
	std::array<int, 3> array_test4 = { 0 };
	cout << array_test4[2] << endl;
	//c�迭�� ���� ũ�⸦ �׻� ��Ȯ�ϰ� �� �� �ִ�.
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
	//�Լ��� �����ϸ� ������ ���� �Լ��� �̸��� ��� �ִ� ������
	//�ڵ����� �Լ��� ���������� ���� �ȴ�. 
	//static const char __func__[] = "addNumber";
	static const char func_name[] = "addNumber";
	using std::cout;
	using std::endl;
	cout << __func__ << endl;
	return num1 + num2;

	func(10);
}
//c++11���ʹ� ���� Ÿ���� �Լ� ���� �ڿ� ������� ���ο� �Լ� ���� ������ 
//�����ϰ� �ִ�. ���뿡 ��� ����� ���� ������ ���ø� �Լ������� �ſ� �����ϴ�.
auto func(int i) -> int
{
	return i + 2;
}