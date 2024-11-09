

#include <iostream>
using namespace std;

struct stDate
{
	short Days = 0;
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

	cout << "\nPlease enter a month?";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	short Year = 0;

	cout << "\nPlease enter a year?";
	cin >> Year;
	cout << "\n";

	return Year;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Days = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;

}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Days < Date2.Days : false)) : false);
}

int main()
{
	
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	if (IsDate1BeforeDate2(Date1, Date2))
		cout << "\nYes, Date1 is Less than Date2.\n";
	else
		cout << "\nNo, Date1 is NOT Less than Date2.\n";

	system("pause>0");
	return 0;
}