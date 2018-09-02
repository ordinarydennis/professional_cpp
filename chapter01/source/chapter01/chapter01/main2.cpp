#include <iostream>
#include <memory>
using std::cout;
using std::endl;

//�ڵ� �Լ� ���� Ÿ��
auto auto_return_type_func()
{
	//���� Ÿ���� auto�� �صθ� return���� ǥ������
	//� Ÿ���� �������Ŀ� ���� ���� Ÿ���� �ڵ����� �����ȴ�.
	//return���� �������� ��� ��� ���Ϲ��� ǥ������ ���� Ÿ���̾�� �Ѵ�.
	double a = 10;
	double b = 20;
	auto ret = a + b;
	return ret;
}

int main()
{
	//�Լ��� ���� Ÿ���� ������ ��� ���ϰ��� ������ �����Ϸ���
	//������ Ÿ������ �ؾ� ������ autoŰ���带 ����ϸ� 
	//������ Ÿ�ӿ� Ÿ�� ������ �ñ� �� �ִ�. 
	auto ret = auto_return_type_func();

	auto test_unique_ptr = std::make_unique<int>(10);
	cout << test_unique_ptr.get() << endl;
	test_unique_ptr.reset();
	//After that is done, std::unique_ptr<>::get() will return nullptr
	if (nullptr == test_unique_ptr.get()) {
		cout << test_unique_ptr.get() << endl;
	}

	auto test_unique_ptr_array = std::make_unique<int[]>(5);
	for(int i = 0; i< 5; i++){
		cout << test_unique_ptr_array[i] << ",";
	}
	cout << endl;

	//�迭�� �������� �ʴ´�.
	auto test_shared_ptr_array = std::make_shared<int>(5);
	cout << *test_shared_ptr_array << endl;
}


