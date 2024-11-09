
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

void ReadArray(int Arr[100], int& ArrayLength)
{
	cout << "Please enter array length ? " << endl ;
	cin >> ArrayLength;

	cout << endl;

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> Arr[i];

	}
	cout << endl;
}

void PrintArray(int Arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl;
}

int TimesRepeated(int Arr[100],int ArrayLength,int NumberToCheck)
{
	int Counter = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (NumberToCheck == Arr[i])
		{
			Counter++;
		}

	}

	return Counter;
}
int main()
{
	int Arr[100], ArrayLength, NumberToCheck;

	ReadArray(Arr, ArrayLength);

	NumberToCheck = ReadPositiveNumber("Please enter number to check ?");

	cout << "\nOriginal Array : ";
	PrintArray(Arr, ArrayLength);
	cout << endl;

	cout << "Number " << NumberToCheck << " is repeated "
	<< TimesRepeated(Arr, ArrayLength, NumberToCheck) << " time(s)." << endl;

	return 0;

}
