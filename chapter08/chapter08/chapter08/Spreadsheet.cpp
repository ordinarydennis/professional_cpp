#include "Spreadsheet.h"

int Spreadsheet::sCounter;

Spreadsheet::Spreadsheet(SpreadsheetApplication& theApp)
	:mTheApp(theApp)
{
	mId = sCounter++;
}


Spreadsheet::~Spreadsheet()
{
}

int Spreadsheet::getId() const
{
	return mId;
}
int Spreadsheet::getCounter() const
{
	return sCounter;
}
int Spreadsheet::getValue() const
{
	return mValue;
}
std::string Spreadsheet::doubleToString(double val)
{
	return "";
}