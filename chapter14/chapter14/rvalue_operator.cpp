#include <iostream>

struct T
{
	T(int v) :a(v) {}


	T(T&& t) { a = t.a; }

	T& operator=(const T& t)
	{
		std::cout << "copy" << std::endl;
		a = t.a;
		return *this;
	}
	T& operator=(T&& t)
	{
		std::cout << "move" << std::endl;
		a = std::move(t.a);
		return *this;
	}

	int a;
};

void foo(const T &t)
{
	T tmp(2);
	std::cout << tmp.a << std::endl;
	tmp = t;
	std::cout << tmp.a << std::endl;
}
void bar(T &&t)
{
	T tmp(2);
	std::cout << tmp.a << std::endl;
	tmp = std::move(t);
	std::cout << tmp.a << std::endl;
}

T ex()
{
	T tmp(2);
	return std::move(tmp);
}

int main(void)
{
	T t1(1);
	std::cout << "foo" << std::endl;
	foo(t1);
	std::cout << "bar" << std::endl;
	bar(T(5));
	ex();
}