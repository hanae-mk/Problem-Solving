

#include <iostream>

using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;
	cout << "Please enter a number?\n";
	cin >> Number;

	return Number;

}

enNumberType CheckNumberType(int Number)
{
	int Result = Number % 2;

	if (Result == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;

}

void PrintNumberType(enNumberType NumberType)
{


	if (NumberType == enNumberType::Even)
	{
		cout << "Number is Even\n";
	}
	else if (NumberType == enNumberType::Odd)
	{
		cout << "Number is Odd\n";
	}
}

int main()
{

	PrintNumberType(CheckNumberType(ReadNumber()));

	return 0;

}