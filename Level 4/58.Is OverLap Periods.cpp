
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

enDateCompare CompareDates(stDate Date1, stDate Date2)
{

	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;

}

bool IsOverLapPeriods(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
		CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
		return false;
	else
		return true;
}

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "Enter Start Date : \n";
	Period.StartDate = ReadFullDate();
	cout << "Enter End Date : \n";
	Period.EndDate = ReadFullDate();

	return Period;
}

int main()
{
	stPeriod Period1, Period2;

	cout << "Enter Period 1 : \n";
	Period1 = ReadPeriod();

	cout << "\nEnter Period 2 : \n";
	Period2 = ReadPeriod();	

	if (IsOverLapPeriods(Period1, Period2))
		cout << "\nYes,Period is Overlap";
	else
		cout << "\nNo, Period is NOT Overlap";

	system("pause>0");
	return 0;

}

