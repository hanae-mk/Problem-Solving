

#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int CountDigitFrequency(short Digit, int Number)
{
	int Counter = 0, Remainder = 0;


	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		if (Digit == Remainder)
		{
			Counter++;
		}
	}

	return Counter;

}

void PrintAllDigitsFrequency(int Number)
{
	for (int i = 0; i < 10; i++)
	{
		short Digit = 0;
		Digit = CountDigitFrequency(i,Number);

		if (Digit > 0)
		{
			cout << "\nDigit " << i << " frequency is " <<
			Digit << " time(s)\n\n";
		}
	}
}

int main()
{
	
	int Number = ReadPositiveNumber("Please enter a positive number ?");
	PrintAllDigitsFrequency(Number);

	return 0;
}