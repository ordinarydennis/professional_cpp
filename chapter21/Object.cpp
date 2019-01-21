#include "Object.h"
#include <iostream>
using std::cout;
using std::endl;

Object::Object()
{
	cout << "Object()" << endl;
}

Object::Object(const Object& _object)
{
	cout << "Object::Object(const Object& _object)" << endl;
}
Object::Object(Object&& __object)
{
	cout << "Object::Object(Object&& __object)" << endl;
}
Object& Object::operator=(const Object& _object)
{
	cout << "Object::operator=(const Object& _object)" << endl;

	return *this;
}
Object::~Object()
{
	cout << "~Object()" << endl;

}
