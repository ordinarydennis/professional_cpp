#include "MemoryDemo.h"

using namespace std;

class Test
{
public:
	Test() {};
	~Test() {};
};


int main()
{
	MemoryDemo* mem = new MemoryDemo();
	delete mem;

	int test_size = sizeof(Test); //size 1 byte
	int a = sizeof(MemoryDemo);
	mem = new MemoryDemo[10];
	delete [] mem;

	mem = new (nothrow) MemoryDemo();
	delete mem;

	mem = new (nothrow) MemoryDemo[10];
	delete [] mem;

	MemoryDemo* memp = new(5) MemoryDemo();
	delete memp;

	return 0;
}
