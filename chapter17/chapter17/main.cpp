#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

void ex17_1_1();
void ex17_1_1_2();
void ex17_2_6_1();
void ex17_4_2_1();
void ex17_4_2_2();
void ex17_4_2_3();
void ex17_4_3_1();
void ex17_4_3_2();
void ex17_4_3_2_1();
void ex17_4_3_3();
void vectorTest();
void ex17_4_3_5();
void ex17_4_3_6();
void ex17_4_3_7();
void ex17_4_3_8();
int main()
{
	//ex17_4_2_1();
	//ex17_4_2_2();
	//ex17_4_2_3();
	//ex17_4_3_1();
	//ex17_4_3_2();
	//ex17_4_3_2_1();
	//ex17_4_3_3();
	//vectorTest();
	//ex17_4_3_5();
	//ex17_4_3_6();
	//ex17_4_3_7();
	ex17_4_3_8();
	return 0;
}
void ex17_1_1()
{
	int num;
	vector<int> myVector;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		myVector.push_back(num);
	}

	while (true) {
		cout << "Enter a number to lookup (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		auto endIt = myVector.cend();
		auto it = find(myVector.cbegin(), endIt, num);
		if (it == endIt) {
			cout << "Could not find " << num << endl;
		}
		else {
			cout << "Found " << *it << endl;
		}
	}
}
bool perfectScore(int num)
{
	return (num >= 100);
}
void ex17_1_1_2()
{
	int num;

	vector<int> myVector;
	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		myVector.push_back(num);
	}

	auto endIt = myVector.cend();
	auto it = find_if(myVector.cbegin(), endIt, perfectScore);
	//auto it = find_if(myVector.cbegin(), endIt, [](int i){ return i >= 100; }); from c++ 11
	if (it == endIt) {
		cout << "No perfect scores" << endl;
	}
	else {
		cout << "Found a \"perfect\" score of " << *it << endl;
	}

}
void ex17_2_6_1()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int value = 3;
	int cnt = count_if(cbegin(vec), cend(vec), [value](int i) { return i > value; });
	cout << "Found " << cnt << " values > " << value << endl;
}
//04_01_NonModifyingAlgorithms 
void ex17_4_2_1()
{
	// The list of elements to be searched
	vector<int> myVector = { 5, 6,6, 9, 8, 8, 3 };
	auto beginIter = cbegin(myVector);
	auto endIter = cend(myVector);

	// Find the first element that does not satisfy the given lambda expression
	auto it = find_if_not(beginIter, endIter, [](int i) { return i < 8; });
	if (it != endIter) {
		cout << "First element not < 8 is " << *it << endl;
	}

	// Find the min and max elements in the vector
	auto res = minmax_element(beginIter, endIter);
	cout << "min is " << *(res.first) << " and max is " << *(res.second) << endl;

	// Find the min and max elements in the vector
	it = min_element(beginIter, endIter);
	auto it2 = max_element(beginIter, endIter);
	cout << "min is " << *it << " and max is " << *it2 << endl;

	// Find the first pair of matching consecutive elements
	it = adjacent_find(beginIter, endIter);
	if (it != endIter) {
		cout << "Found two consecutive equal elements with value " << *it << endl;
	}

	// Find the first of two values
	vector<int> targets = { 8, 9 };
	it = find_first_of(beginIter, endIter, cbegin(targets), cend(targets));
	if (it != endIter) {
		cout << "Found one of 8 or 9: " << *it << endl;
	}

	// Find the first subsequence
	vector<int> sub = { 8, 3 };
	it = search(beginIter, endIter, cbegin(sub), cend(sub));
	if (it != endIter) {
		cout << "Found subsequence {8,3}" << endl;
	}
	else {
		cout << "Unable to find subsequence {8,3}" << endl;
	}

	// Find the last subsequence (which is the same as the first in this example)
	it2 = find_end(beginIter, endIter, cbegin(sub), cend(sub));
	if (it != it2) {
		cout << "Error: search and find_end found different subsequences "
			<< "even though there is only one match." << endl;
	}

	// Find the first subsequence of two consecutive 8s
	it = search_n(beginIter, endIter, 2, 8);
	if (it != endIter) {
		cout << "Found two consecutive 8s" << endl;
	}
	else {
		cout << "Unable to find two consecutive 8s" << endl;
	}
}
template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}
void ex17_4_2_2()
{
	vector<int> myVector;
	list<int> myList;

	cout << "Populate the vector:" << endl;
	populateContainer(myVector);
	cout << "Populate the list:" << endl;
	populateContainer(myList);

	// Compare the two containers
	if (myList.size() == myVector.size() &&
		equal(cbegin(myVector), cend(myVector), cbegin(myList))) {
		cout << "The two containers have equal elements" << endl;
	}
	else {
		if (myList.size() < myVector.size()) {
			cout << "Sorry, the list is not long enough." << endl;
			return;
		}
		else {
			// If the containers were not equal, find out why not
			auto miss = mismatch(cbegin(myVector), cend(myVector), cbegin(myList));
			//template<class InputIt1, class InputIt2>
			//std::pair<InputIt1, InputIt2>
			//	mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2)
			//{
			//	while (first1 != last1 && *first1 == *first2) {
			//		++first1, ++first2;
			//	}
			//	return std::make_pair(first1, first2);
			//}
			cout << "The following initial elements are the same in the vector and the list:" << endl;
			for (auto i = cbegin(myVector); i != miss.first; ++i) {
				cout << *i << '\t';
			}
			cout << endl;
		}
	}

	// C++14: equal() and mismatch() accepting four iterators
	if (equal(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		cout << "The two containers have equal elements" << endl;
	}
	else {
		// If the containers were not equal, find out why not
		auto miss = mismatch(cbegin(myVector), cend(myVector),
			cbegin(myList), cend(myList));
		//template<class InputIt1, class InputIt2>
		//std::pair<InputIt1, InputIt2>
		//	mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
		//{
		//	while (first1 != last1 && first2 != last2 && *first1 == *first2) {
		//		++first1, ++first2;
		//	}
		//	return std::make_pair(first1, first2);
		//}
		cout << "The following initial elements are the same in "
			<< "the vector and the list:" << endl;
		for (auto i = cbegin(myVector); i != miss.first; ++i) {
			cout << *i << '\t';
		}
		cout << endl;
	}

	// Now order them
	//refer to https://www.geeksforgeeks.org/lexicographical_compare-in-cpp/
	if (lexicographical_compare(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		cout << "The vector is lexicographically first." << endl;
	}
	else {
		cout << "The list is lexicographically first." << endl;
	}
}
void ex17_4_2_3()
{
	//refer to http://hochulshin.com/cpp-stl-algorithm-all-of-any-of-none-of/
	// all_of()
	vector<int> vec2 = { 1, 1, 1, 1 };
	if (all_of(cbegin(vec2), cend(vec2), [](int i) { return i == 1; })) {
		cout << "All elements are == 1" << endl;
	}
	else {
		cout << "Not all elements are == 1" << endl;
	}

	// any_of()
	//if one thing succeed, It is success
	vector<int> vec3 = { 0, 0, 1, 0 };
	if (any_of(cbegin(vec3), cend(vec3), [](int i) { return i == 1; })) {
		cout << "At least one element == 1" << endl;
	}
	else {
		cout << "No elements are == 1" << endl;
	}

	// none_of()
	//If one thing fails, it is a failure.
	vector<int> vec4 = { 0, 1, 1, 1 };
	if (none_of(cbegin(vec4), cend(vec4), [](int i) { return i == 1; })) {
		cout << "All elements are != 1" << endl;
	}
	else {
		cout << "Some elements are == 1" << endl;
	}

}
void ex17_4_3_1()
{
	vector<int> vec1;
	cout << "Vector1:" << endl;
	populateContainer(vec1);
	cout << "Vector2:" << endl;
	vector<int> vec2;
	populateContainer(vec2);

	if (vec2.size() < vec1.size())
	{
		cout << "Vector2 should be at least the same size as vector1." << endl;
		return ;
	}

	// Create a lambda to print a container
	auto printContainer = [](const auto& container) {
		for (auto& i : container) { cout << i << " "; }
		cout << endl;
	};

	cout << "Vector1: "; printContainer(vec1);
	cout << "Vector2: "; printContainer(vec2);

	transform(begin(vec1), end(vec1), begin(vec2), begin(vec1),
		[](int a, int b) { return a + b; });

	//template<class _InIt1,
	//	class _InIt2,
	//	class _OutIt,
	//	class _Fn> inline
	//	_OutIt transform(const _InIt1 _First1, const _InIt1 _Last1,
	//		const _InIt2 _First2, _OutIt _Dest, _Fn _Func)

	cout << "Vector1: "; printContainer(vec1);
	cout << "Vector2: "; printContainer(vec2);
	return;
}
void ex17_4_3_2()
{
	vector<int> vec1, vec2;
	populateContainer(vec1);
	vec2.resize(vec1.size());
	//copy(cbegin(vec1), cend(vec1), begin(vec2));
	copy_backward(cbegin(vec1), cend(vec1), end(vec2));
	for (const auto& i : vec2) { cout << i << " "; }

}
void ex17_4_3_2_1()
{
	vector<int> vec1, vec2;

	populateContainer(vec1);

	vec2.resize(vec1.size());
	auto endIterator = copy_if(cbegin(vec1), cend(vec1),
		begin(vec2), [](int i) { return i % 2 == 0; });
	vec2.erase(endIterator, end(vec2));
	for (const auto& i : vec2) { cout << i << " "; }

	cout << endl;
}
class MyClass
{
public:
	MyClass() = default;
	MyClass(const MyClass& src) = default;
	MyClass(const string& str, const int _num) : mStr(str), num(_num) {}
	MyClass(const string& str, const int _num, MyClass* p) : mStr(str), num(_num), pmc(p){}

	// Move assignment operator
	MyClass& operator=(MyClass&& rhs) noexcept {
		if (this == &rhs)
			return *this;
		mStr = std::move(rhs.mStr);
		pmc = std::move(rhs.pmc);
		rhs.pmc = nullptr;
		num = 1;
		cout << "Move operator= (mStr=" << mStr << ")" << endl;
		return *this;
	}

	string getString() const { return mStr; }

private:
	string mStr;
	int num;
	MyClass* pmc = nullptr;
};
void ex17_4_3_3()
{
	vector<MyClass> vecSrc{ MyClass("a",1, new MyClass("aa",1)), MyClass("b",2,new MyClass("bb",2)), MyClass("c",3,new MyClass("cc",3)) };
	vector<MyClass> vecDst(vecSrc.size());
	move(begin(vecSrc), end(vecSrc), begin(vecDst));
	for (const auto& c : vecDst) { cout << c.getString() << " "; }
	cout << endl;
	for (const auto& c : vecSrc) { cout << c.getString() << " "; }
}
class TestClass
{
public:
	TestClass() { cout << "TestClass()" << endl; };
	TestClass(int _num) :num(_num) { cout << "TestClass(int _num) _num is " << _num << endl; };
	TestClass(const TestClass& _rhs) :num(_rhs.num) { cout << "TestClass(const TestClass& _rhs) num: " << _rhs.num << endl; };
	int getNum() const { return num; };

private:
	int num = 0;
};
void vectorTest()
{
	vector<TestClass> test;

	cout << "capacity(): " << test.capacity() << endl;

	//test.resize(10);

	test.push_back(TestClass(1));
	cout << "capacity(): " << test.capacity() << endl;
	test.push_back(TestClass(2));
	cout << "capacity(): " << test.capacity() << endl;
	test.push_back(TestClass(3));
	cout << "capacity(): " << test.capacity() << endl;
	test.push_back(TestClass(4));
	cout << "capacity(): " << test.capacity() << endl;
	test.push_back(TestClass(5));
	cout << "capacity(): " << test.capacity() << endl;

	for (const auto& a : test) {
		cout << a.getNum() << " ";
	}cout << endl;

	test.erase(cbegin(test) + 2);

	for (const auto& a : test) {
		cout << a.getNum() << " ";
	}cout << endl;
	cout << "capacity(): " << test.capacity() << endl;
}
void removeEmptyStrings(vector<string>& strings)
{
	for (const auto& e : strings) { cout << e << ", "; }
	cout << endl;
	auto it = remove_if(begin(strings), end(strings),
		[](const string& str) { return str.empty(); });
	for (const auto& e : strings) { cout << e << ", "; }
	cout << endl;
	// erase the removed elements
	strings.erase(it, end(strings));
}
void removeEmptyStrings2(vector<int>& ints)
{
	for (const auto& e : ints) { cout << e << ", "; }
	cout <<endl;
	auto it = remove(begin(ints), end(ints), 30);
	for (const auto& e : ints) { cout << e << ", "; }
	cout << endl;
	// erase the removed elements
	ints.erase(it, end(ints));
}
void ex17_4_3_5()
{
	vector<string> myVector = { "", "one", "", "two", "three", "four" };
	vector<int> intList = { 1,30,100,2,30,200,3,30,300 };
	//for (auto& str : myVector) { cout << "\"" << str << "\"  "; }
	cout << endl;
	removeEmptyStrings(myVector);
	removeEmptyStrings2(intList);
	//for (auto& str : myVector) { cout << "\"" << str << "\"  "; }
	cout << endl;
}
void ex17_4_3_6()
{

	cout << "Illustrating the generic unique algorithm." << endl;
	const int N = 11;
	int array1[N] = { 1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8 };
	vector<int> vector1;
	for (int i = 0; i < N; ++i)
		vector1.push_back(array1[i]);

	sort(begin(vector1),end(vector1));
	vector<int>::iterator new_end;
	new_end = unique(vector1.begin(), vector1.end());
	cout << "vector1.size()" << vector1.size() << endl;
	// unique elements [vector1.begin(), new_end)
	// erase remaining elements from new_end itor to vector1.end()
	vector1.erase(new_end, vector1.end());
	cout << endl;


	//refer to http://laitdei.tistory.com/entry/STL-unique [力明焙狼 家家茄 窍风老扁]
}
void ex17_4_3_7()
{
	std::vector<int> myvector;
	std::vector<int> outputvector;

	// set some values:
	for (int i = 1; i < 10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

	//reverse(myvector.begin(), myvector.end());    // 9 8 7 6 5 4 3 2 1
	outputvector.resize(myvector.size());
	reverse_copy(myvector.begin(), myvector.end(), outputvector.begin());

	// print out content:
	for (const auto& it : myvector) {
		std::cout << ' ' << it;
	}
	std::cout << '\n';
	for (const auto& it : outputvector) {
		std::cout << ' ' << it;
	}
	std::cout << '\n';
}
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
void ex17_4_3_8()
{
	//refer to 
	//https://en.cppreference.com/w/cpp/algorithm/random_shuffle
	//http://torbjorn.tistory.com/65
	//https://meetingcpp.com/blog/items/stdrandom_shuffle-is-deprecated.html
	std::vector<int> myvector;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	for (int i = 1; i < 10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
	
	std::shuffle(myvector.begin(), myvector.end(), e);
	for (const auto& e : myvector) {
		cout <<  e << " ";
	}cout << endl;
}