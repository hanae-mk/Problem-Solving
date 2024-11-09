
#include <iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

struct stDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
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

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "Enter Start Date :\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date :";
	Period.EndDate = ReadFullDate();

	return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day > Date2.Day : false)) : false);
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}

enDateCompare CompareDate(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1AfterDate2(Date1, Date2))
		return enDateCompare::After;

	return enDateCompare::Equal;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
	if (CompareDate(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
		CompareDate(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
		return false;
	else
		return true;

}

short PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsDateInPeriod(stDate DateToCheck, stPeriod Period)
{
	return !(CompareDate(DateToCheck, Period.StartDate) == enDateCompare::Before || //true
		CompareDate(DateToCheck, Period.EndDate) == enDateCompare::After);//false

}

int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);//10
	int Period2Length = PeriodLengthInDays(Period2, true);//12414
	int OverlapDays = 0;

	if (!IsOverlapPeriods(Period1, Period2))
	{
		return 0;
	}
	
	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateInPeriod(Period1.StartDate, Period2))
				OverlapDays++;

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateInPeriod(Period2.StartDate, Period1))
				OverlapDays++;

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}
		
	return OverlapDays; 
}

int main()
{
	cout << "Enter Period 1:\n";
	stPeriod Period1 = ReadPeriod();

	cout << "Enter Period 2:\n";
	stPeriod Period2 = ReadPeriod();

	cout << "\nOverlap days count is : " << CountOverlapDays(Period1, Period2);

	system("pause>0");
	return 0;

}

