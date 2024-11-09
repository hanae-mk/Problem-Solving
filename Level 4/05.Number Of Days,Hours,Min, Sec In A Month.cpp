

#include <iostream>
using namespace std;

short ReadYear()
{
	short Year = 0;

	cout << "\nPlease enter a year to check?";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month = 0;

	cout << "Please enter a month to check?";
	cin >> Month;

	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;		
	}
		
	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}
		return 30;
}

short NumberOfHoursInAMonth(short Month, short Year)
{
	return NumberOfDaysInAMonth(Month, Year) * 24;
}

int NumberOfMinutesInAMonth(short Month, short Year)
{
	return NumberOfHoursInAMonth(Month, Year) * 60;
}

int NumberOfSecondsInAMonth(short Month, short Year)
{
	return NumberOfMinutesInAMonth(Month, Year) * 60;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber Of Days In Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);
	cout << "\nNumber Of Hours In Month [" << Month << "] is " << NumberOfHoursInAMonth(Month, Year);
	cout << "\nNumber Of Minutes In Month [" << Month << "] is " << NumberOfMinutesInAMonth(Month, Year);
	cout << "\nNumber Of Seconds In Month [" << Month << "] is " << NumberOfSecondsInAMonth(Month, Year);

	system("pause>0");
	return 0;
}