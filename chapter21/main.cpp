#include "Grid.h"
#include "MyGrid.h"
#include "Object.h"
#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
using namespace std;

class Mixin1
{
public:
	Mixin1(int i) : mValue(i) {}
	virtual void Mixin1Func() { cout << "Mixin1: " << mValue << endl; }

private:
	int mValue;
};

class Mixin2
{
public:
	Mixin2(int i) : mValue(i) {}
	virtual void Mixin2Func() { cout << "Mixin2: " << mValue << endl; }

private:
	int mValue;
};

template<typename... Mixins>
class MyClass : public Mixins...
{
public:
	MyClass(const Mixins&... mixins) : Mixins(mixins)... {}
};

void templateTest();
void variadicMixinsTest();
void varArgsTest();
void tupleTest();
template<typename T>
void is_integralTest(T test)
{
	if (is_integral<T>::value) {
		cout << "int is integral" << endl;
	}
	else {
		cout << "int is not integral" << endl;
	}

	if (is_class<T>::value) {
		cout << "string is a class" << endl;
	}
	else {
		cout << "string is not a class" << endl;
	}
}
void typeTraitsTest()
{
	int test = 0;
	is_integralTest(test);
	string sTest = "";
	is_integralTest(sTest);
}
int main()
{
	//templateTest();
	//varArgsTest();
	typeTraitsTest();
	return 0;
}
void templateTest()
{
	//Grid<int, vector<int>> myIntVectorGrid;
	//Grid<int, deque<int>> myIntDequeGrid;
	//MyGrid<int, vector<int>> myGrid;
/*
	myIntVectorGrid.setElementAt(3, 4, 5);
	cout << myIntVectorGrid.getElementAt(3, 4) << endl;

	myIntDequeGrid.setElementAt(1, 2, 3);
	cout << myIntDequeGrid.getElementAt(1, 2) << endl;

	Grid<int, vector<int>> grid2(myIntVectorGrid);
	grid2 = myIntVectorGrid;
*/

	//Grid<int, int> test; // WILL NOT COMPILE
	//MyGrid<Object, vector> objectGrid;
	MyGrid<Object, vector<Object>> objectGrid;
	Object o = objectGrid.getElementAt(1, 1); //copy 
	Object o2;
	o2 = o;  // operator = 

	//MyGrid<int, int> intGrid; //compile error
	MyGrid<Object> objectGrid2;
}
void variadicMixinsTest()
{
	MyClass<Mixin1, Mixin2> a(Mixin1(11), Mixin2(22));
	a.Mixin1Func();
	a.Mixin2Func();

	MyClass<Mixin1> b(Mixin1(33));
	b.Mixin1Func();
	//b.Mixin2Func();    // Error: does not compile.
}

void handleValue(int value)
{
	cout << "Integer: " << value << endl;
}
void handleValue(double value)
{
	cout << "Double: " << value << endl;
}
void handleValue(const string& value)
{
	cout << "String: " << value << endl;
}
// First version using pass-by-value
template<typename T>
void processValues(T arg)	// Base case
{
	handleValue(arg);
}

template<typename T1, typename... Tn>
void processValues(T1 arg1, Tn... args)
{
	handleValue(arg1);
	processValues(args...);
}

// Second version using pass-by-rvalue-reference
template<typename T>
void processValuesRValueRefs(T&& arg)
{
	handleValue(std::forward<T>(arg));
}

template<typename T1, typename... Tn>
void processValuesRValueRefs(T1&& arg1, Tn&&... args)
{
	handleValue(std::forward<T1>(arg1));
	processValuesRValueRefs(std::forward<Tn>(args)...);
}

void varArgsTest()
{
	processValues(1, 2, 3.56, "test", 1.1f);
	cout << endl;
	processValuesRValueRefs(1, 2, 3.56, "test", 1.1f);
}
template<int n, typename TupleType>
class TuplePrint
{
public:
	TuplePrint(const TupleType& t)
	{
		TuplePrint<n - 1, TupleType> tp(t);
		cout << get<n - 1>(t) << endl;
	}
};
template<typename TupleType>
class TuplePrint<0, TupleType>
{
public:
	TuplePrint(const TupleType& t)
	{
		
	}
};

void tupleTest()
{
	using MyTuple = tuple<int, string, bool>;
	MyTuple t(10,"Test",true);
	TuplePrint<tuple_size<MyTuple>::value, MyTuple> tp(t);
}
