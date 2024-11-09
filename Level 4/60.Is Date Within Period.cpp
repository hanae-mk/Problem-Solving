
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

enDateCompare CompareDate(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1AfterDate2(Date1, Date2))
		return enDateCompare::After;

	return enDateCompare::Equal;
}

bool IsDateInPeriod(stPeriod Period, stDate DateToCheck)
{
	return !(CompareDate(DateToCheck, Period.StartDate) == enDateCompare::Before ||
		CompareDate(DateToCheck, Period.EndDate) == enDateCompare::After);
	
	/*return (CompareDate(Period.StartDate, DateToCheck) == enDateCompare::Before &&
		CompareDate(Period.EndDate, DateToCheck) == enDateCompare::After);*/ //My Solution
		
}

int main()
{
	cout << "Enter Period :\n";
	stPeriod Period = ReadPeriod();

	cout << "\nEnter Date To Check :\n";
	stDate DateToCheck = ReadFullDate();

	if (IsDateInPeriod(Period, DateToCheck)) //IsDateWithinPeriod
		cout << "\nYes, Date is within period.";
	else
		cout << "\nNo, Date is NOT within period.";

	system("pause>0");
	return 0;

}

