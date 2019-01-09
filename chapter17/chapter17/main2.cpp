#include <iostream>
#include <vector>
using namespace std;
class Test
{
public:
	Test(int _a)
	{
		printf("Test(%d) \n", _a);
		a = _a;
	}
	Test(const Test& t)
	{
		a = t.a;
		printf("Test(const Test& t) -> %d\n", t.a);
		//cout<<"Test(const Test& t) -> "<<t.a<<endl;
	}
private:
	int a;
};
int main()
{
	vector<Test> v_t;
	v_t.reserve(4);
	v_t.push_back(Test(1)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(2)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(3)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(4)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(5)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(6)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(7)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(8)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(9)); cout << "capacity: " << v_t.capacity() << endl;
	v_t.push_back(Test(10)); cout << "capacity: " << v_t.capacity() << endl;
	//gcc 메모리 확장 정책은 2배 msvc는 1.5배
	return 0;
}