
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

int main()
{
	int Number = ReadPositiveNumber<int>("\nPlease Enter a Positive Number?");
	cout << "Reversed Number is : " << clsUtil<int>::ReverseNumber(Number) << endl;

	system("pause>0");
	return 0;

}

