#pragma once
#include <string>

class SpreadsheetApplication;
class Spreadsheet
{
public:
	Spreadsheet(SpreadsheetApplication& theApp);
	//have to match the type.
	//Spreadsheet(const SpreadsheetApplication& theApp);
	//const SpreadsheetApplication& mTheApp;
	~Spreadsheet();

	int getId() const;
	int getCounter() const;

	int getValue() const;

private:
	static int sCounter;
	int mId;
	int mValue;

	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;

	//Unless mTheApp initialize, occur error.
	SpreadsheetApplication& mTheApp;

	//because definition is needed, occur error.
	//SpreadsheetApplication mTheApp;

	//Pointer variables do not occur an error.
	//SpreadsheetApplication* mTheApp;

	//
	static std::string doubleToString(double val);
};

