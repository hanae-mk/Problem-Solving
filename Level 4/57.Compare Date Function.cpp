
#include <iostream>
#include "clsDate.h"
#include "clsInputValidate.h"

using namespace std;

clsDate ReadFullDate()
{
	clsDate Date;
	bool IsValidDate = false;

	do
	{
		if (IsValidDate)
		{
			cout << "\nInvalid Date, Please Enter Available Date.\n";			
		}
				
		Date.Day = clsInputValidate<short>::ReadNumber("\nPlease Enter a Day?");

		Date.Month = clsInputValidate<short>::ReadNumber("Please Enter a Month?");
		
		Date.Year = clsInputValidate<short>::ReadNumber("Please Enter a Year?");
		

	} while (IsValidDate = !clsDate::IsValidDate(Date));


    return Date;
}

int main()
{
	clsDate Date1, Date2;

	cout << "\nEnter Date 1 : \n";
	Date1 = ReadFullDate();

	cout << "\nEnter Date 2 : \n";
	Date2 = ReadFullDate();

	cout << "\nCompare Results = " << clsDate::CompareDates(Date1, Date2) << endl;

	system("pause>0");
	return 0;
}