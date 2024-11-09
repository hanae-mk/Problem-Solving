

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

	cout << "\nPlease enter day?";
	cin >> Day;

	return Day;
}

short ReadMonth()
{
	short Month = 0;

	cout << "\nPlease enter month?";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	short Year = 0;

	cout << "\nPlease enter year?";
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

short ReadDaysToAdd()
{
	short Days = 0;

	cout << "\nHow many days to add?";
	cin >> Days;

	return Days;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDaysFrom1stDayInYear(short Day, short Month, short Year)
{
	short NumberOfDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		NumberOfDays += NumberOfDaysInAMonth(i, Year);
	}

	NumberOfDays += Day;

	return NumberOfDays;
}

stDate GetDateAfterAddingDays(short Days, stDate Date)
{	
	//389
	short RemainingDays = Days + NumberOfDaysFrom1stDayInYear(Date.Day,Date.Month,Date.Year);// 30 + 359
	short MonthDays = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
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
	stDate Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = GetDateAfterAddingDays(Days, Date);

	cout << "\nDate after adding [" << Days << "] days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


}