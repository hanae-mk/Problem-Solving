
#include <iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 }; //I wrote enDate Only

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)):false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false ): false;
}

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

		return enDateCompare::After;
	
	/*if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	else if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	else
		return enDateCompare::After;*/
		
}

int main()
{
	cout << "\nEnter Date 1:\n";
	stDate Date1 = ReadFullDate();

	cout << "\nEnter Date 2:\n";
	stDate Date2 = ReadFullDate();
	
	cout << "\nCompare Results = " << CompareDates(Date1, Date2) << endl;

	system("pause>0");
	return 0;
}

