
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
	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];
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

stDate DecreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate DecreaseDateByXMonths(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYears(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(short Decades, stDate Date)
{
	for (short i = 1; i <= Decades; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year -= Decade * 10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}

int main()
{
	stDate Date = ReadFullDate();

	cout << "\nDate After : \n";

	Date = DecreaseDateByOneDay(Date);
	cout << "\n01-Subtracting One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDays(10, Date);
	cout << "\n02-Subtracting 10 days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneWeek(Date);
	cout << "\n03-Subtracting one week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXWeeks(10, Date);
	cout << "\n04-Subtracting 10 weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneMonth(Date);
	cout << "\n05-Subtracting one month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXMonths(5, Date);
	cout << "\n06-Subtracting 5 months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneYear(Date);
	cout << "\n07-Subtracting one year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYears(10, Date);
	cout << "\n08-Subtracting 10 years : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYearsFaster(10, Date);
	cout << "\n09-Subtracting 10 years (faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneDecade(Date);
	cout << "\n10-Subtracting one decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecades(10, Date);
	cout << "\n11-Subtracting 10 decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecadesFaster(10, Date);
	cout << "\n12-Subtracting 10 decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneCentury(Date);
	cout << "\n13-Subtracting One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneMillennium(Date);
	cout << "\n14-Subtracting One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}