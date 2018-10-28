#include <iostream>
#include <memory>
using std::cout;
using std::endl;

//자동 함수 리턴 타입
auto auto_return_type_func()
{
	//리턴 타입을 auto로 해두면 return문에 표현식이
	//어떤 타입을 가지느냐에 따라 리턴 타입이 자동으로 결정된다.
	//return문이 여러개일 경우 모든 리턴문의 표현식이 같은 타입이어야 한다.
	double a = 10;
	double b = 20;
	auto ret = a + b;
	return ret;
}

int main()
{
	//함수의 리턴 타입이 복잡할 경우 리턴값을 변수에 대입하려면
	//일일이 타이핑을 해야 하지만 auto키워드를 사용하면 
	//컴파일 타임에 타입 결정을 맡길 수 있다. 
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

	//배열을 지원하지 않는다.
	auto test_shared_ptr_array = std::make_shared<int>(5);
	cout << *test_shared_ptr_array << endl;
}


