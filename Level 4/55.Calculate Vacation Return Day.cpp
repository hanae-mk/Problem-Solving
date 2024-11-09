


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

	cout << "Please enter a Month?";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	short Year = 0;

	cout << "Please enter a Year?";
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];

}

bool IsWeekEnd(stDate Date)
{
	short DayOrder = DayOfWeekOrder(Date);

	return (DayOrder == 5 || DayOrder == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
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

stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1) //I Used Function 
	{
		if (Date.Month == 1) //I Used Function 
		{
			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth((Date.Month), Date.Year);

		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

stDate CalculateVacationReturnDay(stDate DateFrom, short VacationDays)
{
	short WeekEndCounter = 0;

	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{
		if (IsWeekEnd(DateFrom))
			WeekEndCounter++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	
	return DateFrom;
}

short ReadVacationDays()
{
	short VacationDays = 0;

	cout << "\nPlease enter vacation days?";
	cin >> VacationDays;

	return VacationDays;
}

int main()
{
	cout << "\nVacation Starts: ";
	stDate DateFrom = ReadFullDate();

	short VacationDays = ReadVacationDays();

	stDate ReturnDate = CalculateVacationReturnDay(DateFrom, VacationDays);

	cout << "\n\nReturn Date : " << DayShortName(DayOfWeekOrder(ReturnDate)) << " , "
		<< ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;

	system("pause>0");
	return 0;
}



