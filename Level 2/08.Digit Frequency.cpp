
#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"

using namespace std;

int main()
{
	
	int Number = clsInputValidate<int>::ReadPositiveNumber("\nPlease Enter A Number : ");
	short DigitToCheck = clsInputValidate<short>::ReadPositiveNumber("Please Enter One Digit To Check : ");

	cout << "\nDigit " << DigitToCheck << " Frequency is " 
		 << clsUtil<short>::CountDigitFrequency(Number, DigitToCheck) << " Time(s).\n";

	system("pause>0");
	return 0;
}