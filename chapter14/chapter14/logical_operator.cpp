#include <iostream>

bool getbool(bool b)
{
	std::cout << " getbool called " << std::endl;
	return b;
}

struct Boolean
{
private:
	bool value;

public:
	Boolean(bool t_value)
		: value(t_value)
	{
	}

	bool operator&&(const Boolean &right) const
	{
		std::cout << right.value << std::endl;
		return this->value && right.value;
	}

	bool operator||(const Boolean &right) const
	{
		std::cout << right.value << std::endl;
		return this->value || right.value;
	}
};

Boolean getBoolean(bool b)
{
	std::cout << " getBoolean called: " << b << std::endl;
	return Boolean(b);
}

int main()
{
	std::cout << " Testing getbool || expecting 1 output: " << std::endl;
	if (getbool(true) || getbool(false))
	{
	}

	std::cout << " Testing getbool || expecting 2 outputs: " << std::endl;
	if (getbool(false) || getbool(true))
	{
	}

	std::cout << " Testing getbool && expecting 1 outputs: " << std::endl;
	if (getbool(false) && getbool(true))
	{
	}

	std::cout << " Testing getBoolean || expecting 2 outputs: (no shortcircuit) " << std::endl;
	if (getBoolean(true) || getBoolean(false))
	{
	}

	std::cout << " Testing getBoolean && expecting 2 outputs: (no shortcircuit)" << std::endl;
	if (getBoolean(false) && getBoolean(true))
	{
	}
}