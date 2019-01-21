#pragma once
class Object
{
public:
	Object();
	Object(const Object& _object);
	Object(Object&& __object);
	Object& operator=(const Object& _object);
	~Object();
};

