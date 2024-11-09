
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

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;
	
	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];
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

stDate IncreaseDateByXDays(short Days, stDate Date)
{

	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{

	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{

	if (IsLastMonthInYear(Date.Month))
	{
		Date.Month = 1;
		Date.Year++;
	}
	
	else
	{
		Date.Month++;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if ((Date.Day) > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate IncreaseDateByXMonths(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year += Years;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year += Decade * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}

int main()
{
	stDate Date = ReadFullDate();

	cout << "\nDate After : \n";

	/*Date = IncreaseDateByOneDay(Date);
	cout << "\n01-Adding One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXDays(10, Date);
	cout << "\n02-Adding 10 days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03-Adding one week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXWeeks(10, Date);
	cout << "\n04-Adding 10 weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;*/

	Date = IncreaseDateByOneMonth(Date);
	cout << "\n05-Adding one month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	/*Date = IncreaseDateByXMonths(5, Date);
	cout << "\n06-Adding 5 months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneYear(Date);
	cout << "\n07-Adding one year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXYears(10, Date);
	cout << "\n08-Adding 10 years : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXYearsFaster(10, Date);
	cout << "\n09-Adding 10 years (faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneDecade(Date);
	cout << "\n10-Adding one decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXDecades(10, Date);
	cout << "\n11-Adding 10 decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByXDecadesFaster(10, Date);
	cout << "\n12-Adding 10 decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneCentury(Date);
	cout << "\n13-Adding One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneMillennium(Date);
	cout << "\n14-Adding One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;*/

	system("pause>0");
	return 0;

}

