
//LinkedIn : Hanae Messari Khali

#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"
using namespace std;

template <class T>

int ReadPositiveNumber(string Message)
{
	cout << Message;
	return clsInputValidate<int>::ReadPositiveNumber(); //1234
}

int ReverseNumber(int Number)
{
	return clsUtil<int>::ReverseNumber(Number);
}

int main()
{
	int Number = ReadPositiveNumber<int>("\nPlease Enter a Positive Number?");
	cout << "Reversed Number is : " << ReverseNumber(Number) << endl;

	system("pause>0");
	return 0;

}

