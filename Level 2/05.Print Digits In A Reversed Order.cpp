
#include <iostream>
#include <string>

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

void PrintDigits(int Number)
{
	/*string Num = to_string(Number);

	for (int i = Num.length() - 1; i >= 0; i--)
	{
		cout << Num[i] << endl;
	}*/

	int Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		cout << Remainder << endl;
	}

}

int main()
{
	PrintDigits(ReadPositiveNumber("Please enter a positive number ?"));
}
