
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

/*void*/ int SumOfDigits(int Number)
{
	int Remainder = 0 , Sum = 0;
	
	while (Number > 0) //while not if
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Sum += Remainder;
		
	}
	     
	return Sum;
	//cout << "\nSum of digits = " << Sum << endl;
}

int main()
{
	cout << "\nSum Of Digits = " << SumOfDigits(ReadPositiveNumber("Please enter a positive Number ?"));
	 
}