
#include <iostream>
using namespace std;

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
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

	cout << "\nPlease enter a month?";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	short Year = 0;

	cout << "\nPlease enter a year?";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

short NumberOfDaysFrom1stYear(short Year, short Month, short Day)
{
	short DayNumber = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		DayNumber += NumberOfDaysInAMonth(i, Year);
	}

	DayNumber += Day;

	return DayNumber;
}

stDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
{
	stDate Date;
	short RemainingDays = DayOrderInYear; //Ayam li b9aw
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DaysOrderInYear = NumberOfDaysFrom1stYear(Year, Month, Day);

	cout << "\nNumber of Days from the begining of the year is "
	     << DaysOrderInYear << endl;

	stDate Date;
	Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);

	cout << "\nDate for [" << DaysOrderInYear << "] is :";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}