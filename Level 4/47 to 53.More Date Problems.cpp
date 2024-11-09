

#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

struct stDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;

};

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];

}

stDate GetSystemDate()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	stDate Date;

	Date.Day = now->tm_mday;
	Date.Month = now->tm_mon + 1;
	Date.Year = now->tm_year + 1900;

	return Date;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6); //WeekEnds are Friday and Saturday
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);  //!true false   //!false  true
}

short DaysUntilEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsDate1BeforeThanDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

short GetDifferenceInDays(stDate Date, stDate EndOfMonthDate, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeThanDate2(Date, EndOfMonthDate))
	{
		Days++;//1
		Date = IncreaseDateByOneDay(Date);
	}

	return IncludeEndDay ? Days++ : Days;
}

short DaysUntilEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonthDate, true);
	//return NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
}

short DaysUntilEndOfYear(stDate Date)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYearDate, true);
	
	/*short DaysSum = 0;

	for (short i = Date.Month + 1; i <= 12; i++)
	{
		DaysSum += NumberOfDaysInAMonth(i, Date.Year);
	}

	DaysSum += DaysUntilEndOfMonth(Date);

	return DaysSum;*/
}

int main()
{

	stDate Date = GetSystemDate();

	cout << "\nToday is ";
	cout << DayShortName(DayOfWeekOrder(Date)) << " , "
	     << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	cout << "\nIs it End Of Week?";
	if (IsEndOfWeek(Date))
		cout << "\nYes, It is Saturday it's End Of Week.\n";
	else
		cout << "\nNo, Not End Of Week.\n";

	cout << "\nIs it Weekend?";
	if (IsWeekEnd(Date))
		cout << "\nYes, it is a week end.\n";
	else
		cout << "\nNo, Today is" << DayShortName(DayOfWeekOrder(Date)) << ",NOT a Week end.\n";

	cout << "\nIs it Business Day?";
	if (IsBusinessDay(Date))
		cout << "\nYes, it is a business day.\n";
	else
		cout << "\nNo, it is NOT a business day.\n";

	cout << "\nDays until end of week : " << DaysUntilEndOfWeek(Date) << " Day(s).\n";
	cout << "\nDays until end of month : " << DaysUntilEndOfMonth(Date) << " Day(s).\n";
	cout << "\nDays until end of year : " << DaysUntilEndOfYear(Date) << " Day(s).\n";

	system("pause>0");
	return 0;

}

