

#include <iostream>
#include <string>

using namespace std;

short ReadYear()
{
	short Number = 0;

	cout << "\nPlease enter a year to check?";
	cin >> Number;

	return Number;
}

bool IsLeapYear(short Year)
{

	if (Year % 400 == 0)
	{
		return true;
	}
	else if (Year % 100 == 0)
	{
		return false;
	}
	else if (Year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

int main()
{
	short Year = ReadYear();

	if (IsLeapYear(Year))
	{
		cout << "\nYes, Year [" << Year << "] is a Leap Year.\n";
	}
	else
	{
		cout << "\nNo, Year [" << Year << "] is NOT a Leap Year.\n";
	}

	system("pause>0");
	return 0;

}