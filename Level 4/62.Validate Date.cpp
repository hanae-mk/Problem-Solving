

#include <iostream>
using namespace std;

struct stDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

short ReadDay()
{
	short Day = 0;

	cout << "\nPlease enter a day?";
	cin >> Day;

	return Day;
}

short ReadMonth()
{
	short Month = 0;

	cout << "Please enter a month?";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	short Year = 0;

	cout << "Please enter a year?";
	cin >> Year;

	return Year;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsValidDate(stDate Date)
{
	if (Date.Day < 1 || Date.Day > 31)
			return false;
	
	if (Date.Month < 1 || Date.Month > 12)
		return false;

	if (Date.Month == 2)
	{
		if (IsLeapYear(Date.Year))	
		{
			if (Date.Month > 29)
				return false;
		}
			else
			{
				if (Date.Month > 28)
					return false;
			}
	}

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > DaysInMonth)
		return false;
	
   return true;

}

int main()
{
	stDate Date = ReadFullDate();

	if (IsValidDate(Date))
		cout << "\nYes, Date is a valide date.\n";
	else
		cout << "\nNo, Date is NOT a valide date.\n";

	system("pause>0");
	return 0;
}