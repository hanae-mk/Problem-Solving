
#include <iostream>
using namespace std;

short ReadYear()
{
	short Year = 0;

	cout << "\nPlease enter a year?";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short arrNumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrNumberOfDays[Month - 1];
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthShortName(short Month)
{
	string MonthName[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

	return MonthName[Month - 1];
}

void PrintMonthCalendar(short Month, short Year)
{

	printf("  ________________%s_________________\n\n", MonthShortName(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short Current = DayOfWeekOrder(1, Month, Year);
	short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

	int i;
	for (i = 0; i < Current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
		
	printf("\n");
	printf("  ____________________________________\n\n");

}

void PrintYearCalendar(short Year)
{
	printf ("  ____________________________________\n\n");
	printf( "            Calendar - %d\n",Year);
	printf( "  ____________________________________\n\n");

	for (short Month = 1; Month <= 12; Month++)
	{
		PrintMonthCalendar(Month, Year);
	}
}

int main()
{

	PrintYearCalendar(ReadYear());

	system("pause>0");
	return 0;

}

