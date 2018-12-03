#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;
int main()
{
	//14.1.3.3
	SpreadsheetCell myCell, anotherCell, aThirdCell;
	aThirdCell.set("aThirdCell");
	//It is possible because return type is l value;
	(myCell = anotherCell) = aThirdCell;
	cout << myCell.getString() << endl;
	//myCell.set("aaa");
	//cout << aThirdCell.getString() << endl;



	SpreadsheetCell a(4);
	a++;


	return 0;
}

// rel_ops example:
//#include <iostream>     // std::cout, std::boolalpha
//#include <utility>      // std::rel_ops
//#include <cmath>        // std::sqrt
//
//class vector2d {
//public:
//	double x, y;
//	vector2d(double px, double py) : x(px), y(py) {}
//	double length() const { return std::sqrt(x*x + y * y); }
//	bool operator==(const vector2d& rhs) const { return length() == rhs.length(); }
//	bool operator< (const vector2d& rhs) const { return length() < rhs.length(); }
//};
//
//int main() {
//	using namespace std::rel_ops;
//	vector2d a(10, 10);	// length=14.14
//	vector2d b(15, 5);	// length=15.81
//	std::cout << std::boolalpha;
//	std::cout << "(a<b) is " << (a < b) << '\n';
//	std::cout << "(a>b) is " << (a > b) << '\n';
//	return 0;
//}


