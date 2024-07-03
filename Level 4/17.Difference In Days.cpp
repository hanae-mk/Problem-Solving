
#include <iostream>
#include "clsDate.h"
#include "clsInputValidate.h"

using namespace std;

clsDate ReadFullDate()
{
	clsDate Date;
	bool IsInvalidDate = false;

	do
	{
		if (IsInvalidDate)
		{
			cout << "\nInvalid Date, Enter a Valid Date.\n";
		}

		cout << "\nPlease Enter Day?";
		Date.Day = clsInputValidate<short>::ReadNumberBetween(1, 31);

		cout << "Please Enter Month?";
		Date.Month = clsInputValidate<short>::ReadNumberBetween(1, 12);

		cout << "Please Enter Year?";
		Date.Year = clsInputValidate<short>::ReadNumber();

	} while(IsInvalidDate = !clsDate::IsValidDate(Date));

	return Date;

}

int main()
{
	clsDate Date1 = ReadFullDate();
	clsDate Date2 = ReadFullDate();

	cout << "\nDifference is : " << clsDate::GetDifferenceInDays(Date1, Date2) << " Day(s).";
	cout << "\nDifference (Including End Day) is : " << clsDate::GetDifferenceInDays(Date1, Date2, true) << " Day(s).\n";

	system("pause>0");
	return 0;
}